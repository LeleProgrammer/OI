#include <bits/stdc++.h>
using namespace std;

const int N=300005;
const int M=100005;

int n,c,m,len;
int w[N];
int ans[M];
int cnt[M];

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
    cnt[x]++;
    if (cnt[x]>cnt[s]) s=x;
}

void rec(int id,int l,int r,int x) {
    if (cnt[x]<=(r-l+1)/2) {
        ans[id]=0;
    } else {
        ans[id]=x;
    }
}

int main() {
    scanf("%d %d",&n,&c);
    len=sqrt(n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&w[i]);
    }
    scanf("%d",&m);
    for (int i=1;i<=m;++i) {
        int l,r;
        scanf("%d %d",&l,&r);
        q[i]={i,l,r};
    }
    sort(q+1,q+1+m,cmp);
    int x=1;
    while (x<=m) {
        int y=x;
        while (y<=m && get(q[x].l)==get(q[y].l)) ++y;
        int right=get(q[x].l)*len+len-1;
        while (x<y && get(q[x].l)==get(q[x].r)) {
            int id=q[x].id;
            int l=q[x].l;
            int r=q[x].r;
            int s=0;
            for (int i=l;i<=r;++i) {
                add(w[i],s);
            }
            rec(id,l,r,s);
            for (int i=l;i<=r;++i) {
                cnt[w[i]]--;
            }
            ++x;
        }
        int i=right;
        int j=right+1;
        int s=0;
        while (x<y) {
            int id=q[x].id;
            int l=q[x].l;
            int r=q[x].r;
            while (i<r) add(w[++i],s);
            int backup=s;
            while (j>l) add(w[--j],s);
            rec(id,l,r,s);
            while (j<right+1) cnt[w[j++]]--;
            s=backup;
            ++x;
        }
        for (int i=1;i<=c;++i) cnt[i]=0;
    }
    for (int i=1;i<=m;++i) {
        if (ans[i]) printf("yes %d\n",ans[i]);
        else puts("no");
    }
    return 0;
}