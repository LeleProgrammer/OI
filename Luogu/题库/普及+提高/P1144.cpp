#include <bits/stdc++.h>
using namespace std;

const int N=1000005;
const int M=4000005;
const int mod=100003;

typedef pair<int,int> pii;

int n,m,u,v;
int e[M],ne[M],w[M],h[N],tot;
int dis[N],cnt[N];
bool check[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b,int c) {
	e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	dis[s]=0; cnt[1]=1;
	q.push(make_pair(dis[s],s));
	while (!q.empty()) {
		auto tp=q.top();
		q.pop();
		int curr=tp.second;
		check[curr]=true;
		for (int i=h[curr];~i;i=ne[i]) {
			if (dis[e[i]]>dis[curr]+w[i]) {
				dis[e[i]]=dis[curr]+w[i];
				q.push(make_pair(dis[e[i]],e[i]));
			}
			if (dis[e[i]]==dis[curr]+w[i]) {
				cnt[e[i]]+=cnt[curr];
				cnt[e[i]]%=mod;
			}
		}
	}
}

int main() {
	memset(h,-1,sizeof(h));
	scanf("%d %d",&n,&m);
	while (m--) {
		scanf("%d %d",&u,&v);
		add(u,v,1); add(v,u,1);
	}
	dijkstra(1);
	for (int i=1;i<=n;++i) {
		printf("%d\n",cnt[i]);
	}
	return 0;
}
