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
typedef pair<int,double> pid;

const int N=40005;
const int M=100005;
const double eps=1e-9;
const int mod=1e9;

int n,m,las;
int idx;

struct Line {
    double k,b;
} arr[M];

struct Seg {
    int l,r,id;
} tr[N<<2];

int sign(double k) {
    if (fabs(k)<eps) return 0;
    else if (k>0) return 1;
    else return -1;
}

int cmp(double a,double b) {
    if (fabs(a-b)<eps) return 0;
    else if (a-b>0) return 1;
    else return -1;
}

double calc(int id,int x) {
    return arr[id].k*x+arr[id].b;
}

void build(int u,int l,int r) {
    tr[u]={l,r,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
}

void pushdown(int u,int a) {
    // cout<<"pushdown "<<tr[u].l<<" "<<tr[u].r<<endl;
    int &b=tr[u].id;
    int mid=tr[u].l+tr[u].r>>1;
    int comp=cmp(calc(a,mid),calc(b,mid));
    if (comp>0 || (comp==0 && a<b)) swap(a,b); // let b above a (if same, then a is smaller id)
    int cmpl=cmp(calc(a,tr[u].l),calc(b,tr[u].l)),cmpr=cmp(calc(a,tr[u].r),calc(b,tr[u].r));
    if (cmpl>0 || (cmpl==0 && a<b)) pushdown(u<<1,a);
    if (cmpr>0 || (cmpr==0 && a<b)) pushdown(u<<1|1,a);
}

void modify(int u,int l,int r,int a) {
    if (tr[u].l>=l && tr[u].r<=r) pushdown(u,a);
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,a);
        if (r>mid) modify(u<<1|1,l,r,a);
    }
}

pid calc_max(pid a,pid b) {
    // cout<<"TEST: "<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<endl;
    if (cmp(a.second,b.second)==0) return {min(a.first,b.first),a.second};
    else if (cmp(a.second,b.second)>0) return a;
    else return b;
}

pid query(int u,int pos) {
    // cout<<"query "<<tr[u].l<<" "<<tr[u].r<<" "<<tr[u].id<<endl;
    pid ans={tr[u].id,calc(tr[u].id,pos)};
    // cout<<ans.first<<" "<<ans.second<<endl;
    if (tr[u].l==pos && tr[u].r==pos) return ans;
    int mid=tr[u].l+tr[u].r>>1;
    if (pos<=mid) ans=calc_max(ans,query(u<<1,pos));
    else ans=calc_max(ans,query(u<<1|1,pos));
    // cout<<tr[u].l<<" "<<tr[u].r<<" "<<ans.first<<" "<<ans.second<<endl;
    return ans;
}

int newLine(double x0,double y0,double x1,double y1) {
    if (!cmp(x0,x1)) arr[++idx]={0,max(y0,y1)};
    else arr[++idx]={(y1-y0)/(x1-x0),y0-(y1-y0)/(x1-x0)*x0};
    return idx;
}

// void test(int u,int l,int r) {
//     printf("[%d , %d] : %d\n",l,r,tr[u].id);
//     if (l==r) return;
//     int mid=l+r>>1;
//     test(u<<1,l,mid); test(u<<1|1,mid+1,r);
// }

int main() {
    scanf("%d",&m); n=39989;
    build(1,1,n);
    while (m--) {
        int op;
        scanf("%d",&op);
        if (!op) {
            int k;
            scanf("%d",&k);
            k=((k+las-1)%39989)+1;
            printf("%d\n",las=query(1,k).first);
        } else {
            int x0,y0,x1,y1;
            scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
            x0=((x0+las-1)%39989)+1;
            x1=((x1+las-1)%39989)+1;
            y0=((y0+las-1)%mod)+1;
            y1=((y1+las-1)%mod)+1;
            if (x0>x1) swap(x0,x1),swap(y0,y1);
            modify(1,x0,x1,newLine(x0,y0,x1,y1));
        }
        // test(1,1,20);
    }
    return 0;
}