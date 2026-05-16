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

int n,arr[N],sum;
int e[M],ne[M],w[M],h[N],tot;
vector<piii> ans;
int indeg[N];

void add(int a,int b) {
	e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void add(int a,int b,int c) {
	e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa) {
	_graph(i,u) {
		if (e[i]==fa) continue;
		dfs(e[i],u);
		arr[u]+=arr[e[i]];
		if (!arr[e[i]]) continue;
		else if (arr[e[i]]>0) ans.emplace_back(piii{arr[e[i]],{e[i],u}});
		else ans.emplace_back(piii{-arr[e[i]],{u,e[i]}});
	}
}

void topu() {
	queue<int> q;
	_rep(i,1,n) if (!indeg[i]) q.emplace(i);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		_graph(i,u) {
			writesp(u),writesp(e[i]),writeln(w[i]);
			if (!--indeg[e[i]]) q.emplace(e[i]);
		}
	}
}

i32 main() {
	memset(h,-1,sizeof(h));
	read(n);
	_rep(i,1,n) read(arr[i]),sum+=arr[i];
	_rep(i,1,n) arr[i]=arr[i]-sum/n;
	_rep(i,1,n-1) {
		int a,b;
		read(a),read(b);
		add(a,b),add(b,a);
	}
	dfs(1,0);
	writeln(ans.size());
	memset(h,-1,sizeof(h)),tot=0;
	_iter(it,ans) add(it->second.first,it->second.second,it->first),indeg[it->second.second]++;
	topu();
	return 0;
}