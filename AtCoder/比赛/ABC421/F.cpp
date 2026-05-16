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

const int N=500005;
const int inf=1e9;

int q;
int root,idx;
int pos[N];

struct Splay {
    int s[2],p,v,sz;
    int sum;
    void init(int p,int v) {
        this->p=p,this->v=this->sum=v,sz=1;
    }
} tr[N];

void pushup(int u) {
    tr[u].sum=tr[tr[u].s[0]].sum+tr[tr[u].s[1]].sum+tr[u].v;
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
            if ((tr[z].s[1]==y)^(tr[y].s[1]==x)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if (!k) root=x;
}

void init() {
    root=++idx;
    tr[root].init(0,-1);
    int u=++idx;
    tr[root].s[1]=u;
    tr[u].init(root,0);
    pos[0]=u;
    int v=++idx;
    tr[u].s[1]=v;
    tr[v].init(u,inf);
    pushup(u),pushup(root);
}

i32 main() {
    init();
    read(q);
    _rep(i,1,q) {
        int op,x;
        read(op),read(x);
        if (op==1) {
            splay(pos[x],0);
            int r=tr[pos[x]].s[1];
            while (tr[r].s[0]) r=tr[r].s[0];
            splay(r,pos[x]);
            int u=++idx;
            tr[u].init(r,i),pos[i]=u;
            pushup(r),pushup(pos[x]);
            splay(u,0);
        } else {
            int y;
            read(y);
            int l=pos[x],r=pos[y];
            splay(l,0),splay(r,l);
            if (tr[l].s[0]==r) {
                swap(l,r);
                splay(l,0),splay(r,l);
            }
            writeln(tr[tr[r].s[0]].sum);
            tr[r].s[0]=0;
            pushup(r),pushup(l);
        }
    }
    return 0;
}