#include <bits/stdc++.h>
using namespace std;
namespace IO {
	#if ONLINE_JUDGE
	#define getc() (IS == IT && (IT = (IS = ibuf) + fread(ibuf, 1, IL, stdin), IS == IT) ? EOF : *IS++)
	#else
	#define getc() getchar()
	#endif
	const int IL = 1 << 20, OL = 1 << 20;
	int olen = 0;
	char ibuf[IL], *IS = ibuf, *IT = ibuf, obuf[OL];
	inline int read() {
		register char ch = getc(); register int x = 0, f = 1;
		while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getc(); }
		while(isdigit(ch)) x = x * 10 + ch - 48, ch = getc();
		return x * f;
	}
	inline double readdb() {
		register char ch = getc(); register double x = 0, f = 1;
		while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getc(); }
		while(isdigit(ch)) x = x * 10 + ch - 48, ch = getc();
		if(ch == '.') {
			register double b = 0.1;
			ch = getc();
			while(isdigit(ch)) x += (ch - 48) * b, b *= 0.1, ch = getc();
		}
		return x * f;
	}
	inline int readstr(char *s) {
		register char ch = getc(); register int len = 0;
		while(!isalpha(ch)) ch = getc();
		while(isalpha(ch)) s[++len] = ch, ch = getc();
		return len;
	}
	inline void flush() { fwrite(obuf, 1, olen, stdout); olen = 0; }
	inline void putc(register char ch) { obuf[olen++] = ch; }
	template<class T>
	inline void print(register T x) {
		if(x < 0) obuf[olen++] = '-', x = -x;
		if(x > 9) print(x / 10);
		obuf[olen++] = x % 10 + 48;
	}
} using namespace IO;
const int N = 1e5 + 10 , B = 381 , S = (N / B) + 10;
int n, m, a[N], b[B], len, bel[N], cnt, l[S], r[S];
short pos[N][S];
int fir[S][B], lst[S][B];
short dis[S][B][B];
vector <int> dat[B];
inline void Insert(int i , int x){
	if(find(dat[i].begin() , dat[i].end() , x) != dat[i].end()) return;
	dat[i].insert(lower_bound(dat[i].begin() , dat[i].end() , x) , x);
}
inline void Delete(int i , int x){
	dat[i].erase(lower_bound(dat[i].begin(), dat[i].end(), x));
}
inline void init() {
	len = B - 1;
	for(int i = 1; i <= n; i++)
		bel[i] = (i - 1) / len + 1;
	cnt = bel[n];
	for(int i = 1; i <= cnt; i++) {
		l[i] = (i - 1) * len + 1;
		r[i] = i * len;
	} 
	r[cnt] = n;
	memset(fir, 0x3f, sizeof(fir));
	memset(lst, -0x3f, sizeof(lst)); 
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= cnt; i++) {
		for(int j = l[i]; j <= r[i]; j++)
			b[j - l[i] + 1] = a[j];
		sort(b + 1, b + r[i] - l[i] + 2);
		int len = unique(b + 1, b + r[i] - l[i] + 2) - b - 1;
		for(int j = l[i]; j <= r[i]; j++) {
			int x = lower_bound(b + 1, b + 1 + len, a[j]) - b;
			pos[a[j]][i] = x;
			a[j] = x;
			if(fir[i][a[j]] > 1e9) fir[i][a[j]] = j;
			lst[i][a[j]] = j;
			Insert(i, a[j]);
			for(int k = l[i]; k <= j; k++) {
				int t1 = a[j], t2 = a[k]; 
				if(t1 > t2) swap(t1, t2);
				dis[i][t1][t2] = min(dis[i][t1][t2], short(j - k));
			}
		}
	}
}
inline void update(int x, int y){
	if(x == y) return;
	for(int i = 1;i <= cnt;++i){
		if(!pos[x][i]) continue;
		if(!pos[y][i]){
			pos[y][i] = pos[x][i];
			pos[x][i] = 0;
			continue;
		}
		int v1 = pos[x][i], v2 = pos[y][i];
		pos[x][i] = 0;
		fir[i][v2] = min(fir[i][v1], fir[i][v2]);
		lst[i][v2] = max(lst[i][v1], lst[i][v2]);
		if(v1 < v2){
            int k , po = 0;
			for(k = 0;k < dat[i].size() && dat[i][k] <= v1;++k){
				po = dat[i][k];
				dis[i][po][v2] = min(dis[i][po][v2] , dis[i][po][v1]);
			}
			for(;k < dat[i].size() && dat[i][k] <= v2;++k){
				po = dat[i][k];
				dis[i][po][v2] = min(dis[i][po][v2] , dis[i][v1][po]);
			}
			for(;k < dat[i].size();++k){
				po = dat[i][k];
				dis[i][v2][po] = min(dis[i][v2][po] , dis[i][v1][po]);
			}
		}
		else{
            int k , po = 0;
			for(k = 0;k < dat[i].size() && dat[i][k] <= v2;++k){
				po = dat[i][k];
				dis[i][po][v2] = min(dis[i][po][v2] , dis[i][po][v1]);
			}
			for(;k < dat[i].size() && dat[i][k] <= v1;++k){
				po = dat[i][k];
				dis[i][v2][po] = min(dis[i][v2][po] , dis[i][po][v1]);
			}
			for(;k < dat[i].size();++k){
				po = dat[i][k];
				dis[i][v2][po] = min(dis[i][v2][po] , dis[i][v1][po]);
			}
		}
		Delete(i , v1);
	}
}
inline int getans(int x, int y){
	int ans = 1e9;
	int l1 = -1e9, r1 = 1e9, l2 = -1e9, r2 = 1e9;
	for(int i = 1; i <= cnt; i++) {
		int k1 = pos[x][i], k2 = pos[y][i];
		if(k1 && k2) {
			if(k1 < k2 && dis[i][k1][k2] <= len) ans = min(ans, (int)dis[i][k1][k2]);
			else if(k2 <= k1 && dis[i][k2][k1] <= len) ans = min(ans, (int)dis[i][k2][k1]);
		}
		if(i != cnt) {
			if(lst[i][k2] > 0) l2 = lst[i][k2];
			if(lst[i][k1] > 0) l1 = lst[i][k1];
			if(fir[i + 1][pos[y][i + 1]] < 1e9) r2 = fir[i + 1][pos[y][i + 1]];
			if(fir[i + 1][pos[x][i + 1]] < 1e9) r1 = fir[i + 1][pos[x][i + 1]];
			if(r2 >= l1) ans = min(ans, r2 - l1);
			if(r1 >= l2) ans = min(ans, r1 - l2);
		}
	}
	return ans;
}
int main() {
    freopen("1.in","r",stdin);
    freopen("ac.out","w",stdout);
	n = read();
    m = read();
	for(int i = 1;i <= n;++i){
		a[i] = read();
    }
	init();
	int ans = 0;
	for(int i = 1;i <= m;++i){
		int opt = read() , x = read() ^ ans , y = read() ^ ans;
		if(opt == 1) update(x, y);
		else {
			ans = getans(x, y);
			if(ans >= 1e8){
                putc('I');
				putc('k');
				putc('a');
				putc('r');
				putc('o');
				putc('s');
				putc('\n');
				ans = 0; 
			}
			else{
                print(ans);
                putc('\n');
            }
		}
	}
	flush();
	return 0;
}