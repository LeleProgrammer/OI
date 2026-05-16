#include <bits/stdc++.h>
using namespace std;

const int N=20005;
const int M=200005;

int n,m,u,v;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int dcc;
bool cut[N];
stack<int> stk;
int root;
vector<int> cts;

void add(int a,int b) {
	e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u) {
	dfn[u]=low[u]=++ts;
	stk.push(u);
	if (u==root && !~h[u]) {
		dcc++;
		return;
	}
	int cnt=0;
	for (int i=h[u];~i;i=ne[i]) {
		if (!dfn[e[i]]) {
			tarjan(e[i]);
			low[u]=min(low[u],low[e[i]]);
			if (dfn[u]<=low[e[i]]) {
				cnt++;
				if (u!=root || cnt>=2) cut[u]=true;
				dcc++;
				int y;
				do {
					y=stk.top();
					stk.pop();
				} while (y!=e[i]);
			}
		} else low[u]=min(low[u],dfn[e[i]]);
	}
}

int main() {
	memset(h,-1,sizeof(h));
	scanf("%d %d",&n,&m);
	while (m--) {
		scanf("%d %d",&u,&v);
		if (u==v) continue;
		add(u,v); add(v,u);
	}
	for (root=1;root<=n;++root) {
		if (!dfn[root]) {
			tarjan(root);
		}
	}
	for (int i=1;i<=n;++i) {
		if (cut[i]) {
			cts.push_back(i);
		}
	}
	printf("%d\n",cts.size());
	for (int v:cts) {
		printf("%d ",v);
	}
	return 0;
}
