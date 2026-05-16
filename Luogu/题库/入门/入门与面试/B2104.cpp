#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[105][105];

int main() {
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=m;++j) {
			scanf("%d",&arr[i][j]);
		}
	}
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=m;++j) {
			int a;
			scanf("%d",&a);
			arr[i][j]+=a;
		}
	}
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=m;++j) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}