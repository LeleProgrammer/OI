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

const int N=1000005;
const int inf=1e9;

int n,q;

struct node {
    int l,r;
    int mx,mn;
} tr[N<<2];

void pushup(int u) {
    tr[u].mx=max(tr[u<<1].mx,tr[u<<1|1].mx);
    tr[u].mn=min(tr[u<<1].mn,tr[u<<1|1].mn);
}

void build(int u,int l,int r) {
    tr[u]={l,r,-inf,inf};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int p,int k) {
    if (tr[u].l==p && tr[u].r==p) {
        tr[u].mx=max(tr[u].mx,k);
        tr[u].mn=min(tr[u].mn,k);
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (p<=mid) modify(u<<1,p,k);
        else modify(u<<1|1,p,k);
        pushup(u);
    }
}

int query_mx(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].mx;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=-inf;
    if (l<=mid) ans=max(ans,query_mx(u<<1,l,r));
    if (r>mid) ans=max(ans,query_mx(u<<1|1,l,r));
    return ans;
}

int query_mn(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].mn;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=inf;
    if (l<=mid) ans=min(ans,query_mn(u<<1,l,r));
    if (r>mid) ans=min(ans,query_mn(u<<1|1,l,r));
    return ans;
}

int main() {
    read(n),read(q);
    build(1,1,n);
    while (q--) {
        int a,b;
        read(a),read(b);
        if (a>b) swap(a,b);
        bool ok=true;
        if (a+1<=b-1 && (query_mx(1,a+1,b-1)>b || query_mn(1,a+1,b-1)<a)) ok=false;
        if (!ok) puts("No");
        else {
            puts("Yes");
            modify(1,a,b);
            modify(1,b,a);
        }
    }
    return 0;
}