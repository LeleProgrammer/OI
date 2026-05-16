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
        while (isdigit(c)) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x[idx++]=c,c=getchar();
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
    inline void writestr(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=500005;

int n,idx,root;

struct Splay {
    int s[2],p,v,sz;
    void init(int p,int v) {
        this->p=p,this->v=v;
        sz=1;
    }
} tr[N];

void pushup(int u) {
    tr[u].sz=tr[tr[u].s[0]].sz+tr[tr[u].s[1]].sz+1;
}

void rotate(int x) {
    int y=tr[x].p;
    int z=tr[y].p;
    int k=tr[y].s[1]==x;
    tr[z].s[tr[z].s[1]==y]=x,tr[x].p=z;
    tr[y].s[k]=tr[x].s[k^1],tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y,tr[y].p=x;
    pushup(y);
    pushup(x);
}

void splay(int x,int k) {
    while (tr[x].p!=k) {
        int y=tr[x].p;
        int z=tr[y].p;
        if (z!=k) {
            if ((tr[y].s[1]==x)^(tr[z].s[1]==y)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if (!k) root=x;
}

int getk(int k) {
    int x=root;
    while (x) {
        if (k<=tr[tr[x].s[0]].sz) x=tr[x].s[0];
        else if (k==tr[tr[x].s[0]].sz+1) return x;
        else k-=tr[tr[x].s[0]].sz+1,x=tr[x].s[1];
    }
    return -1;
}

void init() {
    root=++idx;
    tr[root].init(0,0);
    tr[++idx].init(root,n+1);
    tr[root].s[1]=idx;
    pushup(root);
}

void dfs(int u) {
    if (tr[u].s[0]) dfs(tr[u].s[0]);
    if (tr[u].v>=1 && tr[u].v<=n) writesp(tr[u].v);
    if (tr[u].s[1]) dfs(tr[u].s[1]);
}

int main() {
    read(n);
    init();
    _rep(i,1,n) {
        int k;
        read(k);
        int l=getk(k),r=getk(k+1);
        splay(l,0),splay(r,l);
        tr[++idx].init(r,i);
        pushup(r),pushup(l);
        splay(idx,0);
    }
    dfs(root);
    return 0;
}