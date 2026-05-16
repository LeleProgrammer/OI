#include <bits/stdc++.h>
using namespace std;

const int N=500005;
const int M=4000005;

int n,m,u,v;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int dcc;
stack<int> stk;
vector<int> dcc_nodes[N];
int root;

void add(int a,int b) {
	e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u) {
	dfn[u]=low[u]=++ts;
	stk.push(u);
	if (u==root && h[u]==-1) {
		dcc++;
		dcc_nodes[dcc].push_back(u);
		return;
	}
	for (int i=h[u];~i;i=ne[i]) {
		if (!dfn[e[i]]) {
			tarjan(e[i]);
			low[u]=min(low[u],low[e[i]]);
			if (dfn[u]<=low[e[i]]) {
				dcc++;
				int y;
				do {
					y=stk.top();
					stk.pop();
					dcc_nodes[dcc].push_back(y);
				} while (y!=e[i]);
				dcc_nodes[dcc].push_back(u);
			}
		} else {
			low[u]=min(low[u],dfn[e[i]]);
		}
	}
}

int main() {
	memset(h,-1,sizeof(h));
	scanf("%d %d",&n,&m);
	while (m--) {
		scanf("%d %d",&u,&v);
		if (u==v) continue;
		add(u,v),add(v,u);
	}
	for (root=1;root<=n;++root) {
		if (!dfn[root]) {
			tarjan(root);
		}
	}
	printf("%d\n",dcc);	
	for (int i=1;i<=dcc;++i) {
		printf("%d ",dcc_nodes[i].size());
		for (int j:dcc_nodes[i]) {
			printf("%d ",j);
		}
		putchar(10);
	}
	return 0;
}
