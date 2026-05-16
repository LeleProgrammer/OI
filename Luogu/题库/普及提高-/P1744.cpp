#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;

const int N=105;
const int M=2005;

typedef pair<double,int> pdi;

int n,m,a,b,S,E;
int e[M],ne[M],h[N],tot;
double w[M];
double dis[N];
bool check[N];
priority_queue< pdi,vector<pdi>,greater<pdi> > q;

double x[N],y[N];

void add(int a,int b,double c) {
	e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

double get_dis(int a,int b) {
	return sqrt(pow(abs(x[a]-x[b]),2.0)+pow(abs(y[a]-y[b]),2.0));
}

void dijkstra(int s) {
	for (int i=1;i<=n;++i) dis[i]=inf,check[i]=false;
	dis[s]=0;
	q.push(make_pair(dis[s],s));
	while (!q.empty()) {
		auto tp=q.top(); q.pop();
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

int main() {
	memset(h,-1,sizeof(h));
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		scanf("%lf %lf",x+i,y+i);
	}
	scanf("%d",&m);
	while (m--) {
		scanf("%d %d",&a,&b);
		add(a,b,get_dis(a,b));
		add(b,a,get_dis(b,a));
	}
	scanf("%d %d",&S,&E);
	dijkstra(S);
	printf("%.2lf",dis[E]);
	return 0;
}
