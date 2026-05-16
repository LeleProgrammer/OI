#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int T,n,q,l,r;
int a[N];
int ans1,ans2;

struct node {
    int l,r;
    bool diff;
    int val;
    int difl,difr;
    int difli,difri;
} tr[N*4];

void pushup(int u) {
    if (tr[u<<1].diff) {
        tr[u].diff=true;
        tr[u].difl=tr[u<<1].difl;
        tr[u].difr=tr[u<<1].difr;
        tr[u].difli=tr[u<<1].difli;
        tr[u].difri=tr[u<<1].difri;
    } else if (tr[u<<1|1].diff) {
        tr[u].diff=true;
        tr[u].difl=tr[u<<1|1].difl;
        tr[u].difr=tr[u<<1|1].difr;
        tr[u].difli=tr[u<<1|1].difli;
        tr[u].difri=tr[u<<1|1].difri;
    } else if (tr[u<<1].val==tr[u<<1|1].val) {
        tr[u].diff=false;
        tr[u].val=tr[u<<1].val;
    } else {
        tr[u].diff=true;
        tr[u].difl=tr[u<<1].val;
        tr[u].difr=tr[u<<1|1].val;
        tr[u].difli=tr[u<<1].l;
        tr[u].difri=tr[u<<1|1].l;
    }
}

void build(int u,int l,int r) {
    if (l==r) tr[u]={l,r,false,a[l],0,0};
    else {
        tr[u]={l,r,false,0,0,0};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

bool query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) {
        if (tr[u].diff) ans1=tr[u].difli,ans2=tr[u].difri;
        // cout<<"TEST:"<<tr[u].diff<<" "<<tr[u].l<<" "<<tr[u].r<<endl;
        return tr[u].diff;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        int ansl,ansr;
        ansl=-1,ansr=-1;
        if (l<=mid) ansl=query(u<<1,l,r);
        if (r>mid) ansr=query(u<<1|1,l,r);
        if (ansl==0 && ansr==0) {
            if (a[mid]==a[mid+1]) return 0;
            ans1=mid,ans2=mid+1;
            return 1;
        }
        if (ansl==1 || ansr==1) return 1;
        if (ansl==-1) return ansr;
        if (ansr==-1) return ansl;
    }
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d",a+i);
        build(1,1,n);
        scanf("%d",&q);
        while (q--) {
            scanf("%d %d",&l,&r);
            if (!query(1,l,r)) puts("-1 -1");
            else {
                printf("%d %d\n",ans1,ans2);
            }
        }
        putchar(10);
    }
    return 0;
}