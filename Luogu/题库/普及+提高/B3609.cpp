#include <bits/stdc++.h>
using namespace std;

const int N=10005;
const int M=100005;

int n,m,u,v;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int id[N],dcc;
bool flag[N];
stack<int> stk;
vector<int> dcc_nodes[N];

void add(int a,int b) {
	e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u) {
	dfn[u]=low[u]=++ts;
	stk.push(u);
	flag[u]=true;
	for (int i=h[u];~i;i=ne[i]) {
		if (!dfn[e[i]]) {
			tarjan(e[i]);
			low[u]=min(low[u],low[e[i]]);
		} else if (flag[e[i]]) {
			low[u]=min(low[u],dfn[e[i]]);
		}
	}
	if (dfn[u]==low[u]) {
		dcc++;
		int y;
		do {
			y=stk.top(); stk.pop(); flag[y]=false;
			id[y]=dcc;
		} while (y!=u);
	}
}

bool cmp(const int& a,const int& b) {
	return a<b;
}

bool cmp2(const vector<int>& a,const vector<int>& b) {
	return a[0]<b[0];
}

int main() {
	memset(h,-1,sizeof(h));
	scanf("%d %d",&n,&m);
	while (m--) {
		scanf("%d %d",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;++i) {
		if (!dfn[i]) {
			tarjan(i);
		}
	}
	printf("%d\n",dcc);
	for (int i=1;i<=n;++i) {
		dcc_nodes[id[i]].push_back(i);
	}
	for (int i=1;i<=dcc;++i) {
		sort(dcc_nodes[i].begin(),dcc_nodes[i].end(),cmp);
	}
	sort(dcc_nodes+1,dcc_nodes+1+dcc,cmp2);
	for (int i=1;i<=dcc;++i) {
		for (int v:dcc_nodes[i]) {
			printf("%d ",v);
		}
		putchar(10);
	}
	return 0;
}
