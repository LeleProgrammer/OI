#include <bits/stdc++.h>
using namespace std;

const int N=100005;

typedef pair<double,double> pdd;

int n,m;
double arr[N];

struct SegmentTree {
    int l,r;
    double add;
    double sum1,sum2;
} tr[N*4];

void pushup(int u) {
    tr[u].sum1=tr[u<<1].sum1+tr[u<<1|1].sum1;
    tr[u].sum2=tr[u<<1].sum2+tr[u<<1|1].sum2;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.add) {
        left.add+=root.add;
        right.add+=root.add;
        left.sum2+=2*root.add*left.sum1+(left.r-left.l+1)*root.add*root.add;
        left.sum1+=(left.r-left.l+1)*root.add;
        right.sum2+=2*root.add*right.sum1+(right.r-right.l+1)*root.add*root.add;
        right.sum1+=(right.r-right.l+1)*root.add;
        root.add=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,0.00,arr[l],arr[l]*arr[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,double k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=k;
        tr[u].sum2+=2*k*tr[u].sum1+(tr[u].r-tr[u].l+1)*k*k;
        tr[u].sum1+=(tr[u].r-tr[u].l+1)*k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

pdd query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return {tr[u].sum1,tr[u].sum2};
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    double ans1=0,ans2=0;
    if (l<=mid) {
        auto p=query(u<<1,l,r);
        ans1+=p.first;
        ans2+=p.second;
    }
    if (r>mid) {
        auto p=query(u<<1|1,l,r);
        ans1+=p.first;
        ans2+=p.second;
    }
    return {ans1,ans2};
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%lf",&arr[i]);
    build(1,1,n);
    while (m--) {
        int op,x,y;
        scanf("%d %d %d",&op,&x,&y);
        if (op==1) {
            double k;
            scanf("%lf",&k);
            modify(1,x,y,k);
        } else if (op==2) {
            auto t=query(1,x,y);
            printf("%.4lf\n",t.first/(double(y-x+1)));
        } else {
            auto t=query(1,x,y);
            double avg=t.first/(double(y-x+1));
            printf("%.4lf\n",t.second/(double(y-x+1))-avg*avg);
        }
    }
    return 0;
}