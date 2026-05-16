#include <bits/stdc++.h>
using namespace std;

const int N=400005;
const int M=1000005;

int n,m;
int k[N];
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int id[N],maxx[N],sum[N],scc;
bool flag[N];
stack<int> stk;
queue<int> q;
int in[N];
int out[N];
int ans1[N],ans2[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u) {
    dfn[u]=low[u]=++ts;
    stk.push(u); flag[u]=true;
    for (int i=h[u];~i;i=ne[i]) {
        if (!dfn[e[i]]) {
            tarjan(e[i]);
            low[u]=min(low[u],low[e[i]]);
        } else if (flag[e[i]]) low[u]=min(low[u],dfn[e[i]]);
    }
    if (low[u]==dfn[u]) {
        scc++;
        int y;
        do {
            y=stk.top(); stk.pop(); flag[y]=false;
            id[y]=scc;
            maxx[scc]=max(maxx[scc],k[y]);
            sum[scc]+=k[y];
        } while (y!=u);
    }
}

void topu() {
    for (int i=n+1;i<=scc;++i) {
        ans1[i]=sum[i];
        ans2[i]=maxx[i];
        if (in[i]==0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (ans1[e[i]]<ans1[u]+sum[e[i]]) {
                ans1[e[i]]=ans1[u]+sum[e[i]];
                ans2[e[i]]=max(ans2[u],maxx[e[i]]);
            } else if (ans1[e[i]]==ans1[u]+sum[e[i]]) {
                ans2[e[i]]=max(ans2[e[i]],max(ans2[u],maxx[e[i]]));
            }
            in[e[i]]--;
            out[u]--;
            if (!in[e[i]]) {
                q.push(e[i]);
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m); scc=n;
    for (int i=1;i<=n;++i) scanf("%d",&k[i]);
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
    }
    for (int i=1;i<=n;++i) if (!dfn[i]) tarjan(i);
    for (int i=1;i<=n;++i) {
        for (int j=h[i];~j;j=ne[j]) {
            if (id[i]!=id[e[j]]) {
                add(id[i],id[e[j]]);
                out[id[i]]++;
                in[id[e[j]]]++;
            }
        }
    }
    topu();
    int res1=0,res2=0;
    for (int i=n+1;i<=scc;++i) {
        if (ans1[i]>res1) {
            res1=ans1[i];
            res2=ans2[i];
        } else if (ans1[i]==res1) {
            res2=max(res2,ans2[i]);
        }
    }
    printf("%d %d",res1,res2);
    return 0;
}