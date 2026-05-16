#include <bits/stdc++.h>

#define int long long
#define mod 1000000007

using namespace std;

const int N=100005;
const int M=300005;

int n,m,a,b;
int e[M],ne[M],w[N],h[N],tot;
int dfn[N],low[N],ts;
int scc;
bool flag[N];
stack<int> stk;
vector<int> scc_nodes[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u) {
    dfn[u]=low[u]=++ts;
    flag[u]=true; stk.push(u);
    for (int i=h[u];~i;i=ne[i]) {
        if (!dfn[e[i]]) {
            tarjan(e[i]);
            low[u]=min(low[u],low[e[i]]);
        } else if (flag[e[i]]) {
            low[u]=min(low[u],dfn[e[i]]);
        }
    }
    if (dfn[u]==low[u]) {
        scc++;
        int y;
        do {
            y=stk.top(); stk.pop(); flag[y]=false;
            scc_nodes[scc].push_back(y);
        } while (y!=u);
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) scanf("%lld",&w[i]);
    scanf("%lld",&m);
    while (m--) scanf("%lld %lld",&a,&b),add(a,b);
    for (int i=1;i<=n;++i) if (!dfn[i]) tarjan(i);
    int ans1=0,ans2=1;
    for (int i=1;i<=scc;++i) {
        int minn=1000000000000000000LL,cnt=1;
        for (int u:scc_nodes[i]) {
            if (w[u]<minn) {
                ans2*=cnt;
                ans2%=mod;
                cnt=1;
                minn=w[u];
            } else if (w[u]==minn) {
                cnt++;
            }
        }
        ans2*=cnt;
        ans2%=mod;
        ans1+=minn;
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}