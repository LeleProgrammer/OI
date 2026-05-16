#include <bits/stdc++.h>
using namespace std;

const int N=30005;
const int M=200005;
const int K=1000005;

int n,m,len;
int w[N];
int cnt[K];
int ans[M];

struct Query {
    int id,l,r;
} q[M];

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
    if (!cnt[x]) s++;
    cnt[x]++;
}

void del(int x,int& s) {
    cnt[x]--;
    if (!cnt[x]) s--;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&w[i]);
    }
    scanf("%d",&m);
    for (int i=1;i<=m;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        q[i]={i,a,b};
    }
    len=sqrt(n);
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
        printf("%d\n",ans[i]);
    }
    return 0;
}