#include <bits/stdc++.h>
using namespace std;

const int N=155;
const int M=5005;

int n,m,u,v;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
bool is_bridge[N][N];

void add(int a,int b) {
	e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u,int from) {
	dfn[u]=low[u]=++ts;
	for (int i=h[u];~i;i=ne[i]) {
		if (!dfn[e[i]]) {
			tarjan(e[i],i);
			low[u]=min(low[u],low[e[i]]);
			if (dfn[u]<low[e[i]]) {
				is_bridge[u][e[i]]=true;
				is_bridge[e[i]][u]=true;
			}
		} else if (i!=(from^1)) {
			low[u]=min(low[u],dfn[e[i]]);
		}
	}
}

int main() {
	memset(h,-1,sizeof(h));
	scanf("%d %d",&n,&m);
	while (m--) {
		scanf("%d %d",&u,&v);
		add(u,v); add(v,u);
	}
	tarjan(1,-1);
	for (int i=1;i<=n;++i) {
		for (int j=i;j<=n;++j) {
			if (is_bridge[i][j]) {
				printf("%d %d\n",i,j);
			}
		}
	}
	return 0;
} 