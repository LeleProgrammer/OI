#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int T,n,m,len;
int arr[N];
int cnt[N];
int ans[N];
vector<int> nums;

struct Query {
    int id,l,r,x;
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

void add(int x) {
    cnt[x]++;
}

void del(int x) {
    cnt[x]--;
}

int main() {
    scanf("%d",&T);
    while (T--) {
        memset(arr,0,sizeof(arr));
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        nums.clear();
        scanf("%d",&n);
        len=sqrt(n);
        for (int i=1;i<=n;++i) {
            scanf("%d",&arr[i]);
            nums.push_back(arr[i]);
        }
        scanf("%d",&m);
        for (int i=1;i<=m;++i) {
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            q[i]={i,l,r,x};
            nums.push_back(x);
        }
        sort(nums.begin(),nums.end(),cmp1);
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        for (int i=1;i<=n;++i) {
            arr[i]=lower_bound(nums.begin(),nums.end(),arr[i])-nums.begin();
        }
        for (int i=1;i<=m;++i) {
            q[i].x=lower_bound(nums.begin(),nums.end(),q[i].x)-nums.begin();
        }
        sort(q+1,q+1+m,cmp2);
        for (int k=0,i=0,j=1;k<=m;++k) {
            int id=q[k].id;
            int l=q[k].l;
            int r=q[k].r;
            int x=q[k].x;
            while (i<r) add(arr[++i]);
            while (i>r) del(arr[i--]);
            while (j<l) del(arr[j++]);
            while (j>l) add(arr[--j]);
            ans[id]=cnt[x];
        }
        for (int i=1;i<=m;++i) {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}