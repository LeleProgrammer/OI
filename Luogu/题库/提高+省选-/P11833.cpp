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
    inline void writestr(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); }
    inline void writestrsp(string x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(' '); }
    inline void writestrln(string x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=200005;
const int inf=2.01e9;

int c,T;
int n;
int a[N],b[N];
i64 t[N];
int s[N];
i64 cur;

struct Seg {
    int l,r;
    int posmx,posmn,mx,mn;
    int add,ms,ns;
} tr[N<<2];

void pushup(int u) {
    tr[u].posmx=max(tr[u<<1].posmx,tr[u<<1|1].posmx);
    tr[u].posmn=min(tr[u<<1].posmn,tr[u<<1|1].posmn);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.add) {
        left.add+=root.add;
        right.add+=root.add;
        left.posmx+=root.add;
        left.posmn+=root.add;
        right.posmx+=root.add;
        right.posmn+=root.add;
        root.add=0;
    }
    if (root.ms) {
        left.ms=left.mx=right.ms=right.mx=root.ms;
        root.ms=0;
    }
    if (root.ns) {
        left.ns=left.mn=right.ns=right.mn=root.ns;
        root.ns=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,a[l],a[l],0,0,0,0,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=k;
        tr[u].posmx+=k;
        tr[u].posmn+=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

void modify_mx(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].ms=tr[u].mx=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_mx(u<<1,l,r,k);
        if (r>mid) modify_mx(u<<1|1,l,r,k);
        pushup(u);
    }
}

void modify_mn(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].ns=tr[u].mn=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_mn(u<<1,l,r,k);
        if (r>mid) modify_mn(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int p) {
    if (tr[u].l==p && tr[u].r==p) return tr[u].posmx;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if (p<=mid) return query(u<<1,p);
    else return query(u<<1|1,p);
}

int query_mx(int u,int p) {
    if (tr[u].l==p && tr[u].r==p) return tr[u].mx;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if (p<=mid) return query_mx(u<<1,p);
    else return query_mx(u<<1|1,p);
}

int query_mn(int u,int p) {
    if (tr[u].l==p && tr[u].r==p) return tr[u].mn;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if (p<=mid) return query_mn(u<<1,p);
    else return query_mn(u<<1|1,p);
}

bool cmp(const int& a,const int& b) {
    return t[a]<t[b];
}

void moveR(int a,int b,int dest) {
    while (true) {
        int posa=query(1,a),posb=query(1,b);
        int len=posb-posa+1;
        if (posa==dest) break;
        int d;
        if (b<n) d=query(1,b+1);
        else d=inf;
        if (d>dest+len-1) {
            // disconnect
            if (a>1 && query(1,a-1)==posa-1) {
                modify_mx(1,query_mn(1,a-1),a-1,a-1);
            }
            // move
            modify(1,a,b,dest-posa);
            cur+=(i64)(dest-posa)*len;
            modify_mn(1,a,b,a);
            // connect
            if (b<n && query(1,b+1)==dest+1) {
                modify_mn(1,b+1,query_mx(1,b+1),a);
                modify_mx(1,a,b,query_mx(1,b+1));
            }
            break;
        } else {
            d--;
            if (b<d) {
                // disconnect
                if (a>1 && query(1,a-1)==posa-1) {
                    modify_mx(1,query_mn(1,a-1),a-1,a-1);
                }
                // move
                modify(1,a,b,d-posb);
                cur+=(i64)(d-posb)*len;
                modify_mn(1,a,b,a);
                // connect
                modify_mn(1,b+1,query_mx(1,b+1),a);
                modify_mx(1,a,b,query_mx(1,b+1));
            }
            b=query_mx(1,b+1);
        }
    }
}

void moveL(int a,int b,int dest) {
    while (true) {
        int posa=query(1,a),posb=query(1,b);
        int len=posb-posa+1;
        if (posb==dest) break;
        int d;
        if (a>1) d=query(1,a-1);
        else d=-inf;
        if (d<dest-len+1) {
            // disconnect
            if (b<n && query(1,b+1)==posb+1) {
                modify_mn(1,b+1,query_mx(1,b+1),b+1);
            }
            // move
            modify(1,a,b,-(posb-dest));
            cur+=(i64)(posb-dest)*len;
            modify_mx(1,a,b,b);
            // connect
            if (a>1 && query(1,a-1)==dest-1) {
                modify_mx(1,query_mn(1,a-1),a-1,b);
                modify_mn(1,a,b,query_mn(1,a-1));
            }
            break;
        } else {
            d++;
            if (d!=posa) {
                // disconnect
                if (b<n && query(1,b+1)==posb+1) {
                    modify_mn(1,b+1,query_mx(1,b+1),b+1);
                }
                // move
                modify(1,a,b,-(posa-d));
                cur+=(i64)(posa-d)*len;
                modify_mx(1,a,b,b);
                // connect
                modify_mx(1,query_mn(1,a-1),a-1,b);
                modify_mn(1,a,b,query_mn(1,a-1));
            }
            a=query_mn(1,a-1);
        }
    }
}

int main() {
    // FRR("P11833_5.in");
    // FRW("P11833_my.out");
    read(c),read(T);
    while (T--) {
        read(n);
        _rep(i,1,n) read(a[i]),read(b[i]),read(t[i]);
        build(1,1,n);
        _rep(l,1,n) {
            int r=n;
            _rep(i,l+1,n) {
                if (a[i]!=a[i-1]) {
                    r=i-1;
                    break;
                }
            }
            modify_mx(1,l,r,r);
            modify_mn(1,l,r,l);
            l=r;
        }
        _rep(i,1,n) s[i]=i;
        sort(s+1,s+1+n,cmp);
        cur=0;
        bool ok=true;
        _rep(i,1,n) {
            int k=s[i];
            if (query(1,k)==b[k]) continue;
            else if (query(1,k)<b[k]) moveR(k,query_mx(1,k),b[k]);
            else moveL(query_mn(1,k),k,b[k]);
            if (cur>t[k]) {
                ok=false;
                break;
            }
        }
        if (ok) puts("Yes");
        else puts("No");
    }
    // TIMESTAMP
    return 0;
}