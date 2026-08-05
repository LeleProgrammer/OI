#include <bits/stdc++.h>
using namespace std;

const int M=20005;
const int N=155;

typedef pair<int,int> pii;

int p;
char u,v;
int ww;
vector<int> cows;
int dis[N];
bool check[N];
int G[N][N];
int ans1,ans2=0x7fffffff;
priority_queue< pii,vector<pii>,greater<pii> > q;

void dijkstra(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(check,0,sizeof(check));
	dis[s]=0;
	q.push(make_pair(dis[s],s));
	while (!q.empty()) {
		auto pa=q.top();
		q.pop();
		int k=pa.second;
		int d=pa.first;
		check[k]=true;
		for (int j=0;j<='z';++j) {
			if (dis[j]>dis[k]+G[k][j] && !check[j]) {
				dis[j]=dis[k]+G[k][j];
				q.push(make_pair(dis[j],j));
			}
		}
	}
}

int main() {
	memset(G,0x3f,sizeof(G));
	scanf("%d",&p);
	while (p--) {
		scanf(" %c %c %d",&u,&v,&ww);
		if (isupper(u) && u!='Z') {
			cows.push_back(u);
		}
		if (isupper(v) && v!='Z') {
			cows.push_back(v);
		}
		G[u][v]=G[v][u]=min(G[u][v],ww);
	}
	for (int cow:cows) {
		dijkstra(cow);
		if (dis['Z']<ans2) {
			ans2=dis['Z'];
			ans1=cow;
		}
	}
	printf("%c %d",char(ans1),ans2);
	return 0;
}
