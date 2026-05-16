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

void add(int a,int b) {
	e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u,int from) {
	dfn[u]=low[u]=++ts;
	stk.push(u);
	for (int i=h[u];~i;i=ne[i]) {
		if (!dfn[e[i]]) {
			tarjan(e[i],i);
			low[u]=min(low[u],low[e[i]]);
		} else if (i!=(from^1)) { // 优先级，异或要加括号 
			low[u]=min(low[u],dfn[e[i]]);
		}
	}
	if (dfn[u]==low[u]) {
		dcc++;
		int y;
		do {
			y=stk.top(); stk.pop();
			dcc_nodes[dcc].push_back(y);
		} while (y!=u);
	}
}

int main() {
	memset(h,-1,sizeof(h));
	scanf("%d %d",&n,&m);
	while (m--) {
		scanf("%d %d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;++i) {
		if (!dfn[i]) {
			tarjan(i,M);
		}
	}
	printf("%d",dcc);
	putchar(10);
	for (int i=1;i<=dcc;++i) {
		printf("%d ",dcc_nodes[i].size());
		for (int v:dcc_nodes[i]) {
			printf("%d ",v);
		}
		putchar(10);
	}
	return 0;
}