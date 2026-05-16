#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;

int n,m;
int arr[N];

struct SegmentTree {
	int l,r;
	int sum;
	int max;
} tr[N*4];

void pushup(int u) {
	tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
	tr[u].max=max(tr[u<<1].max,tr[u<<1|1].max);
}

void build(int u,int l,int r) {
	tr[u]={l,r,arr[l],arr[l]};
	if (l==r) return;
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}

void modify(int u,int l,int r,int x) {
	if (tr[u].max<x) return;
	if (tr[u].l==tr[u].r) {
		tr[u].sum=tr[u].sum%x;
		tr[u].max=tr[u].sum;
	} else {
		int mid=tr[u].l+tr[u].r>>1;
		if (l<=mid) modify(u<<1,l,r,x);
		if (r>mid) modify(u<<1|1,l,r,x);
		pushup(u);
	}
}

void change(int u,int k,int x) {
	if (tr[u].l==k && tr[u].r==k) {
		tr[u].sum=x;
		tr[u].max=x;
	} else {
		int mid=tr[u].l+tr[u].r>>1;
		if (k<=mid) change(u<<1,k,x);
		else change(u<<1|1,k,x);
		pushup(u);
	}
}

int query(int u,int l,int r) {
	if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
	int mid=tr[u].l+tr[u].r>>1;
	int ans=0;
	if (l<=mid) ans+=query(u<<1,l,r);
	if (r>mid) ans+=query(u<<1|1,l,r);
	return ans;
}

signed main() {
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;++i) {
		scanf("%lld",&arr[i]);
	}
	build(1,1,n);
	while (m--) {
		int op;
		scanf("%lld",&op);
		if (op==1) {
			int l,r;
			scanf("%lld %lld",&l,&r);
			printf("%lld\n",query(1,l,r));
		} else if (op==2) {
			int l,r,x;
			scanf("%lld %lld %lld",&l,&r,&x);
			modify(1,l,r,x);
		} else {
			int k,x;
			scanf("%lld %lld",&k,&x);
			change(1,k,x);
		}
	}
	return 0;
}