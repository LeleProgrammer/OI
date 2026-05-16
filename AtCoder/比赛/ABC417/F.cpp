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
    inline void writestr(string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=200005;
const int mod=998244353;

int n,m;
int a[N];

struct Seg {
    int l,r;
    pii v;
    pii set;
} tr[N<<2];

int exgcd(int a,int b,int& x,int& y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int inverse(int a) {
    int x,y;
    exgcd(a,mod,x,y);
    x=(x%mod+mod)%mod;
    return x;
}

pii operator + (const pii& a,const pii& b) {
    return pii{(a.first*b.second+a.second*b.first)%mod,a.second*b.second%mod};
}

pii operator * (const pii& a,const int& b) {
    return pii{a.first*b%mod,a.second};
}

void pushup(int u) {
    tr[u].v=tr[u<<1].v+tr[u<<1|1].v;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (~root.set.first && ~root.set.second) {
        left.set=root.set;
        left.v=root.set*(left.r-left.l+1);
        right.set=root.set;
        right.v=root.set*(right.r-right.l+1);
        root.set=pii{-1,-1};
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,pii{a[l],1},pii{-1,-1}};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,pii k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].set=k;
        tr[u].v=k*(tr[u].r-tr[u].l+1);
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

pii query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].v;
    pushdown(u);
    pii ans,L={0,1},R={0,1};
    int mid=tr[u].l+tr[u].r>>1;
    if (l<=mid) L=query(u<<1,l,r);
    if (r>mid) R=query(u<<1|1,l,r);
    ans=L+R;
    return ans;
}

i32 main() {
    read(n),read(m);
    _rep(i,1,n) read(a[i]);
    build(1,1,n);
    while (m--) {
        int l,r;
        read(l),read(r);
        pii sum=query(1,l,r);
        // cout<<"sum: "<<sum.first<<" "<<sum.second<<endl;
        sum.second=sum.second*(r-l+1)%mod;
        modify(1,l,r,sum);
    }
    _rep(i,1,n) {
        auto res=query(1,i,i);
        int ans=res.first*inverse(res.second)%mod;
        writesp(ans);
    }
    return 0;
}