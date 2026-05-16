#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,T;
int v[100005],t[100005];
int h[100005];

signed main() {
	scanf("%lld %lld",&n,&T);
	memset(h,0,sizeof h);
	for (int i=1;i<=n;++i) {
		scanf("%lld %lld",&v[i],&t[i]);
	}
	int maxx=-1;
	int number=1;
	for (int i=1;i<=n;++i) {
		for (int j=t[i]+1;j<=T;++j) {
			h[i]+=v[i];
		}
		if (h[i]>maxx) {
			maxx=h[i];
			number=i;
		}
	}
	printf("%lld",number);
//	for (int i=1;i<=T;++i) {
//		maxx=-1;
//		for (int j=1;j<=n;++j) {
////			cout<<h[j]<<" ";
//			if (i>t[j]) {
//				h[j]+=v[j];
//			}
//			if (h[j]>maxx) {
//				maxx=h[j];
//				number=j;
//			}
//		}
////		cout<<endl;
//	}
	return 0;
}