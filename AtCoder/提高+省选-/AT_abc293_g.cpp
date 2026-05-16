#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int n,m,len;
int w[N];
int cnt[N];
int ans[N];

struct Query {
    int id,l,r;
} q[N];

int get(int x) {
    return x/len;
}

bool cmp(const Query& a,const Query& b) {
    int al=get(a.l),bl=get(b.l);
    if (al!=bl) return al<bl;
    return a.r<b.r;
}

int cal(int x) {
    return (x*(x-1)*(x-2))/6;
}

void add(int x,int& s) {
    if (cnt[x]>=3) s-=cal(cnt[x]);
    cnt[x]++;
    if (cnt[x]>=3) s+=cal(cnt[x]);
}

void del(int x,int& s) {
    if (cnt[x]>=3) s-=cal(cnt[x]);
    cnt[x]--;
    if (cnt[x]>=3) s+=cal(cnt[x]);
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&w[i]);
    }
    len=sqrt(n);
    for (int i=1;i<=m;++i) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        q[i]={i,a,b};
    }
    sort(q+1,q+1+m,cmp);
    for (int k=1,i=0,j=1,s=0;k<=m;++k) {
        int id=q[k].id;
        int l=q[k].l;
        int r=q[k].r;
        while (i<r) add(w[++i],s);
        while (i>r) del(w[i--],s);
        while (j<l) del(w[j++],s);
        while (j>l) add(w[--j],s);
        ans[id]=s;
    }
    for (int i=1;i<=m;++i) {
        printf("%lld\n",ans[i]);
    }
    return 0;
}