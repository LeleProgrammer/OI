#include <bits/stdc++.h>

#define int long long
#define inf 1000000000000000000LL

using namespace std;

const int N=305;
const int M=25005;

int n,m,t,u,v,ww,a,b;
int G[N][N];

void floyd() {
	for (int k=1;k<=n;++k) {
		for (int i=1;i<=n;++i) {
			for (int j=1;j<=n;++j) {
				G[i][j]=min(G[i][j],max(G[i][k],G[k][j]));
			}
		}
	}
}

signed main() {
	scanf("%lld %lld %lld",&n,&m,&t);
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=n;++j) {
			G[i][j]=inf;
		}
	}
	while (m--) {
		scanf("%lld %lld %lld",&u,&v,&ww);
		G[u][v]=ww;
	}
	floyd();
	while (t--) {
		scanf("%lld %lld",&a,&b);
		printf("%lld\n",G[a][b]==inf?-1:G[a][b]);
	}
	return 0;
}
