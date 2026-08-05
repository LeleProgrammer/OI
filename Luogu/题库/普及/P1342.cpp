#include <bits/stdc++.h>

#define int long long
#define inf 1000000000000000000LL

using namespace std;

const int N=1000005;
const int M=1000005;

int n,m;
int e[M],ne[M],w[M],h[N],tot;
int e2[M],ne2[M],w2[M],h2[N],tot2;
int a,b,c;
int dis1[N],dis2[N];
bool check1[N],check2[N];

typedef pair<int,int> pii;

priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b,int c) {
	e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void add2(int a,int b,int c) {
	e2[tot2]=b,w2[tot2]=c,ne2[tot2]=h2[a],h2[a]=tot2++;
}

void dijkstra_1() {
	for (int i=1;i<=n;++i) dis1[i]=inf,check1[i]=false;
	dis1[1]=0;
	q.push(make_pair(dis1[1],1));
	while (!q.empty()) {
		auto tp=q.top(); q.pop();
		int curr=tp.second;
		check1[curr]=true;
		for (int i=h[curr];~i;i=ne[i]) {
			if (dis1[e[i]]>dis1[curr]+w[i] && !check1[e[i]]) {
				dis1[e[i]]=dis1[curr]+w[i];
				q.push(make_pair(dis1[e[i]],e[i]));
			}
		}
	}
}

void dijkstra_2() {
	for (int i=1;i<=n;++i) dis2[i]=inf,check2[i]=false;
	dis2[1]=0;
	q.push(make_pair(dis2[1],1));
	while (!q.empty()) {
		auto tp=q.top(); q.pop();
		int curr=tp.second;
		check2[curr]=true;
		for (int i=h2[curr];~i;i=ne2[i]) {
			if (dis2[e2[i]]>dis2[curr]+w2[i] && !check2[e2[i]]) {
				dis2[e2[i]]=dis2[curr]+w2[i];
				q.push(make_pair(dis2[e2[i]],e2[i]));
			}
		}
	}
}

signed main() {
	memset(h,-1,sizeof(h));
	memset(h2,-1,sizeof(h2));
	scanf("%lld %lld",&n,&m);
	while (m--) {
		scanf("%lld %lld %lld",&a,&b,&c);
		add(a,b,c); add2(b,a,c);
	}
	dijkstra_1();
	dijkstra_2();
	int ans=0;
	for (int i=1;i<=n;++i) {
		ans+=dis1[i]+dis2[i];
	}
	printf("%lld",ans);
	return 0;
}
