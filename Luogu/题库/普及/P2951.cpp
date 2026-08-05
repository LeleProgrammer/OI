#include <bits/stdc++.h>
using namespace std;

const int N=20005;
const int M=100005;

typedef pair<int,int> pii;

int n,m,u,v;
int e[M],ne[M],h[N],tot;
int dis[N];
bool check[N];
priority_queue< pii,vector<pii>,greater<pii> > q;
int ans1,ans2,ans3;

void add(int a,int b) {
	e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(check,0,sizeof(check));
	dis[s]=0;
	q.push(make_pair(dis[s],s));
	while (!q.empty()) {
		auto tp=q.top(); q.pop();
		int curr=tp.second;
		check[curr]=true;
		for (int i=h[curr];~i;i=ne[i]) {
			if (dis[e[i]]>dis[curr]+1 && !check[e[i]]) {
				dis[e[i]]=dis[curr]+1;
				q.push(make_pair(dis[e[i]],e[i]));
			}
		}
	}
}

int main() {
	memset(h,-1,sizeof(h));
	scanf("%d %d",&n,&m);
	while (m--) {
		scanf("%d %d",&u,&v);
		add(u,v);add(v,u);
	}
	dijkstra(1);
	ans1=-1;
	for (int i=1;i<=n;++i) {
		if (dis[i]>ans1) {
			ans1=dis[i];
			ans2=i;
			ans3=1;
		} else if (dis[i]==ans1) {
			ans3++;
		}
	}
	printf("%d %d %d",ans2,ans1,ans3);
	return 0;
}
