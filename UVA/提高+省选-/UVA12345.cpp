#include <bits/stdc++.h>
using namespace std;

const int N=50005;
const int M=1000005;

int n,m,len,cntq,cntm;
int w[N];
int cnt[M];
int ans[N];

struct Query {
    int id,l,r,t;
} q[N];

struct Modify {
    int a,b;
} mod[N];

int get(int x) {
    return x/len;
}

bool cmp(const Query& a,const Query& b) {
    int al=get(a.l),bl=get(b.l);
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
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&w[i]);
    len=sqrt(n);
    for (int i=1;i<=m;++i) {
        char op[2];
        int a,b;
        scanf("%s %d %d",op,&a,&b);
        ++a;
        if (*op=='Q') {
            ++cntq;
            q[cntq]={cntq,a,b,cntm};
        } else {
            mod[++cntm]={a,b};
        }
    }
    sort(q+1,q+1+cntq,cmp);
    for (int k=1,i=0,j=1,t=0,s=0;k<=cntq;++k) {
        int id=q[k].id;
        int l=q[k].l;
        int r=q[k].r;
        int tt=q[k].t;
        while (i<r) add(w[++i],s);
        while (i>r) del(w[i--],s);
        while (j<l) del(w[j++],s);
        while (j>l) add(w[--j],s);
        while (t<tt) {
            ++t;
            if (mod[t].a>=l && mod[t].a<=r) {
                del(w[mod[t].a],s);
                add(mod[t].b,s);
            }
            swap(w[mod[t].a],mod[t].b);
        }
        while (t>tt) {
            if (mod[t].a>=l && mod[t].a<=r) {
                del(w[mod[t].a],s);
                add(mod[t].b,s);
            }
            swap(w[mod[t].a],mod[t].b);
            --t;
        }
        ans[id]=s;
    }
    for (int i=1;i<=cntq;++i) {
        printf("%d\n",ans[i]);
    }
    return 0;
}