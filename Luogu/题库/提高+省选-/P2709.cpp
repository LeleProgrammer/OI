#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=50005;

int n,m,k,len;
int arr[N];
int cnt[N];
int ans[N];
int l,r;

struct Query {
    int id,l,r;
} q[N];

int get(int x) {
    return x/len;
}

bool cmp(const Query& a,const Query& b) {
    int al=get(a.l);
    int bl=get(b.l);
    if (al!=bl) return al<bl;
    return a.r<b.r;
}

void add(int x,int& s) {
    s-=cnt[x]*cnt[x];
    cnt[x]++;
    s+=cnt[x]*cnt[x];
}

void del(int x,int& s) {
    s-=cnt[x]*cnt[x];
    cnt[x]--;
    s+=cnt[x]*cnt[x];
}

signed main() {
    scanf("%lld %lld %lld",&n,&m,&k);
    len=sqrt(n);
    for (int i=1;i<=n;++i) scanf("%lld",&arr[i]);
    for (int i=1;i<=m;++i) {
        int l,r;
        scanf("%lld %lld",&l,&r);
        q[i]={i,l,r};
    }
    sort(q+1,q+1+m,cmp);
    for (int k=1,i=0,j=1,s=0;k<=m;++k) {
        int id=q[k].id;
        int l=q[k].l;
        int r=q[k].r;
        while (i<r) add(arr[++i],s);
        while (i>r) del(arr[i--],s);
        while (j<l) del(arr[j++],s);
        while (j>l) add(arr[--j],s);
        ans[id]=s;
    }
    for (int i=1;i<=m;++i) {
        printf("%lld\n",ans[i]);
    }
    return 0;
}