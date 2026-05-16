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

const int N=30005;
const int M=60005;
const int K=1500005;
const int P=33;

int n,idx,ans;
int e[M],ne[M],w[M],h[N],tot;
int arr[N];
int tr[K][2];
int st[K],fa[N];
int mx,x,y;
int f[N];
stack<int> stk;

void add(int a,int b,int c) {
	e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void insert(int k,int pos=0) {
	// cout<<"inserted: "<<k<<endl;
	int u=0;
	_rrep(i,P,0) {
		int c=((k>>i)&1);
		if (!tr[u][c]) tr[u][c]=++idx;
		u=tr[u][c];
	}
	st[u]=pos;
}

pii query(int k) {
	int ans=0,u=0;
	_rrep(i,P,0) {
		int c=((k>>i)&1);
		// cout<<"test: "<<i<<" "<<c<<endl;
		if (tr[u][c^1]) u=tr[u][c^1],ans=((ans<<1)|1);
		else u=tr[u][c],ans<<=1;
	}
	return {ans,st[u]};
}

void restore(int u) {
	if (tr[u][0]) restore(tr[u][0]),tr[u][0]=0;
	if (tr[u][1]) restore(tr[u][1]),tr[u][1]=0;
}

void dfs(int u,int p) {
	fa[u]=p;
	insert(arr[u],u);
	auto k=query(arr[u]);
	// cout<<"get: "<<arr[u]<<" "<<k.first<<" "<<k.second<<endl;
	if (k.first>=mx) mx=k.first,x=k.second,y=u;
	_graph(i,u) {
		if (e[i]==p) continue;
		arr[e[i]]=(arr[u]^w[i]);
		dfs(e[i],u);
	}
}

void dfs3(int u,int& cur) {
	insert(arr[u]);
	cur=max(cur,query(arr[u]).first);
	// cout<<"searched: "<<u<<" "<<arr[u]<<" "<<query(arr[u]).first<<endl;
	_graph(i,u) {
		if (e[i]==fa[u]) continue;
		dfs3(e[i],cur);
	}
}

void dfs2(int u,int& cur) {
	stk.pop();
	f[u]=max(f[u],cur);
	// cout<<"record: "<<u<<" "<<cur<<endl;
	if (stk.empty()) return;
	insert(arr[u]);
	// cout<<"searched: "<<u<<" "<<arr[u]<<" "<<query(arr[u]).first<<endl;
	cur=max(cur,query(arr[u]).first);
	_graph(i,u) {
		if (e[i]==fa[u]) continue;
		if (e[i]!=stk.top()) dfs3(e[i],cur);
	}
	dfs2(stk.top(),cur);
}

i32 main() {
	memset(h,-1,sizeof(h));
	read(n);
	_rep(i,1,n-1) {
		int a,b,c;
		read(a),read(b),read(c);
		add(a,b,c),add(b,a,c);
	}
	dfs(1,0);
	// _rep(i,1,n) printf("arr[%d] = %d\n",i,arr[i]);
	// cout<<"test: "<<x<<" "<<y<<": "<<mx<<endl;
	int u=x;
	while (u) stk.emplace(u),u=fa[u];
	restore(0),idx=0;
	int tmp=0;
	dfs2(1,tmp);
	while (!stk.empty()) stk.pop();
	u=y;
	while (u) stk.emplace(u),u=fa[u];
	// cout<<"==================================="<<endl;
	restore(0),idx=0;
	tmp=0;
	dfs2(1,tmp);
	// _rep(i,1,n) printf("f[%d] = %d\n",i,f[i]);
	unordered_set<int> X,Y;
	u=x;
	while (u) X.emplace(u),u=fa[u];
	u=y;
	while (u) Y.emplace(u),u=fa[u];
	u=x;
	while (u) {
		_graph(i,u) {
			if (e[i]==fa[u] || X.count(e[i]) || Y.count(e[i])) continue;
			restore(0),idx=0;
			int res=0;
			dfs3(e[i],res);
			// cout<<"test: "<<u<<" -> "<<e[i]<<" "<<res<<endl;
			ans=max(ans,res+mx);
		}
		u=fa[u];
	}
	// cout<<"now: "<<ans<<endl;
	u=y;
	while (u) {
		_graph(i,u) {
			if (e[i]==fa[u] || X.count(e[i]) || Y.count(e[i])) continue;
			restore(0),idx=0;
			int res=0;
			dfs3(e[i],res);
			// cout<<"test: "<<u<<" -> "<<e[i]<<" "<<res<<endl;
			ans=max(ans,res+mx);
		}
		u=fa[u];
	}
	// cout<<"now: "<<ans<<endl;
	u=y;
	while (u) {
		if (X.count(u) && u!=1) ans=max(ans,mx+f[u]);
		u=fa[u];
	}
	// cout<<"nowwwww: "<<ans<<endl;
	u=x;
	restore(0),idx=0;
	int cur=0;
	int las=0;
	while (u) {
		insert(arr[u]);
		cur=max(cur,query(arr[u]).first);
		_graph(i,u) {
			if (e[i]==fa[u] || e[i]==las) continue;
			dfs3(e[i],cur);
		}
		if (u!=1) ans=max(ans,cur+f[u]);
		// cout<<"test: "<<u<<" "<<cur<<" "<<f[u]<<endl;
		las=u;
		u=fa[u];
	}
	// cout<<"now: "<<ans<<endl;
	u=y;
	restore(0),idx=0;
	cur=0;
	las=0;
	while (u) {
		insert(arr[u]);
		cur=max(cur,query(arr[u]).first);
		_graph(i,u) {
			if (e[i]==fa[u] || e[i]==las) continue;
			dfs3(e[i],cur);
		}
		if (u!=1) ans=max(ans,cur+f[u]);
		las=u;
		u=fa[u];
	}
	write(ans);
	return 0;
}