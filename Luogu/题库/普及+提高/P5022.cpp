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

const int N=5005;
const int M=10005;

int n,m;
int e[M],ne[M],h[N],tot;
deque<int> q;
bool vis[N];
int ans[N],vec[N];

inline void add(int a,int b) {
	e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

inline bool dfs(int u,int fa) {
	vis[u]=true;
	q.emplace_back(u);
	_graph(i,u) {
		if (e[i]==fa) continue;
		if (vis[e[i]]) {
			while (q.front()!=e[i]) q.pop_front();
			return true;
		} else if (dfs(e[i],u)) return true;
	}
	q.pop_back();
	return false;
}

inline void dfs2(int u,int fa,int* vec,int& idx) {
	vec[++idx]=u;
	vector<int> des;
	_graph(i,u) {
		if (e[i]==fa) continue;
		if (!q.empty() && ((e[i]==q.front() && u==q.back()) || (e[i]==q.back() && u==q.front()))) continue;
		des.emplace_back(e[i]);
	}
	sort(des.begin(),des.end());
	_iter(it,des) dfs2(*it,u,vec,idx);
}

inline bool comp(const int* a,const int* b) {
	_rep(i,1,n) {
		if (a[i]>b[i]) return false;
		else if (a[i]<b[i]) return true;
	}
	return false;
}

int main() {
	memset(h,-1,sizeof(h));
	read(n),read(m);
	while (m--) {
		int a,b;
		read(a),read(b);
		add(a,b),add(b,a);
	}
	dfs(1,0);
	int idx;
	if (q.empty()) dfs2(1,0,ans,idx=0);
	else {
		_rep(t,1,q.size()) {
			if (t==1) dfs2(1,0,ans,idx=0);
			else {
				dfs2(1,0,vec,idx=0);
				if (comp(vec,ans)) swap(ans,vec);
			}
			q.emplace_back(q.front()),q.pop_front();
		}
	}
	_rep(i,1,n) writesp(ans[i]);
	return 0;
}
