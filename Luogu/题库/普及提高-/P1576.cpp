#include <bits/stdc++.h>
using namespace std;

const int N=2005;
const int M=200005;

typedef pair<int,int> pii;

int n,m,x,y,a,b;
double z;
int e[M],ne[M],h[N],tot;
double w[M];
double dis[N];
bool check[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b,double c) {
	e[tot]=b,ne[tot]=h[a],w[tot]=c,h[a]=tot++;
}

void dijkstra() {
	for (int i=1;i<=n;++i) {
		dis[i]=2147483647-100;
	}
	memset(check,0,sizeof(check));
	dis[a]=100.0;
	q.push(make_pair(dis[a],a));
	while (!q.empty()) {
		auto tp=q.top();
		q.pop();
		int curr=tp.second;
		check[curr]=true;
		for (int i=h[curr];~i;i=ne[i]) {
			if (dis[e[i]]>dis[curr]*w[i] && !check[e[i]]) {
				dis[e[i]]=dis[curr]*w[i];
				q.push(make_pair(dis[e[i]],e[i]));
			}
		}
	}
}

int main() {
	memset(h,-1,sizeof(h));
	scanf("%d %d",&n,&m);
	while (m--) {
		scanf("%d %d %lf",&x,&y,&z);
		z/=100.0; z=1.0-z; z=1.0/z;
		add(x,y,z); add(y,x,z);
	}
	scanf("%d %d",&a,&b);
	dijkstra();
	printf("%.8lf",dis[b]);
	return 0;
} 
