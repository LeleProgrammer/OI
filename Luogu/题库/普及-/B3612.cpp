#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int pre[100005];

int main() {
	int n;
	scanf("%d",&n);
	pre[0]=0;
	for (int i=1;i<=n;++i) {
		scanf("%d",arr+i);
		pre[i]=pre[i-1]+arr[i];
	}
	int m;
	scanf("%d",&m);
	for (int i=1;i<=m;++i) {
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",pre[r]-pre[l-1]);
	}
	return 0;
}