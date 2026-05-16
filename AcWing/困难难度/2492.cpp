#include <bits/stdc++.h>
using namespace std;

const int N=50005;
const int M=200005;
const int K=1000005;

int n,m,len;
int a[N];
int ans[M];
int cnt[K];

int get(int x) {
    return x/len;
}

struct Query {
    int id,l,r;
} q[M];

bool cmp(const Query& a,const Query& b) {
    int i,j;
    i=get(a.l);
    j=get(b.l);
    if (i!=j) return i<j;
    return a.r<b.r;
}

void add(int x,int& ans) {
    if (!cnt[x]) ans++;
    cnt[x]++;
}

void del(int x,int& ans) {
    if (cnt[x]==1) ans--;
    cnt[x]--;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    len=sqrt(n);
    for (int i=0;i<m;++i) {
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q,q+m,cmp);
    for (int k=0,i=0,j=1,s=0;k<m;++k) {
        auto t=q[k];
        int id=t.id;
        int l=t.l;
        int r=t.r;
        while (i<r) add(a[++i],s);
        while (i>r) del(a[i--],s);
        while (j<l) del(a[j++],s);
        while (j>l) add(a[--j],s);
        ans[id]=s;
    }
    for (int i=0;i<m;++i) {
        printf("%d\n",ans[i]);
    }
    return 0;
}