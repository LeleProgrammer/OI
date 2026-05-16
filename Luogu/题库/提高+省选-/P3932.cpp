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
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=200005;
const int mod=19260817;

int n,m;
int d[N],a[N];
int ans[N],pre[N];

struct Seg {
    int l,r;
    int k,add;
} tr[N<<2];

struct Query {
    int x,l,r,i;
    friend bool operator < (const Query& a,const Query& b) {
        return a.x<b.x;
    }
} q[N];

void pushup(int u) {
    tr[u].k=tr[u<<1].k+tr[u<<1|1].k;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.add) {
        left.add=(left.add+root.add)%mod,right.add=(right.add+root.add)%mod;
        left.k=(left.k+(pre[left.r]-pre[left.l-1])*root.add)%mod,right.k=(right.k+(pre[right.r]-pre[right.l-1])*root.add)%mod;
        root.add=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,a[l]%mod,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) tr[u].add=(tr[u].add+k)%mod,tr[u].k=(tr[u].k+(pre[tr[u].r]-pre[tr[u].l-1])*k)%mod;
    else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].k;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query(u<<1,l,r);
    if (r>mid) ans+=query(u<<1|1,l,r);
    ans%=mod;
    return ans;
}

i32 main() {
    read(n),read(m);
    _rep(i,1,n-1) read(d[i]);
    _rep(i,1,n) read(a[i]),pre[i]=(pre[i-1]+a[i])%mod;
    _rep(i,1,m) read(q[i].x),read(q[i].l),read(q[i].r),q[i].i=i;
    sort(q+1,q+1+m);
    int s=0;
    _rep(i,1,n) a[i]=a[i]*s%mod,s=(s+d[i])%mod;
    build(1,1,n);
    int cur=1;
    _rep(i,1,m) {
        int x=q[i].x,l=q[i].l,r=q[i].r,id=q[i].i;
        while (cur<x) modify(1,1,cur,d[cur]),modify(1,cur+1,n,-d[cur]),cur++;
        ans[id]=query(1,l,r);
        ans[id]=(ans[id]%mod+mod)%mod;
    }
    _rep(i,1,m) writeln(ans[i]);
    return 0;
}