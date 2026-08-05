#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,m,op,x,y,k,last,read;
int tree[500005];

int lowbit(int x) {
	return x&(-x);
}

int query(int x) {
	int result=0;
	while (x>0) {
		result+=tree[x];
		x-=lowbit(x);
	}
	return result;
}

void add(int x,int d) {
	while (x<=n) {
		tree[x]+=d;
		x+=lowbit(x);
	}
	return ;
}

signed main() {
	scanf("%lld %lld",&n,&m);
	last=0;
	for (int i=1;i<=n;++i) {
		scanf("%lld",&read);
		add(i,read-last);
		last=read;
	}
	for (int i=1;i<=m;++i) {
		scanf("%lld",&op);
		if (op==1) {
			scanf("%lld %lld %lld",&x,&y,&k);
			add(x,k);add(y+1,-k);
		} else {
			scanf("%lld",&x);
			printf("%lld\n",query(x));
		}
	}
	return 0;
}