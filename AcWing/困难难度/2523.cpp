#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=100005;

int n,m,len;
int arr[N];
int cnt[M];
int ans[M];
vector<int> nums;

struct Query {
    int id,l,r;
} q[M];

int get(int x) {
    return x/len;
}

bool cmp1(const int& a,const int& b) {
    return a<b;
}

bool cmp2(const Query& a,const Query& b) {
    int al,bl;
    al=get(a.l);
    bl=get(b.l);
    if (al!=bl) return al<bl;
    return a.r<b.r;
}

void add(int x,int& res) {
    cnt[x]++;
    res=max(res,cnt[x]*nums[x]);
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
        nums.push_back(arr[i]);
    }
    sort(nums.begin(),nums.end(),cmp1);
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for (int i=1;i<=n;++i) {
        arr[i]=lower_bound(nums.begin(),nums.end(),arr[i])-nums.begin();
    }
    len=sqrt(n);
    for (int i=1;i<=m;++i) {
        int l,r;
        scanf("%lld %lld",&l,&r);
        q[i]={i,l,r};
    }
    sort(q+1,q+1+m,cmp2);
    int x=1;
    while (x<=m) {
        int y=x;
        while (y<=m && get(q[y].l)==get(q[x].l)) ++y;
        int right=get(q[x].l)*len+len-1;
        while (x<y && q[x].r<=right) {
            int id=q[x].id;
            int l=q[x].l;
            int r=q[x].r;
            int s=0;
            for (int k=l;k<=r;++k) {
                add(arr[k],s);
            }
            ans[id]=s;
            for (int k=l;k<=r;++k) {
                cnt[arr[k]]--;
            }
            ++x;
        }
        int s=0;
        int i=right;
        int j=right+1;
        while (x<y) {
            int id=q[x].id;
            int l=q[x].l;
            int r=q[x].r;
            while (i<r) add(arr[++i],s);
            int last=s;
            while (j>l) add(arr[--j],s);
            ans[id]=s;
            while (j<right+1) cnt[arr[j++]]--;
            s=last;
            ++x;
        }
        memset(cnt,0,sizeof(cnt));
    }
    for (int i=1;i<=m;++i) {
        printf("%lld\n",ans[i]);
    }
    return 0;
}