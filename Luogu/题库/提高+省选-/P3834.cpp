#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int M=200005;

int n,m;
int a[N];
vector<int> nums;
int tot;
int l,r,k;
int root[N];

struct node {
    int l;
    int r;
    int cnt;
} tr[N*4+N*20];

void pushup(int curr) {
    tr[curr].cnt=tr[tr[curr].l].cnt+tr[tr[curr].r].cnt;
}

int find(int x) {
    return lower_bound(nums.begin(),nums.end(),x)-nums.begin();
}

int build(int l,int r) {
    int curr=++tot;
    if (l==r) return curr;
    int mid=l+r>>1;
    tr[curr].l=build(l,mid);
    tr[curr].r=build(mid+1,r);
    return curr;
}

int insert(int p,int l,int r,int k) {
    int curr=++tot;
    tr[curr]=tr[p];
    if (l==r) tr[curr].cnt++;
    else {
        int mid=l+r>>1;
        if (k<=mid) tr[curr].l=insert(tr[p].l,l,mid,k);
        else tr[curr].r=insert(tr[p].r,mid+1,r,k);
        pushup(curr);
    }
    return curr;
}

int query(int p,int curr,int l,int r,int k) {
    if (l==r) return l;
    int mid=l+r>>1;
    int left=tr[tr[curr].l].cnt-tr[tr[p].l].cnt;
    if (k>left) return query(tr[p].r,tr[curr].r,mid+1,r,k-left);
    else return query(tr[p].l,tr[curr].l,l,mid,k);
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]),nums.push_back(a[i]);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    root[0]=build(0,nums.size()-1);
    for (int i=1;i<=n;++i) root[i]=insert(root[i-1],0,nums.size()-1,find(a[i]));
    while (m--) {
        scanf("%d %d %d",&l,&r,&k);
        printf("%d\n",nums[query(root[l-1],root[r],0,nums.size()-1,k)]);
    }
    return 0;
}