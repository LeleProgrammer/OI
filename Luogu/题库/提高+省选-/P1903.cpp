#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=133338;
const int M=1000005;

int n,m,cntq,cntm;
int len;
int arr[N];
int ans[N];
int cnt[M];

int get(int x) {
    return x/len;
}

struct Query {
    int id,l,r,t;
} q[N];

struct Modify {
    int a,b;
} mod[N];

bool cmp(const Query& a,const Query& b) {
    int al=get(a.l);
    int ar=get(a.r);
    int bl=get(b.l);
    int br=get(b.r);
    if (al!=bl) return al<bl;
    if (ar!=br) return ar<br;
    return a.t<b.t;
}

inline void add(int x,int& s) {
    if (!cnt[x]) s++;
    cnt[x]++;
}

inline void del(int x,int& s) {
    cnt[x]--;
    if (!cnt[x]) s--;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    for (int i=1;i<=m;++i) {
        char op[2];
        int l,r;
        scanf("%s %lld %lld",op,&l,&r);
        if (*op=='Q') {
            ++cntq;
            q[cntq]={cntq,l,r,cntm};
        } else {
            ++cntm;
            mod[cntm]={l,r};
        }
    }
    len=max(1LL,(int)cbrt(n*max(1LL,cntm)));
    sort(q+1,q+1+cntq,cmp);
    for (int k=1,i=0,j=1,t=0,s=0;k<=cntq;++k) {
        int id=q[k].id;
        int l=q[k].l;
        int r=q[k].r;
        int tt=q[k].t;
        while (i<r) add(arr[++i],s);
        while (i>r) del(arr[i--],s);
        while (j<l) del(arr[j++],s);
        while (j>l) add(arr[--j],s);
        while (t<tt) {
            ++t;
            if (mod[t].a>=j && mod[t].a<=i) {
                del(arr[mod[t].a],s);
                add(mod[t].b,s);
            }
            swap(arr[mod[t].a],mod[t].b);
        }
        while (t>tt) {
            if (mod[t].a>=j && mod[t].a<=i) {
                del(arr[mod[t].a],s);
                add(mod[t].b,s);
            }
            swap(arr[mod[t].a],mod[t].b);
            --t;
        }
        ans[id]=s;
    }
    for (int i=1;i<=cntq;++i) {
        printf("%lld\n",ans[i]);
    }
    return 0;
}