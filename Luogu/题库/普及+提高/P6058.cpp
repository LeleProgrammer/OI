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

const int N=200005;
const int M=400005;
const int K=20;
const int inf=1e18;

int n,m,cnt;
int e[M],ne[M],w[M],h[N],tot;
int pre[N],dep[N];
int f[N][K];
int g[N];
int lf[N];

void add(int a,int b,int c) {
	e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa,int d) {
	dep[u]=d;
	bool flag=false;
	vector<int> vec;
	_graph(i,u) vec.emplace_back(i);
	sort(vec.begin(),vec.end(),[&](const int& a,const int& b) {
		return e[a]<e[b];
	});
	_iter(it,vec) {
		int i=*it;
		if (e[i]==fa) continue;
		flag=true;
		pre[e[i]]=pre[u]+w[i];
		f[e[i]][0]=u;
		_rep(j,1,K-1) f[e[i]][j]=f[f[e[i]][j-1]][j-1];
		dfs(e[i],u,d+1);
	}
	if (!flag) lf[++cnt]=u;
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
	int g=lca(a,b);
	return pre[a]+pre[b]-pre[g]*2;
}

bool check(int mid) {
	int sum=pre[lf[1]],cur=1;
	_rep(i,2,cnt) {
		if (sum+g[i-1]+pre[lf[i]]>mid) cur++,sum=pre[lf[i]];
		else sum+=g[i-1];
	}
	return cur<=m;
}

i32 main() {
	memset(h,-1,sizeof(h));
	read(n),read(m);
	_rep(i,1,n-1) {
		int a,b,c;
		read(a),read(b),read(c);
		add(a,b,c),add(b,a,c);
	}
	dfs(1,0,1);
	_rep(i,1,cnt-1) g[i]=dis(lf[i],lf[i+1]);
	int l=0,r=inf;
	_rep(i,1,cnt) l=max(l,pre[lf[i]]*2);
	while (l<r) {
		int mid=l+r>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	write(r);
	return 0;
}