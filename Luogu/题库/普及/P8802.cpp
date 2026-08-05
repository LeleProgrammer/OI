#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int n,m,u,v,c;
int C[1005];
int G[1005][1005];
int dis[1005];
bool check[1005];

void dijkstra() {
	memset(dis,0x3f,sizeof(dis));
	memset(check,false,sizeof(check));
	dis[1]=0;
	for (int i=1;i<=n;++i) {
		int minn=inf,mini;
		for (int j=1;j<=n;++j) {
			if ((!check[j]) && dis[j]<minn) {
				minn=dis[j];
				mini=j;
			}
		}
		check[mini]=true;
		for (int j=1;j<=n;++j) {
			if ((!check[j]) && dis[j]>dis[mini]+G[mini][j]+C[j] && G[mini][j]) {
				dis[j]=dis[mini]+G[mini][j]+C[j];
			}
		}
	}
}

int main() {
	memset(C,0,sizeof(C));
	memset(G,0,sizeof(G));
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;++i) {
		scanf("%d",C+i);
	}
	for (int i=1;i<=m;++i) {
		scanf("%d %d %d",&u,&v,&c);
		G[u][v]=G[v][u]=c;
	}
	dijkstra();
	printf("%d",dis[n]-C[n]);
	return 0;
}