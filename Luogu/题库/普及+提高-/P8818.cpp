#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int inf=9e18;

int n,m,q;
int a[N],b[N];

struct SegmentTree {
    int l,r;
    int pmax;
    int pmin;
    int nmax;
    int nmin;
    bool zero;
} tra[N*4],trb[N*4];

void pushupa(int u) {
    tra[u].pmax=max(tra[u<<1].pmax,tra[u<<1|1].pmax);
    tra[u].pmin=min(tra[u<<1].pmin,tra[u<<1|1].pmin);
    tra[u].nmax=max(tra[u<<1].nmax,tra[u<<1|1].nmax);
    tra[u].nmin=min(tra[u<<1].nmin,tra[u<<1|1].nmin);
    tra[u].zero=tra[u<<1].zero|tra[u<<1|1].zero;
}

void pushupb(int u) {
    trb[u].pmax=max(trb[u<<1].pmax,trb[u<<1|1].pmax);
    trb[u].pmin=min(trb[u<<1].pmin,trb[u<<1|1].pmin);
    trb[u].nmax=max(trb[u<<1].nmax,trb[u<<1|1].nmax);
    trb[u].nmin=min(trb[u<<1].nmin,trb[u<<1|1].nmin);
    trb[u].zero=trb[u<<1].zero|trb[u<<1|1].zero;
}

SegmentTree combine(SegmentTree a,SegmentTree b) {
    SegmentTree ans;
    ans.pmax=max(a.pmax,b.pmax);
    ans.pmin=min(a.pmin,b.pmin);
    ans.nmax=max(a.nmax,b.nmax);
    ans.nmin=min(a.nmin,b.nmin);
    ans.zero=a.zero|b.zero;
    return ans;
}

void builda(int u,int l,int r) {
    tra[u]={l,r,a[l]>0?a[l]:-inf,a[l]>0?a[l]:inf,a[l]<0?a[l]:-inf,a[l]<0?a[l]:inf,!a[l]};
    if (l==r) return;
    int mid=l+r>>1;
    builda(u<<1,l,mid);
    builda(u<<1|1,mid+1,r);
    pushupa(u);
}

void buildb(int u,int l,int r) {
    trb[u]={l,r,b[l]>0?b[l]:-inf,b[l]>0?b[l]:inf,b[l]<0?b[l]:-inf,b[l]<0?b[l]:inf,!b[l]};
    if (l==r) return;
    int mid=l+r>>1;
    buildb(u<<1,l,mid);
    buildb(u<<1|1,mid+1,r);
    pushupb(u);
}

SegmentTree querya(int u,int l,int r) {
    if (tra[u].l>=l && tra[u].r<=r) return tra[u];
    int mid=tra[u].l+tra[u].r>>1;
    if (l<=mid && r>mid) {
        auto left=querya(u<<1,l,r);
        auto right=querya(u<<1|1,l,r);
        return combine(left,right);
    } else if (l<=mid) {
        return querya(u<<1,l,r);
    } else {
        return querya(u<<1|1,l,r);
    }
}

SegmentTree queryb(int u,int l,int r) {
    if (trb[u].l>=l && trb[u].r<=r) return trb[u];
    int mid=trb[u].l+trb[u].r>>1;
    if (l<=mid && r>mid) {
        auto left=queryb(u<<1,l,r);
        auto right=queryb(u<<1|1,l,r);
        return combine(left,right);
    } else if (l<=mid) {
        return queryb(u<<1,l,r);
    } else {
        return queryb(u<<1|1,l,r);
    }
}

signed main() {
    scanf("%lld %lld %lld",&n,&m,&q);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
    }
    for (int i=1;i<=m;++i) {
        scanf("%lld",&b[i]);
    }
    builda(1,1,n);
    buildb(1,1,m);
    while (q--) {
        int l1,r1,l2,r2;
        scanf("%lld %lld %lld %lld",&l1,&r1,&l2,&r2);
        auto A=querya(1,l1,r1);
        auto B=queryb(1,l2,r2);
        bool apos=A.pmax!=-inf;
        bool aneg=A.nmax!=-inf;
        bool bpos=B.pmax!=-inf;
        bool bneg=B.nmax!=-inf;
        bool azer=A.zero;
        bool bzer=B.zero;
        int ans;
        if (!apos && !aneg) ans=0;
        else if (!bpos && !bneg) ans=0;
        else if (apos && bpos && !aneg && !bneg) { // + +
            if (bzer) ans=0; // + 0
            else ans=A.pmax*B.pmin;
        } else if (apos && bneg && !aneg && !bpos) { // + -
            if (azer) ans=0; // 0 -
            else ans=A.pmin*B.nmin;
        } else if (aneg && bpos && !apos && !bneg) { // - +
            if (azer) ans=0; // 0 +
            else ans=A.nmax*B.pmax;
        } else if (aneg && bneg && !apos && !bpos) { // - -
            if (bzer) ans=0; // - 0
            else ans=A.nmin*B.nmax;
        } else if (aneg && apos && bpos && !bneg) { // +- +
            if (bzer) ans=0;
            else ans=A.pmax*B.pmin;
        } else if (aneg && apos && bneg && !bpos) { // +- -
            if (bzer) ans=0;
            else ans=A.nmin*B.nmax;
        } else if (apos && !aneg && bpos && bneg) { // + +-
            if (azer) ans=0;
            else ans=A.pmin*B.nmin;
        } else if (aneg && !apos && bpos && bneg) { // - +-
            if (azer) ans=0;
            else ans=A.nmax*B.pmax;
        } else if (aneg && apos && bneg && bpos) { // +- +-
            if (azer) ans=0;
            else ans=max(A.pmin*B.nmin,A.nmax*B.pmax);
        } else {
            assert(false);
        }
        printf("%lld\n",ans);
    }
    return 0;
}