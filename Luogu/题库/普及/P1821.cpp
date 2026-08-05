#include <bits/stdc++.h>
using namespace std;

const int N=1005;

typedef pair<int,int> pii;

int n,m,x,u,v,w;
int G[N][N];
int dis[N];
bool check[N];
int ans[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

void dijkstra(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(check,0,sizeof(check));
	dis[s]=0;
	q.push(make_pair(dis[s],s));
	while (!q.empty()) {
		auto tp=q.top();
		int curr=tp.second;
		q.pop();
		check[curr]=true;
		for (int i=1;i<=n;++i) {
			if (dis[i]>dis[curr]+G[curr][i]) {
				dis[i]=dis[curr]+G[curr][i];
				q.push(make_pair(dis[i],i));
			}
		}
	}
}

int main() {
	memset(G,0x3f,sizeof(G));
	scanf("%d %d %d",&n,&m,&x);
	while (m--) {
		scanf("%d %d %d",&u,&v,&w);
		G[u][v]=min(G[u][v],w);
	}
	for (int i=1;i<=n;++i) {
		if (i==x) continue;
		dijkstra(i);
		ans[i]=dis[x];
	}
	dijkstra(x);
	for (int i=1;i<=n;++i) {
		ans[i]+=dis[i];
	}
	int res=0;
	for (int i=1;i<=n;++i) {
		res=max(res,ans[i]);
	}
	printf("%d",res);
	return 0;
}
