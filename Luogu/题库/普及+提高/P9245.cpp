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

const int N=100005;
const int M=200005;
const int K=20;

int n,k;
int e[M],w[M],ne[M],h[N],tot;
int arr[N],dep[N],f[N][K],p[N];

void add(int a,int b,int c) {
	e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa,int d) {
	dep[u]=d;
	_graph(i,u) {
		if (e[i]==fa) continue;
		f[e[i]][0]=u;
		_rep(j,1,K-1) f[e[i]][j]=f[f[e[i]][j-1]][j-1];
		p[e[i]]=p[u]+w[i];
		dfs(e[i],u,d+1);
	}
}

int lca(int a,int b) {
	if (a==b) return a;
	if (dep[a]<dep[b]) swap(a,b);
	_rrep(i,K-1,0) if (dep[f[a][i]]>=dep[b]) a=f[a][i];
	if (a==b) return a;
	_rrep(i,K-1,0) if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
	return f[a][0];
}

int dis(int a,int b) {
	return p[a]+p[b]-2*p[lca(a,b)];
}

i32 main() {
	memset(h,-1,sizeof(h));
	read(n),read(k);
	_rep(i,1,n-1) {
		int a,b,c;
		read(a),read(b),read(c);
		add(a,b,c),add(b,a,c);
	}
	_rep(i,1,k) read(arr[i]);
	dfs(1,0,1);
	int cur=0;
	_rep(i,1,k-1) cur+=dis(arr[i],arr[i+1]);
	_rep(i,1,k) {
		if (i==1) writesp(cur-dis(arr[i],arr[i+1]));
		else if (i==k) writesp(cur-dis(arr[i],arr[i-1]));
		else writesp(cur-dis(arr[i-1],arr[i])-dis(arr[i],arr[i+1])+dis(arr[i-1],arr[i+1]));
	}
	return 0;
}