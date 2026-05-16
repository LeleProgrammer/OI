#include <bits/stdc++.h>
using namespace std;

const int N=5005;
const int M=20005;

int n,m,u,v;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int id[N],dcc;
bool is_bridge[M];
int deg[N];
int ans;
stack<int> stk;

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
			if (dfn[u]<low[e[i]]) {
				is_bridge[i]=is_bridge[i^1]=true;
			}
		} else if (i!=(from^1)) {
			low[u]=min(low[u],dfn[e[i]]);
		}
	}
	if (dfn[u]==low[u]) {
		dcc++;
		int y;
		do {
			y=stk.top(); stk.pop();
			id[y]=dcc;
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
	tarjan(1,-1);
	for (int i=0;i<tot;++i) {
		if (is_bridge[i]) {
			deg[id[e[i]]]++;
		}
	}
	for (int i=1;i<=dcc;++i) {
		if (deg[i]==1) {
			ans++;
		}
	}
	printf("%d",ans+1>>1);
	return 0;
}