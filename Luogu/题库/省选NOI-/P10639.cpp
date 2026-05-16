#include <bits/stdc++.h>

#define int long long

using namespace std;

namespace IO {
    inline void read(int &a) {
        int sym=1,num=0;
        char c=getchar();
        while (c<'0' || c>'9') {
            if (c=='-') {
                sym=-1;
        }
        c=getchar();
        }
        while (c>='0' && c<='9') {
            num=num*10+c-'0';
            c=getchar();
        }
        a=sym*num;
    }
    inline void write(int a) {
        if (a<0) {
            putchar('-');
            a*=-1;
        }
        if (a>=10) {
            write(a/10);
        }
        putchar(a%10+'0');
    }
}

using IO::read;

const int N=500005;
const int inf=9e18;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int sum,max,min;
    int cntmax,cntmin;
    int submax,submin;
    int setmax,setmin;
    int add;
} tr[N*4];

inline void pushup(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    root.sum=left.sum+right.sum;
    root.max=max(left.max,right.max);
    root.min=min(left.min,right.min);
    if (left.max==right.max) {
        root.cntmax=left.cntmax+right.cntmax;
        root.submax=max(left.submax,right.submax);
    } else if (left.max<right.max) {
        root.cntmax=right.cntmax;
        root.submax=max(left.max,right.submax);
    } else {
        root.cntmax=left.cntmax;
        root.submax=max(left.submax,right.max);
    }
    if (left.min==right.min) {
        root.cntmin=left.cntmin+right.cntmin;
        root.submin=min(left.submin,right.submin);
    } else if (left.min<right.min) {
        root.cntmin=left.cntmin;
        root.submin=min(left.submin,right.min);
    } else {
        root.cntmin=right.cntmin;
        root.submin=min(left.min,right.submin);
    }
}

inline void pushsetmax(int u,int val) {
    if (val>=tr[u].max) return;
    tr[u].sum-=tr[u].cntmax*(tr[u].max-val);
    tr[u].setmax=val;
    tr[u].setmin=min(tr[u].setmin,tr[u].setmax);
    if (tr[u].submin==tr[u].max) tr[u].submin=val;
    if (tr[u].min==tr[u].max) tr[u].min=val;
    tr[u].max=val;
}

inline void pushsetmin(int u,int val) {
    if (val<=tr[u].min) return;
    tr[u].sum+=tr[u].cntmin*(val-tr[u].min);
    tr[u].setmin=val;
    tr[u].setmax=max(tr[u].setmax,tr[u].setmin);
    if (tr[u].submax==tr[u].min) tr[u].submax=val;
    if (tr[u].max==tr[u].min) tr[u].max=val;
    tr[u].min=val;
}

inline void pushadd(int u,int val) {
    tr[u].sum+=(tr[u].r-tr[u].l+1)*val;
    tr[u].max+=val;
    tr[u].min+=val;
    if (tr[u].setmax!=inf) tr[u].setmax+=val;
    if (tr[u].submax!=-inf) tr[u].submax+=val;
    if (tr[u].setmin!=-inf) tr[u].setmin+=val;
    if (tr[u].submin!=inf) tr[u].submin+=val;
    tr[u].add+=val;
}

inline void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.add) {
        pushadd(u<<1,root.add);
        pushadd(u<<1|1,root.add);
        root.add=0;
    }
    if (root.setmax!=inf) {
        pushsetmax(u<<1,root.setmax);
        pushsetmax(u<<1|1,root.setmax);
        root.setmax=inf;
    }
    if (root.setmin!=-inf) {
        pushsetmin(u<<1,root.setmin);
        pushsetmin(u<<1|1,root.setmin);
        root.setmin=-inf;
    }
}

inline void build(int u,int l,int r) {
    tr[u]={l,r,arr[l],arr[l],arr[l],1,1,-inf,inf,inf,-inf,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

inline void modify_add(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        pushadd(u,k);
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_add(u<<1,l,r,k);
        if (r>mid) modify_add(u<<1|1,l,r,k);
        pushup(u);
    }
}

inline void modify_setmax(int u,int l,int r,int k) {
    if (tr[u].max<=k) return;
    if (tr[u].l>=l && tr[u].r<=r && k>tr[u].submax) {
        if (tr[u].l!=tr[u].r) pushdown(u);
        pushsetmax(u,k);
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_setmax(u<<1,l,r,k);
        if (r>mid) modify_setmax(u<<1|1,l,r,k);
        pushup(u);
    }
}

inline void modify_setmin(int u,int l,int r,int k) {
    if (tr[u].min>=k) return;
    if (tr[u].l>=l && tr[u].r<=r && k<tr[u].submin) {
        if (tr[u].l!=tr[u].r) pushdown(u);
        pushsetmin(u,k);
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_setmin(u<<1,l,r,k);
        if (r>mid) modify_setmin(u<<1|1,l,r,k);
        pushup(u);
    }
}

inline int query_sum(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query_sum(u<<1,l,r);
    if (r>mid) ans+=query_sum(u<<1|1,l,r);
    return ans;
}

inline int query_max(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].max;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=-inf;
    if (l<=mid) ans=max(ans,query_max(u<<1,l,r));
    if (r>mid) ans=max(ans,query_max(u<<1|1,l,r));
    return ans;
}

inline int query_min(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].min;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=inf;
    if (l<=mid) ans=min(ans,query_min(u<<1,l,r));
    if (r>mid) ans=min(ans,query_min(u<<1|1,l,r));
    return ans;
}

signed main() {
    read(n);
    for (int i=1;i<=n;++i) {
        read(arr[i]);
    }
    build(1,1,n);
    read(m);
    while (m--) {
        int op,l,r;
        read(op); read(l); read(r);
        if (op==1) {
            int x;
            read(x);
            modify_add(1,l,r,x);
        } else if (op==2) {
            int x;
            read(x);
            modify_setmin(1,l,r,x);
        } else if (op==3) {
            int x;
            read(x);
            modify_setmax(1,l,r,x);
        } else if (op==4) {
            int ans=query_sum(1,l,r);
            printf("%lld\n",ans);
        } else if (op==5) {
            int ans=query_max(1,l,r);
            printf("%lld\n",ans);
        } else {
            int ans=query_min(1,l,r);
            printf("%lld\n",ans);
        }
    }
    return 0;
}