#include <bits/stdc++.h>

#define int long long
#define inf 1000000000000000000

using namespace std;

const int N=100005;
const int M=200005;

typedef pair<int,int> pii;

int n,m;
int a,b,c;
int e[M],ne[M],w[M],h[N],tot;
int dis[N];
bool check[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b,int c) {
	e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s) {
	for (int i=1;i<=n;++i) dis[i]=inf,check[i]=false;
	dis[s]=0;
	q.push(make_pair(dis[s],s));
	while (!q.empty()) {
		auto tp=q.top();
		q.pop();
		int curr=tp.second;
		check[curr]=true;
		for (int i=h[curr];~i;i=ne[i]) {
			if (dis[e[i]]>dis[curr]+w[i] && !check[e[i]]) {
				dis[e[i]]=dis[curr]+w[i];
				q.push(make_pair(dis[e[i]],e[i]));
			}
		}
	}
}

void print(int u) {
	if (u==1) {
		printf("%lld ",u);
		return;
	}
	for (int i=h[u];~i;i=ne[i]) {
		if (dis[u]==dis[e[i]]+w[i]) {
			print(e[i]);
			printf("%lld ",u);
			return;
		}
	}
}

signed main() {
	memset(h,-1,sizeof(h));
	scanf("%lld %lld",&n,&m);
	while (m--) {
		scanf("%lld %lld %lld",&a,&b,&c);
		add(a,b,c); add(b,a,c);
	}
	dijkstra(1);
	if (dis[n]==inf) puts("-1");
	else print(n);
	return 0;
}
