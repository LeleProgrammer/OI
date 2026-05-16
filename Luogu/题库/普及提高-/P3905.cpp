#include <bits/stdc++.h>

#define inf 1000000005

using namespace std;

const int N=105;
const int M=10005;

int n,m,a,b,c,S,E,d;
int I[N][N];
int G[N][N];

int main() {
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=n;++j) {
			I[i][j]=G[i][j]=inf;
		}
	}
	while (m--) {
		scanf("%d %d %d",&a,&b,&c);
		I[a][b]=I[b][a]=c;
		G[a][b]=G[b][a]=0;
	}
	scanf("%d",&d);
	while (d--) {
		scanf("%d %d",&a,&b);
		G[a][b]=G[b][a]=I[a][b];
	}
	scanf("%d %d",&S,&E);
	for (int k=1;k<=n;++k) {
		for (int i=1;i<=n;++i) {
			for (int j=1;j<=n;++j) {
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	printf("%d",G[S][E]);
	return 0;
}
