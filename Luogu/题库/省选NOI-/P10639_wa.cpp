#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=500005;
const int inf=9e18;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int sum,max,min;
    int cntmax,cntmin;
    int hismax,hismin;
    int submax,submin;
    int addmax,addmin;
    int addmaxhis,addminhis;
    int addsubmax,addsubmin;
    int addsubmaxhis,addsubminhis;
} tr[N*4];

void pushup(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    root.sum=left.sum+right.sum;
    root.max=max(left.max,right.max);
    root.min=min(left.min,right.min);
    if (left.max==right.max) {
        root.submax=max(left.submax,right.submax);
    } else if (left.max<right.max) {
        root.submax=max(left.max,right.submax);
    } else {
        root.submax=max(left.submax,right.max);
    }
    if (left.min==right.min) {
        root.submin=min(left.submin,right.submin);
    } else if (left.min<right.min) {
        root.submin=min(left.submin,right.min);
    } else {
        root.submin=min(left.min,right.submin);
    }
}

void update_max(int u,int addmax,int addsubmax,int addmaxhis,int addsubmaxhis) {
    tr[u].sum+=tr[u].cntmax*addmax+(tr[u].r-tr[u].l+1-tr[u].cntmax)*addsubmax;
    tr[u].addmaxhis=max(tr[u].addmaxhis,tr[u].addmax+addmaxhis);
    tr[u].addsubmaxhis=max(tr[u].addsubmaxhis,tr[u].addsubmax+addsubmaxhis);
    tr[u].addmax+=addmax;
    tr[u].addsubmax+=addsubmax;
    tr[u].max+=addmax;
    if (tr[u].submax!=-inf) tr[u].submax+=addsubmax;
}

void update_min(int u,int addmin,int addsubmin,int addminhis,int addsubminhis) {
    tr[u].sum+=tr[u].cntmin*addmin+(tr[u].r-tr[u].l+1-tr[u].cntmin)*addsubmin;
    tr[u].addminhis=min(tr[u].addminhis,tr[u].addmin+addminhis);
    tr[u].addsubminhis=min(tr[u].addsubminhis,tr[u].addsubmin+addsubminhis);
    tr[u].addmin+=addmin;
    tr[u].addsubmin+=addsubmin;
    tr[u].min+=addmin;
    if (tr[u].submin!=inf) tr[u].submin+=addsubmin;
}

void pushmax(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    int val=max(left.max,right.max);
    if (val==left.max) {
        update_max(u<<1,root.addmax,root.addsubmax,root.addmaxhis,root.addsubmaxhis);
    } else {
        update_max(u<<1,root.addsubmax,root.addsubmax,root.addsubmaxhis,root.addsubmaxhis);
    }
    if (val==right.max) {
        update_max(u<<1|1,root.addmax,root.addsubmax,root.addmaxhis,root.addsubmaxhis);
    } else {
        update_max(u<<1|1,root.addsubmax,root.addsubmax,root.addsubmaxhis,root.addsubmaxhis);
    }
    root.addmax=root.addsubmax=0;
    root.addmaxhis=root.addsubmaxhis=0;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    int val=min(left.min,right.min);
    if (val==left.min) {
        update_min(u<<1,root.addmin,root.addsubmin,root.addminhis,root.addsubminhis);
    } else {
        update_min(u<<1,root.addsubmin,root.addsubmin,root.addsubminhis,root.addsubminhis);
    }
    if (val==right.min) {
        update_min(u<<1|1,root.addmin,root.addsubmin,root.addminhis,root.addsubminhis);
    } else {
        update_min(u<<1|1,root.addsubmin,root.addsubmin,root.addsubminhis,root.addsubminhis);
    }
    root.addmin=root.addsubmin=0;
    root.addminhis=root.addsubminhis=0;
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l],arr[l],arr[l],1,1,arr[l],arr[l],-inf,inf,0,0,0,0,0,0,0,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify_max(int u,int l,int r,int k) {
    if (tr[u].max<=k) return;
    if (tr[u].l>=l && tr[u].r<=r && k>tr[u].submax) {
        if (tr[u].l!=tr[u].r) pushdown(u);
        update_max(u,k-tr[u].max,0,k-tr[u].max,0);
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_max(u<<1,l,r,k);
        if (r>mid) modify_max(u<<1|1,l,r,k);
        pushup(u);
    }
}

void modify_min(int u,int l,int r,int k) {
    if (tr[u].min>=k) return;
    if (tr[u].l>=l && tr[u].r<=r && k<tr[u].submin) {
        if (tr[u].l!=tr[u].r) pushdown(u);
        update_min(u,k-tr[u].min,0,k-tr[u].min,0);
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_min(u<<1,l,r,k);
        if (r>mid) modify_min(u<<1|1,l,r,k);
        pushup(u);
    }
}

void modify_add(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        if (tr[u].l!=tr[u].r) pushdown(u);
        update_max(u,k,k,k,k);
        update_min(u,k,k,k,k);
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_add(u<<1,l,r,k);
        if (r>mid) modify_add(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query_sum(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query_sum(u<<1,l,r);
    if (r>mid) ans+=query_sum(u<<1|1,l,r);
    return ans;
}

int query_max(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].max;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=-inf;
    if (l<=mid) ans=max(ans,query_max(u<<1,l,r));
    if (r>mid) ans=max(ans,query_max(u<<1|1,l,r));
    return ans;
}

int query_min(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].min;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=inf;
    if (l<=mid) ans=min(ans,query_min(u<<1,l,r));
    if (r>mid) ans=min(ans,query_min(u<<1|1,l,r));
    return ans;
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    build(1,1,n);
    scanf("%lld",&m);
    while (m--) {
        int op,l,r;
        scanf("%lld %lld %lld",&op,&l,&r);
        if (op==1) {
            int x;
            scanf("%lld",&x);
            modify_add(1,l,r,x);
        } else if (op==2) {
            int x;
            scanf("%lld",&x);
            modify_min(1,l,r,x);
        } else if (op==3) {
            int x;
            scanf("%lld",&x);
            modify_max(1,l,r,x);
        } else if (op==4) {
            printf("%lld\n",query_sum(1,l,r));
        } else if (op==5) {
            printf("%lld\n",query_max(1,l,r));
        } else {
            printf("%lld\n",query_min(1,l,r));
        }
    }
    return 0;
}