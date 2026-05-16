#include <bits/stdc++.h>
using namespace std;

const int N=500005;

int n,m,len;
int w[N];
int cnt[N];
int ans[N];
vector<int> nums;

struct Query {
    int id,l,r;
} q[N];

int get(int x) {
    return x/len;
}

bool cmp1(const int& a,const int& b) {
    return a<b;
}

bool cmp2(const Query& a,const Query& b) {
    int al=get(a.l);
    int bl=get(b.l);
    if (al!=bl) return al<bl;
    return a.r<b.r;
}

void add(int x,int& s) {
    if (cnt[x]==2) s--;
    cnt[x]++;
    if (cnt[x]==2) s++;
}

void del(int x,int& s) {
    if (cnt[x]==2) s--;
    cnt[x]--;
    if (cnt[x]==2) s++;
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&w[i]);
        nums.push_back(w[i]);
    }
    len=sqrt(n);
    sort(nums.begin(),nums.end(),cmp1);
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for (int i=1;i<=m;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        q[i]={i,a,b};
    }
    sort(q+1,q+1+m,cmp2);
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