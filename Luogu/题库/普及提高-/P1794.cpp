#include <bits/stdc++.h>
using namespace std;

int v,g,n;
int value[505];
int room[505];
int weight[505];
int f[505][505];
int ans=0;

int main() {
	scanf("%d %d",&v,&g);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		scanf("%d %d %d",value+i,room+i,weight+i);
	}
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;++i) {
		for (int j=v;j>=room[i];--j) {
			for (int k=g;k>=weight[i];--k) {
				f[j][k]=max(f[j][k],f[j-room[i]][k-weight[i]]+value[i]);
				ans=max(ans,f[j][k]);
			}
		}
	}
	printf("%d",ans);
	return 0;
}