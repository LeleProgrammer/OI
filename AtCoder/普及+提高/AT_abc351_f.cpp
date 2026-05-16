#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long

const int N=400005;

int n;
int arr[N];
vector<int> nums;
int ans;

struct SegmentTree {
    int l,r;
    int sum;
    int cnt;
} tr[N<<2];

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].cnt=tr[u<<1].cnt+tr[u<<1|1].cnt;
}

void build(int u,int l,int r) {
    tr[u]={l,r,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int p,int k) {
    if (tr[u].l==p && tr[u].r==p) tr[u].sum+=k,tr[u].cnt++;
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if (p<=mid) modify(u<<1,p,k);
        else modify(u<<1|1,p,k);
        pushup(u);
    }
}

pair<int,int> query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return {tr[u].sum,tr[u].cnt};
    int mid=tr[u].l+tr[u].r>>1;
    pair<int,int> ans={0,0};
    if (l<=mid) {
        auto t=query(u<<1,l,r);
        ans.first+=t.first;
        ans.second+=t.second;
    }
    if (r>mid) {
        auto t=query(u<<1|1,l,r);
        ans.first+=t.first;
        ans.second+=t.second;
    }
    return ans;
}

signed main() {
    scanf("%lld",&n);
    build(1,1,n);
    _rep(i,1,n) scanf("%lld",&arr[i]),nums.push_back(arr[i]);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    _rep(i,1,n) arr[i]=lower_bound(nums.begin(),nums.end(),arr[i])-nums.begin()+1;
    _rep(i,1,n) {
        if (arr[i]!=1) {
            auto t=query(1,1,arr[i]-1);
            ans+=nums[arr[i]-1]*t.second-t.first;
        }
        modify(1,arr[i],nums[arr[i]-1]);
    }
    printf("%lld",ans);
    return 0;
}