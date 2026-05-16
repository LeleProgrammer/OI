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

const int N=4000005;
const int M=200005;

int n,root,idx=1,ans;
int arr[N];
int e[M],ne[M],h[N],tot;
int tr[N][2];
int cnt[N];

void add(int a,int b) {
	e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void insert(int k) {
	int u=1;
	_rrep(i,31,0) {
		int c=((k>>i)&1);
		if (!tr[u][c]) tr[u][c]=++idx;
		u=tr[u][c];
		cnt[u]++;
	}
}

void del(int k) {
	int u=1;
	_rrep(i,31,0) {
		int c=((k>>i)&1);
		u=tr[u][c];
		cnt[u]--;
	}
}

int query(int k) {
	int u=1,ans=0;
	_rrep(i,31,0) {
		int c=((k>>i)&1);
		if (tr[u][c^1] && cnt[tr[u][c^1]]) u=tr[u][c^1],ans=(ans<<1)+1;
		else u=tr[u][c],ans<<=1;
	}
	return ans;
}

void dfs(int u,int fa) {
	_graph(i,u) del(arr[e[i]]);
	ans=max(ans,query(arr[u]));
	_graph(i,u) insert(arr[e[i]]);
	_graph(i,u) if (e[i]!=fa) dfs(e[i],u);
}

int main() {
	memset(h,-1,sizeof(h));
	read(n);
	_rep(i,1,n) read(arr[i]),insert(arr[i]);
	_rep(i,1,n) {
		int k;
		read(k);
		k++;
		if (!k) root=i;
		else add(k,i),add(i,k);
	}
	dfs(root,0);
	write(ans);
	return 0;
}