#include <bits/stdc++.h>

#define int long long
#define mod 1000000007

using namespace std;

const int N=100005;
const int M=300005;

int n,m,a,b;
int w[N];
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int scc;
vector<int> scc_nodes[N];
bool flag[N];
stack<int> stk;

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
    for (int i=1;i<=n;++i) {
        scanf("%lld",&w[i]);
    }
    scanf("%lld",&m);
    while (m--) {
        scanf("%lld %lld",&a,&b);
        add(a,b);
    }
    for (int i=1;i<=n;++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    int ans1=0,ans2=1;
    for (int i=1;i<=scc;++i) {
        int minn=0x3f3f3f3f,cnt=0;
        for (int u:scc_nodes[i]) {
            if (w[u]<minn) {
                if (cnt) ans2*=cnt;
                ans2%=mod;
                minn=w[u];
                cnt=1;
            } else if (w[u]==minn) {
                cnt++;
                minn=w[u];
            }
        }
        if (cnt) ans2*=cnt;
        ans1+=minn;
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}