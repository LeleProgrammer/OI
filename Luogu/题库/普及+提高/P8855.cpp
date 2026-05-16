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
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=30005;
const int M=60005;
const int K=25;

int n,m;
int e[M],ne[M],h[N],tot;
int layer[N];
int f[N][K];

void add(int a,int b) {
	e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa,int dep) {
	layer[u]=dep;
	_graph(i,u) {
		if (e[i]==fa) continue;
		f[e[i]][0]=u;
		_rep(j,1,K-1) f[e[i]][j]=f[f[e[i]][j-1]][j-1];
		dfs(e[i],u,dep+1);
	}
}

inline int lca(int a,int b) {
	if (a==b) return a;
	if (layer[a]<layer[b]) swap(a,b);
	_rrep(i,K-1,0) if (layer[f[a][i]]>=layer[b]) a=f[a][i];
	if (a==b) return a;
	_rrep(i,K-1,0) if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
	return f[a][0];
}

int main() {
	memset(h,-1,sizeof(h));
	scanf("%d",&n);
	_rep(i,1,n-1) {
		int a,b;
		scanf("%d %d",&a,&b);
		add(a,b); add(b,a);
	}
	dfs(1,0,1);
	scanf("%d",&m);
	LL ans=0;
	int cur=1;
	while (m--) {
		int k;
		scanf("%d",&k);
		int g=lca(cur,k);
		ans+=layer[cur]-layer[g];
		ans+=layer[k]-layer[g];
		cur=k;
	}
	printf("%lld",ans);
	return 0;
}