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
    inline void writestr(string x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); }
    inline void writestrsp(string x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(' '); }
    inline void writestrln(string x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=100005;
const int mod=51061;

int n,q;
bool test;

struct Splay {
    int s[2],p,v,sz;
    int add,mul,rev;
    int sum;
    void init() {
        p=0,v=1,sz=1,add=rev=0,mul=1,sum=v;
    }
} tr[N];

void pushup(int u) {
    tr[u].sz=tr[tr[u].s[0]].sz+tr[tr[u].s[1]].sz+1;
    tr[u].sum=(tr[tr[u].s[0]].sum+tr[tr[u].s[1]].sum+tr[u].v)%mod;
}

void pushrev(int u) {
    swap(tr[u].s[0],tr[u].s[1]);
    tr[u].rev^=1;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[tr[u].s[0]],&right=tr[tr[u].s[1]];
    if (root.rev) pushrev(tr[u].s[0]),pushrev(tr[u].s[1]),tr[u].rev^=1;
    if (root.mul!=1) {
        left.mul=left.mul*root.mul%mod;
        right.mul=right.mul*root.mul%mod;
        left.sum=left.sum*root.mul%mod;
        right.sum=right.sum*root.mul%mod;
        left.add=left.add*root.mul%mod;
        right.add=right.add*root.mul%mod;
        left.v=left.v*root.mul%mod;
        right.v=right.v*root.mul%mod;
        root.mul=1;
    }
    if (root.add) {
        left.add=(left.add+root.add)%mod;
        right.add=(right.add+root.add)%mod;
        left.sum=(left.sum+left.sz*root.add)%mod;
        right.sum=(right.sum+right.sz*root.add)%mod;
        left.v=(left.v+root.add)%mod;
        right.v=(right.v+root.add)%mod;
        root.add=0;
    }
}

bool isroot(int x) {
    return x!=tr[tr[x].p].s[0] && x!=tr[tr[x].p].s[1];
}

void rotate(int x) {
    int y=tr[x].p;
    int z=tr[y].p;
    int k=tr[y].s[1]==x;
    if (!isroot(y)) tr[z].s[tr[z].s[1]==y]=x;
    tr[x].p=z;
    tr[y].s[k]=tr[x].s[k^1],tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y,tr[y].p=x;
    pushup(y);
    pushup(x);
}

void splay(int x) {
    stack<int> stk;
    int y=x;
    stk.emplace(x);
    while (y) stk.emplace(y=tr[y].p);
    while (!stk.empty()) pushdown(stk.top()),stk.pop();
    while (!isroot(x)) {
        int y=tr[x].p;
        int z=tr[y].p;
        if (!isroot(y)) {
            if ((tr[z].s[1]==y)^(tr[y].s[1]==x)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
}

void access(int x) {
    int y=0,z=x;
    while (x) splay(x),tr[x].s[1]=y,pushup(x),y=x,x=tr[x].p;
    splay(z);
}

void makeroot(int x) {
    access(x);
    pushrev(x);
}

int findroot(int x) {
    access(x);
    while (tr[x].s[0]) x=tr[x].s[0];
    splay(x);
    return x;
}

void split(int x,int y) {
    TIMESTAMP
    makeroot(x),access(y);
}

void link(int x,int y) {
    makeroot(x);
    if (findroot(y)!=x) tr[x].p=y;
}

void cut(int x,int y) {
    makeroot(x);
    if (findroot(y)==x && tr[x].s[1]==y && !tr[y].s[0]) tr[x].s[1]=tr[y].p=0,pushup(x);
}

i32 main() {
    FRR("P1501_2.in");
    TIMESTAMP
    read(n),read(q);
    _rep(i,1,n) tr[i].init();
    _rep(i,1,n-1) {
        int a,b;
        read(a),read(b);
        link(a,b);
    }
    test=true;
    TIMESTAMP
    while (q--) {
        cout<<q<<endl;
        char op[5];
        readstr(op);
        if (*op=='+') {
            int u,v,c;
            read(u),read(v),read(c);
            split(u,v);
            tr[v].add=(tr[v].add+c)%mod;
            tr[v].sum=(tr[v].sum+tr[v].sz*c)%mod;
            tr[v].v=(tr[v].v+c)%mod;
        } else if (*op=='-') {
            int u1,v1,u2,v2;
            read(u1),read(v1),read(u2),read(v2);
            cut(u1,v1),link(u2,v2);
        } else if (*op=='*') {
            int u,v,c;
            read(u),read(v),read(c);
            TIMESTAMP
            split(u,v);
            cout<<"done"<<endl;
            TIMESTAMP
            tr[v].mul=tr[v].mul*c%mod;
            tr[v].add=tr[v].add*c%mod;
            tr[v].sum=tr[v].sum*c%mod;
            tr[v].v=tr[v].v*c%mod;
        } else {
            int u,v;
            read(u),read(v);
            split(u,v);
            writeln(tr[v].sum%mod);
        }
        exit(0);
    }
    return 0;
}