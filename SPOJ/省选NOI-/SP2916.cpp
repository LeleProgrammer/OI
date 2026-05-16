#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int T,n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int lmx,rmx,mmx;
    int sum;
} tr[N*4];

SegmentTree pushup(SegmentTree l,SegmentTree r) {
    SegmentTree ans;
    ans.mmx=max(max(l.mmx,r.mmx),l.rmx+r.lmx);
    ans.lmx=max(l.lmx,l.sum+r.lmx);
    ans.rmx=max(r.rmx,r.sum+l.rmx);
    ans.sum=l.sum+r.sum;
    return ans;
}

void pushup(int u) {
    tr[u].mmx=max(max(tr[u<<1].mmx,tr[u<<1|1].mmx),tr[u<<1].rmx+tr[u<<1|1].lmx);
    tr[u].lmx=max(tr[u<<1].lmx,tr[u<<1].sum+tr[u<<1|1].lmx);
    tr[u].rmx=max(tr[u<<1|1].rmx,tr[u<<1|1].sum+tr[u<<1].rmx);
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l],arr[l],arr[l],arr[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

SegmentTree query(int u,int l,int r) {
    if (l>r) return {0,0,0,0,0,0};
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    int mid=tr[u].l+tr[u].r>>1;
    if (l<=mid && r>mid) {
        SegmentTree L=query(u<<1,l,r),R=query(u<<1|1,l,r);
        SegmentTree ans=pushup(L,R);
        return ans;
    } else if (l<=mid) return query(u<<1,l,r);
    else return query(u<<1|1,l,r);
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d",&arr[i]);
        build(1,1,n);
        scanf("%d",&m);
        while (m--) {
            int x1,y1,x2,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if (x1==x2 && y1==y2) {
                SegmentTree ans=query(1,x1,y1);
                printf("%d\n",ans.mmx);
            } else if (x2<=y1) {
                SegmentTree a,b,c,d,e;
                a=query(1,x1,x2),b=query(1,x2,y1),c=query(1,y1,y2),d=query(1,x2,y2),e=query(1,x1,y1);
                int ans=max(max(a.rmx+d.lmx-arr[x2],e.rmx+c.lmx-arr[y1]),b.mmx);
                printf("%d\n",ans,a.rmx+d.lmx-arr[x2],e.rmx+c.lmx-arr[y1],b.mmx);
            } else {
                SegmentTree a=query(1,x1,y1),b=query(1,x2,y2),c=query(1,y1+1,x2-1);
                printf("%d\n",a.rmx+b.lmx+c.sum);
            }
        }
    }
    return 0;
}