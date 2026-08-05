#include <bits/stdc++.h>
using namespace std;

const int N=250005;
const int M=1000005;

typedef pair<int,int> pii;

int n,m;
int e[M],ne[M],w[M],h[N],tot;
int arr[N];
char c;
int S,E;
int dis[N];
bool check[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b,int c) {
	e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra() {
	memset(dis,0x3f,sizeof(dis));
	memset(check,0,sizeof(check));
	dis[S]=0;
	q.push(make_pair(dis[S],S));
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
	while (scanf("%d %d",&m,&n),n) {
		memset(h,-1,sizeof(h));
		for (int i=1;i<=n*m;++i) {
			scanf(" %c",&c);
			if (c=='@') arr[i]=0;
			else arr[i]=1;
		}
		for (int i=0;i<m;++i) {
			for (int j=1;j<=n;++j) {
				if (i) add(i*n+j,(i-1)*n+j,arr[i*n+j]!=arr[(i-1)*n+j]);
				if (j!=1) add(i*n+j,i*n+j-1,arr[i*n+j]!=arr[i*n+j-1]);
				if (i!=n-1) add(i*n+j,(i+1)*n+j,arr[i*n+j]!=arr[(i+1)*n+j]);
				if (j!=n) add(i*n+j,i*n+j+1,arr[i*n+j]!=arr[i*n+j+1]);
			}
		}
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		S=a*n+b+1,E=c*n+d+1;
		dijkstra();
		printf("%d\n",dis[E]);
	}
	return 0;
} 
