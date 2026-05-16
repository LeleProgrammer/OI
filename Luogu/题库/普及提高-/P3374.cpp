#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,m,op,x,y,k,read;
int tree[500005];

int lowbit(int x) {
	return x&(-x);
}

int query(int x) {
	int result=0;
	for (;x>0;x-=lowbit(x)) result+=tree[x];
	return result;
}

void add(int x,int d) {
	for (;x<=n;x+=lowbit(x)) tree[x]+=d;
	return ;
}

signed main() {
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;++i) {
		scanf("%lld",&read);
		add(i,read);
	}
	for (int i=1;i<=m;++i) {
		scanf("%lld",&op);
		if (op==1) {
			scanf("%lld %lld",&x,&k);
			add(x,k);
		} else {
			scanf("%lld %lld",&x,&y);
			printf("%lld\n",query(y)-query(x-1));
		}
	}
	return 0;
}