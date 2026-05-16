#include <bits/stdc++.h>

#define int long long
#define inf 1000000000000000000

using namespace std;

const int N=1005;
const int M=1005;

typedef pair<int,int> pii;

int n,m;
int e[M],ne[M],w[M],h[N],tot;
string u,v;
int ww;
map<string,int> dc;
int cnt;
int Q;
int dis[N];
bool check[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b,int c) {
	e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

int gett(string s) {
	map<string,int>::iterator iter=dc.find(s);
	if (iter==dc.end()) {
		dc.insert(make_pair(s,++cnt));
	}
	return dc[s];
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

signed main() {
	memset(h,-1,sizeof(h));
	scanf("%lld %lld",&n,&m);
	while (m--) {
		cin>>u>>v;
		scanf("%d",&ww);
		add(gett(u),gett(v),ww);
	}
	scanf("%lld",&Q);
	while (Q--) {
		cin>>u>>v;
		dijkstra(gett(u));
		int it=gett(v);
		if (dis[it]==inf) puts("Roger");
		else printf("%lld\n",dis[it]);
	}
	return 0;
}
