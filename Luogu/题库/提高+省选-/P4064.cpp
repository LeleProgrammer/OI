#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _riter(i,a) for (auto i=a.rbegin();i!=a.rend();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _dinic(i,u) for (int i=cur[u];~i && k<limit;i=ne[i])
#define rint register int
#define LL long long
#define i32 signed
#define i64 long long
#define i128 __int128
#define u32 unsigned
#define u64 unsigned long long
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<double,double> pdd;

namespace IO {
    template<typename T> inline void read(T& x) {
        int s=1; char c=getchar(); x=0;
        while (!isdigit(c)) { if (c=='-') s=-1; c=getchar(); }
        while (isdigit(c) && c!=EOF) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x[idx++]=c,c=getchar();
        x[idx]='\0';
    }
    template<typename T> inline void write(T x) {
        if (x<0) putchar('-'),x=-x;
        if (x/10) write(x/10);
        putchar('0'+(x%10));
    }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
    inline void writestr(string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=200005;

int T,n,m,k,a;
int arr[N],c[N];

struct node {
	int l,r;
	friend bool operator < (const node& a,const node& b) {
		return a.r<b.r;
	}
} b[N];

bool check(int mid) {
	priority_queue<node> q;
	_rep(i,1,n) c[i]=0;
	int cur=0,j=1,cnt=0;
	_rep(i,1,n) {
		cur+=c[i];
		while (j<=m && b[j].l==i) q.emplace(b[j++]);
		while (!q.empty() && arr[i]+cur<mid) {
			auto g=q.top(); q.pop();
			if (g.r<i) continue;
			cur+=a,c[g.r+1]-=a;
			cnt++;
		}
		if (arr[i]+cur<mid) return false;
	}
	return cnt<=k;
}

int main() {
	read(T);
	while (T--) {
		read(n),read(m),read(k),read(a);
		_rep(i,1,n) read(arr[i]);
		_rep(i,1,m) read(b[i].l),read(b[i].r);
		sort(b+1,b+1+m,[&](const node& a,const node& b) {
			return a.l<b.l;
		});
		int l=1,r=2e9;
		while (l<r) {
			int mid=(l+r>>1)+1;
			if (check(mid)) l=mid;
			else r=mid-1;
		}
		writeln(l);
	}
	return 0;
}