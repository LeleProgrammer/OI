#include <bits/stdc++.h>
using namespace std;

const int N=105;
const int M=20005;

typedef pair<int,int> pii;

int s[8];
int hs[8]={0,2,6,4,8,6,10,14};
int a,b,m;
int e[M],w[M],ne[M],h[N],tot;
int x,y,z;
int dis[N];
bool check[N];

void add(int a,int b,int c) {
	e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

priority_queue< pii,vector<pii>,greater<pii> > q;

void dijkstra() {
	memset(dis,0x3f,sizeof(dis));
	memset(check,0,sizeof(check));
	dis[a]=0;
	q.push(make_pair(dis[a],a));
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
	for (int i=1;i<=7;++i) scanf("%d",&s[i]);
	for (int i=1;i<=7;++i) if (s[i]) hs[i]/=2;
	memset(h,-1,sizeof(h));
	scanf("%d %d",&a,&b);
	scanf("%d",&m);
	while (m--) {
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,hs[z]); add(y,x,hs[z]);
	}
	dijkstra();
	printf("%d",dis[b]);
	return 0;
}
