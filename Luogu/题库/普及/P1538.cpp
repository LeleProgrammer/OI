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

const int N=265;

int k,n;
char s[N];
vector<char> ans[N];

void solve_horizon(int i) {
	ans[i].emplace_back(' ');
	_rep(j,1,k) ans[i].emplace_back('-');
	ans[i].emplace_back(' ');
	ans[i].emplace_back(' ');
}

void solve_empty(int i) {
	ans[i].emplace_back(' ');
	_rep(j,1,k) ans[i].emplace_back(' ');
	ans[i].emplace_back(' ');
	ans[i].emplace_back(' ');
}

void solve_left(int i) {
	ans[i].emplace_back('|');
	_rep(j,1,k) ans[i].emplace_back(' ');
	ans[i].emplace_back(' ');
	ans[i].emplace_back(' ');
}

void solve_right(int i) {
	ans[i].emplace_back(' ');
	_rep(j,1,k) ans[i].emplace_back(' ');
	ans[i].emplace_back('|');
	ans[i].emplace_back(' ');
}

void solve_both(int i) {
	ans[i].emplace_back('|');
	_rep(j,1,k) ans[i].emplace_back(' ');
	ans[i].emplace_back('|');
	ans[i].emplace_back(' ');
}

int main() {
	read(k);
	readstr(s+1),n=strlen(s+1);
	_rep(i,1,n) {
		if (s[i]=='1') {
			solve_empty(1);
			_rep(i,2,k+1) solve_right(i);
			solve_empty(k+2);
			_rep(i,k+3,2*k+2) solve_right(i);
			solve_empty(2*k+3);
		} else if (s[i]=='2') {
			solve_horizon(1);
			_rep(i,2,k+1) solve_right(i);
			solve_horizon(k+2);
			_rep(i,k+3,2*k+2) solve_left(i);
			solve_horizon(2*k+3);
		} else if (s[i]=='3') {
			solve_horizon(1);
			_rep(i,2,k+1) solve_right(i);
			solve_horizon(k+2);
			_rep(i,k+3,2*k+2) solve_right(i);
			solve_horizon(2*k+3);
		} else if (s[i]=='4') {
			solve_empty(1);
			_rep(i,2,k+1) solve_both(i);
			solve_horizon(k+2);
			_rep(i,k+3,2*k+2) solve_right(i);
			solve_empty(2*k+3);
		} else if (s[i]=='5') {
			solve_horizon(1);
			_rep(i,2,k+1) solve_left(i);
			solve_horizon(k+2);
			_rep(i,k+3,2*k+2) solve_right(i);
			solve_horizon(2*k+3);
		} else if (s[i]=='6') {
			solve_horizon(1);
			_rep(i,2,k+1) solve_left(i);
			solve_horizon(k+2);
			_rep(i,k+3,2*k+2) solve_both(i);
			solve_horizon(2*k+3);
		} else if (s[i]=='7') {
			solve_horizon(1);
			_rep(i,2,k+1) solve_right(i);
			solve_empty(k+2);
			_rep(i,k+3,2*k+2) solve_right(i);
			solve_empty(2*k+3);
		} else if (s[i]=='8') {
			solve_horizon(1);
			_rep(i,2,k+1) solve_both(i);
			solve_horizon(k+2);
			_rep(i,k+3,2*k+2) solve_both(i);
			solve_horizon(2*k+3);
		} else if (s[i]=='9') {
			solve_horizon(1);
			_rep(i,2,k+1) solve_both(i);
			solve_horizon(k+2);
			_rep(i,k+3,2*k+2) solve_right(i);
			solve_horizon(2*k+3);
		} else if (s[i]=='0') {
			solve_horizon(1);
			_rep(i,2,k+1) solve_both(i);
			solve_empty(k+2);
			_rep(i,k+3,2*k+2) solve_both(i);
			solve_horizon(2*k+3);
		}
	}
	_rep(i,1,2*k+3) {
		_iter(it,ans[i]) putchar(*it);
		putchar(10);
	}
	return 0;
}