#include <bits/stdc++.h>

#define inf 1000000000000000000LL
#define int long long

using namespace std;

const int N=4000005;

int n,q;
int a[N];
int op,l,r,x;

struct node {
	int l,r;
	int max;
	int cha,add; // lazytag
} tr[N];

void pushup(int u) {
	tr[u].max=max(tr[u<<1].max,tr[u<<1|1].max);
}

void pushdown(int u) {
	auto &root=tr[u],&right=tr[u<<1|1],&left=tr[u<<1];
	if (root.cha!=inf) {
		right.cha=root.cha;
		left.cha=root.cha;
		right.max=root.cha;
		left.max=root.cha;
		left.add=0;
		right.add=0;
		root.cha=inf;
	}
	if (root.add) {
		right.add+=root.add;
		left.add+=root.add;
		right.max+=root.add;
		left.max+=root.add;
		root.add=0;
	}
}

void build(int u,int l,int r) {
	if (l==r) tr[u]={l,r,a[l],inf,0};
	else {
		tr[u]={l,r,a[l],inf,0};
		int mid=l+r>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		pushup(u);
	}
}

void addition(int u,int l,int r,int k) {
	if (tr[u].l>=l && tr[u].r<=r) {
		tr[u].add+=k;
		tr[u].max+=k;
	} else {
		int mid=tr[u].l+tr[u].r>>1;
		pushdown(u);
		if (l<=mid) addition(u<<1,l,r,k);
		if (r>=mid+1) addition(u<<1|1,l,r,k);
		pushup(u);
	}
}

void modify(int u,int l,int r,int k) {
	if (tr[u].l>=l && tr[u].r<=r) {
		tr[u].cha=k;
		tr[u].max=k;
		tr[u].add=0;
	} else {
		int mid=tr[u].l+tr[u].r>>1;
		pushdown(u);
		if (l<=mid) modify(u<<1,l,r,k);
		if (r>=mid+1) modify(u<<1|1,l,r,k);
		pushup(u);
	}
}

int query(int u,int l,int r) {
	if (tr[u].l>=l && tr[u].r<=r) {
		return tr[u].max;
	} else {
		int mid=tr[u].l+tr[u].r>>1;
		pushdown(u);
		int ans=-inf;
		if (l<=mid) ans=query(u<<1,l,r);
		if (r>=mid+1) ans=max(ans,query(u<<1|1,l,r));
		return ans;
	}
}

signed main() {
	scanf("%lld %lld",&n,&q);
	for (int i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
	while (q--) {
		scanf("%lld %lld %lld",&op,&l,&r);
		if (op==1) {
			scanf("%lld",&x);
			modify(1,l,r,x);
		} else if (op==2) {
			scanf("%lld",&x);
			addition(1,l,r,x);
		} else {
			printf("%lld\n",query(1,l,r));
		}
	}
	return 0;
}