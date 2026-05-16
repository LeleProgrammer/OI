#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=1000005;

int n,m;
int e[M],ne[M],h[N],tot;
bool cut[N];
int dfn[N],low[N],ts;
int id[N];
bool flag[N];
int cnt[N];
int dcc;
vector<int> dccs[N];
stack<int> stk;
int sz[N];
int f[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u) {
    dfn[u]=low[u]=++ts;
    stk.push(u);
    sz[u]=1;
    int k=0;
    if (u==1 && !~h[u]) {
        dcc++;
        id[u]=dcc;
        dccs[dcc].push_back(u);
    }
    for (int i=h[u];~i;i=ne[i]) {
        if (!dfn[e[i]]) {
            tarjan(e[i]);
            sz[u]+=sz[e[i]];
            low[u]=min(low[u],low[e[i]]);
            if (dfn[u]<=low[e[i]]) {
                f[u]+=sz[e[i]]*(n-sz[e[i]]);
                k+=sz[e[i]];
                cut[u]=true;
                dcc++;
                int y;
                do {
                    y=stk.top(); stk.pop();
                    id[y]=dcc;
                    dccs[dcc].push_back(y);
                } while (y!=u);
                stk.push(u);
            }
        } else {
            low[u]=min(low[u],dfn[e[i]]);
        }
    }
    if (cut[u]) f[u]+=(k+1)*(n-k-1);
    f[u]+=(n-1)*(2-cut[u]);
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld",&n,&m);
    while (m--) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        add(a,b); add(b,a);
    }
    tarjan(1);
    for (int i=1;i<=n;++i) {
        printf("%lld\n",f[i]);
    }
    return 0;
}