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
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=100005;
const double eps=1e-9;

int n,m,idx;

struct Line {
    double k,b;
} arr[N];

struct Seg {
    int l,r,id;
} tr[N<<2];

int sign(double k) {
    if (fabs(k)<0) return 0;
    else if (k>0) return 1;
    else return -1;
}

int cmp(double a,double b) {
    if (fabs(a-b)<0) return 0;
    else if (a>b) return 1;
    else return -1;
}

void build(int u,int l,int r) {
    tr[u]={l,r,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
}

double calc(int id,int x) {
    return arr[id].k*x+arr[id].b;
}

void pushdown(int u,int a) {
    int &b=tr[u].id;
    int mid=tr[u].l+tr[u].r>>1;
    int comp=cmp(calc(a,mid),calc(b,mid));
    if (comp>0) swap(a,b);
    int cmpl=cmp(calc(a,tr[u].l),calc(b,tr[u].l));
    int cmpr=cmp(calc(a,tr[u].r),calc(b,tr[u].r));
    if (cmpl>0) pushdown(u<<1,a);
    if (cmpr>0) pushdown(u<<1|1,a);
}

int newLine(double s,double p) {
    double k=p,b=s-p;
    arr[++idx]={k,b};
    return idx;
}

void modify(int u,int l,int r,int a) {
    if (tr[u].l>=l && tr[u].r<=r) pushdown(u,a);
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,a);
        if (r>mid) modify(u<<1|1,l,r,a);
    }
}

double query(int u,int p) {
    if (tr[u].l==p && tr[u].r==p) return calc(tr[u].id,p);
    int mid=tr[u].l+tr[u].r>>1;
    double ans=calc(tr[u].id,p);
    if (p<=mid) ans=max(ans,query(u<<1,p));
    else ans=max(ans,query(u<<1|1,p));
    return ans;
}

int main() {
    scanf("%d",&m); n=50000;
    build(1,1,n);
    while (m--) {
        char s[16];
        scanf("%s",s);
        if (!strcmp(s,"Query")) {
            int t;
            scanf("%d",&t);
            printf("%d\n",(int)floor(query(1,t)/100.0));
        } else if (!strcmp(s,"Project")) {
            double s,p;
            scanf("%lf %lf",&s,&p);
            modify(1,1,n,newLine(s,p));
        }
    }
    return 0;
}