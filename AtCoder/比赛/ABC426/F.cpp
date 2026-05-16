#include <bits/stdc++.h>
using namespace std;

#define int i128

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

const int N=300005;

int n,q;
int a[N];

struct Seg {
    int l,r;
    int sum;
    int mn;
    int add;
    int cnt;
} tr[N<<2];

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    if (!tr[u<<1].mn) tr[u].mn=tr[u<<1|1].mn;
    else if (!tr[u<<1|1].mn) tr[u].mn=tr[u<<1].mn;
    else tr[u].mn=min(tr[u<<1].mn,tr[u<<1|1].mn);
    tr[u].cnt=tr[u<<1].cnt+tr[u<<1|1].cnt;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.add) {
        if (left.mn) {
            left.add+=root.add;
            left.mn+=root.add;
            left.sum+=left.cnt*root.add;
        }
        if (right.mn) {
            right.mn+=root.add;
            right.add+=root.add;
            right.sum+=right.cnt*root.add;
        }
        root.add=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,a[l],a[l],0,1};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

int modify(int u,int l,int r,int k) {
    if (!tr[u].mn) return 0;
    else if (tr[u].l==tr[u].r && tr[u].mn<=k) {
        int ans=tr[u].mn;
        tr[u].mn=0,tr[u].sum=0,tr[u].add=0,tr[u].cnt=0;
        return ans;
    } else if (tr[u].l>=l && tr[u].r<=r && tr[u].mn>k) {
        tr[u].add-=k;
        tr[u].sum-=tr[u].cnt*k;
        tr[u].mn-=k;
        return k*tr[u].cnt;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        int ans=0;
        if (l<=mid) ans+=modify(u<<1,l,r,k);
        if (r>mid) ans+=modify(u<<1|1,l,r,k);
        pushup(u);
        return ans;
    }
}

i32 main() {
    read(n);
    _rep(i,1,n) read(a[i]);
    build(1,1,n);
    read(q);
    while (q--) {
        int l,r,k;
        read(l),read(r),read(k);
        writeln(modify(1,l,r,k));
    }
    return 0;
}