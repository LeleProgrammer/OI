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
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=100005;
const int A=500005;
const int M=22000005;
const int inf=1e9;

int n,m,idx;
int a[N];
int root[A];
vector<int> arr[A];

namespace SEG {
    struct Seg {
        int l,r;
        i64 v;
    } tr[N<<2];
    
    inline void pushup(int u) {
        tr[u].v=tr[u<<1].v+tr[u<<1|1].v;
    }

    inline void build(int u,int l,int r) {
        tr[u]={l,r,a[l]};
        if (l==r) return;
        int mid=l+r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        pushup(u);
    }

    inline void modify(int u,int p,int k) {
        if (tr[u].l==p && tr[u].r==p) tr[u].v=k;
        else {
            int mid=tr[u].l+tr[u].r>>1;
            if (p<=mid) modify(u<<1,p,k);
            else modify(u<<1|1,p,k);
            pushup(u);
        }
    }

    inline i64 query(int u,int l,int r) {
        if (tr[u].l>=l && tr[u].r<=r) return tr[u].v;
        int mid=tr[u].l+tr[u].r>>1;
        i64 ans=0;
        if (l<=mid) ans+=query(u<<1,l,r);
        if (r>mid) ans+=query(u<<1|1,l,r);
        return ans;
    }
}

struct Splay {
    int s[2],p,v,sz;
    inline void reset() {
        s[0]=s[1]=p=v=sz=0;
    }
    inline void init(int p,int v) {
        this->p=p,this->v=v,sz=1;
    }
} tr[M];

inline void pushup(int u) {
    tr[u].sz=tr[tr[u].s[0]].sz+tr[tr[u].s[1]].sz+1;
}

inline void rotate(int x) {
    int y=tr[x].p;
    int z=tr[y].p;
    int k=tr[y].s[1]==x;
    tr[z].s[tr[z].s[1]==y]=x,tr[x].p=z;
    tr[y].s[k]=tr[x].s[k^1],tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y,tr[y].p=x;
    pushup(y);
    pushup(x);
}

inline void splay(int x,int k,int& root) {
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

inline int newNode() {
    int u=++idx;
    tr[u].reset();
    return u;
}

inline int findPrev(int root,int k) {
    int u=root,las=-1;
    while (u) {
        if (k<=tr[u].v) u=tr[u].s[0];
        else {
            if (las==-1 || tr[u].v>tr[las].v) las=u;
            u=tr[u].s[1];
        }
    }
    return las;
}

inline int findNext(int root,int k) {
    int u=root,las=-1;
    while (u) {
        if (k<tr[u].v) {
            if (las==-1 || tr[u].v<tr[las].v) las=u;
            u=tr[u].s[0];
        } else u=tr[u].s[1];
    }
    return las;
}

inline void rmv(int u,int x) {
    if (!u) return;
    queue<int> q;
    q.emplace(u);
    vector<int> vec;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        if (a[tr[u].v]%x==0) a[tr[u].v]/=x,SEG::modify(1,tr[u].v,a[tr[u].v]);
        else vec.emplace_back(u);
        if (tr[u].s[0]) q.emplace(tr[u].s[0]);
        if (tr[u].s[1]) q.emplace(tr[u].s[1]);
    }
    _iter(it,vec) {
        int u=*it;
        int L=findPrev(root[x],tr[u].v);
        int R=findNext(root[x],tr[u].v);
        splay(L,0,root[x]);
        splay(R,L,root[x]);
        tr[R].s[0]=0;
        pushup(R);
        pushup(L);
    }
}

inline void modify(int l,int r,int x) {
    int L=findPrev(root[x],l);
    int R=findNext(root[x],r);
    splay(L,0,root[x]);
    splay(R,L,root[x]);
    rmv(tr[R].s[0],x);
}

inline i64 query(int l,int r) {
    return SEG::query(1,l,r);
}

inline int build(vector<int>& arr,int p,int l,int r) {
    int mid=l+r>>1;
    int u=newNode();
    tr[u].init(p,arr[mid]);
    if (l<mid) tr[u].s[0]=build(arr,u,l,mid-1);
    if (r>mid) tr[u].s[1]=build(arr,u,mid+1,r);
    pushup(u);
    return u;
}

i32 main() {
    read(n),read(m);
    _rep(i,1,n) read(a[i]);
    _rep(i,1,A-1) arr[i].emplace_back(-inf);
    _rep(i,1,n) {
        if (a[i]<=1) continue;
        vector<int> vec;
        _rep(j,1,a[i]) {
            if (j*j>a[i]) break;
            if (a[i]%j==0) {
                vec.emplace_back(j);
                if (a[i]/j!=j) vec.emplace_back(a[i]/j);
            }
        }
        _iter(it,vec) arr[*it].emplace_back(i);
    }
    _rep(i,1,A-1) {
        arr[i].emplace_back(inf);
        root[i]=build(arr[i],0,0,(int)arr[i].size()-1);
    }
    SEG::build(1,1,n);
    while (m--) {
        int op,l,r;
        read(op),read(l),read(r);
        if (op==1) {
            int x;
            read(x);
            if (x==1) continue;
            modify(l,r,x);
        } else writeln(query(l,r));
    }
    return 0;
}