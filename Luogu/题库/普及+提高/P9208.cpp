#include <bits/stdc++.h>
using namespace std;

#define int long long

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

const int N=300005;
const int M=600005;

int n,mod;
int e[M],ne[M],h[N],tot;
int c[N],v[N];
int cnt[N],summ;
int sufc[N],sufv[N];

void add(int a,int b) {
	e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

int exgcd(int a,int b,int& x,int& y) {
	if (!b) {
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

int inverse(int a) {
	int x,y;
	exgcd(a,mod,x,y);
	x=(x%mod+mod)%mod;
	return x;
}

void dfs(int u,int fa) {
	sufc[u]=sufv[u]=1;
	_graph(i,u) {
		if (e[i]==fa) continue;
		dfs(e[i],u);
		cnt[u]+=cnt[e[i]];
		sufc[u]=sufc[u]*sufc[e[i]]%mod;
		sufv[u]=sufv[u]*sufv[e[i]]%mod;
	}
	sufc[u]=sufc[u]*c[u]%mod;
	sufv[u]=sufv[u]*v[u]%mod;
}

i32 main() {
	memset(h,-1,sizeof(h));
	read(n),read(mod);
	_rep(i,1,n-1) {
		int a,b;
		read(a),read(b);
		add(a,b),add(b,a);
	}
	_rep(i,1,n) read(c[i]);
	_rep(i,1,n) {
		read(v[i]);
		while (v[i]%mod==0) cnt[i]++,v[i]/=mod;
		summ+=cnt[i];
	}
	dfs(1,0);
	int ans=0;
	_rep(i,1,n) {
		if (summ-cnt[i]>0) continue;
		int C=sufc[i],V=sufv[1]*inverse(sufv[i])%mod;
		ans=(ans+C*V%mod)%mod;
	}
	write(ans);
	return 0;
}