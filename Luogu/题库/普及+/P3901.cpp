#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n,m;
int len;
int cnt[N];
bool ans[N];
int arr[N];

int get(int x) {
    return x/len;
}

struct Query {
    int id,l,r;
} q[N];

bool cmp(const Query& a,const Query& b) {
    int al=get(a.l);
    int ar=get(a.r);
    int bl=get(b.l);
    int br=get(b.r);
    if (al!=bl) return al<bl;
    return ar<br;
}

void add(int x,int& res) {
    if (!cnt[x]) ++res;
    cnt[x]++;
}

void del(int x,int& res) {
    cnt[x]--;
    if (!cnt[x]) --res;
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&arr[i]);
    len=sqrt(n);
    for (int i=1;i<=m;++i) {
        int l,r;
        scanf("%d %d",&l,&r);
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
        ans[id]=s==i-j+1;
    }
    for (int i=1;i<=m;++i) {
        printf(ans[i]?"Yes":"No");
        putchar(10);
    }
    return 0;
}