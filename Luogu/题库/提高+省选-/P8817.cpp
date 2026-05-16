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

const int N=2505;
const int M=20005;
const int inf=1e9;

int n,m,k;
i128 ans;
i128 arr[N];
int e[M],ne[M],h[N],tot;
int dis[N][N];
queue<int> q;
vector<int> vec[N];

void add(int a,int b) {
	e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void bfs(int s) {
	_rep(i,1,n) dis[s][i]=inf;
	q.emplace(s),dis[s][s]=0;
	while (!q.empty()) {
		int u=q.front(); q.pop();
		_graph(i,u) if (dis[s][e[i]]>dis[s][u]+1) dis[s][e[i]]=dis[s][u]+1,q.emplace(e[i]);
	}
}

bool cmp(const int& a,const int& b) {
	return arr[a]>arr[b];
}

int main() {
	memset(h,-1,sizeof(h));
	read(n),read(m),read(k),k++;
	_rep(i,2,n) read(arr[i]);
	while (m--) {
		int a,b;
		read(a),read(b);
		add(a,b),add(b,a);
	}
	_rep(i,1,n) bfs(i);
	_rep(i,2,n) _rep(j,2,n) if (i!=j && dis[1][j]<=k && dis[j][i]<=k) vec[i].emplace_back(j);
	_rep(i,2,n) sort(vec[i].begin(),vec[i].end(),cmp);
//	_rep(i,2,n) printf("size(vec[%d]) = %d\n",i,vec[i].size());
	_rep(b,2,n) _rep(c,2,n) {
		if (b==c) continue;
		if (dis[b][c]>k) continue;
		_rep(i,0,min(2,(int)vec[b].size()-1)) _rep(j,0,min(2,(int)vec[c].size()-1)) {
			int a=vec[b][i],d=vec[c][j];
//			cout<<"test: "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
			if (a!=b && a!=c && d!=b && d!=c && a!=d) ans=max(ans,arr[a]+arr[b]+arr[c]+arr[d]);
		}
	}
	write(ans);
	return 0;
}

