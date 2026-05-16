#include <bits/stdc++.h>

#define int long long
#define inf 1000000000000000000LL

using namespace std;

const int N=1000005;
const int M=1000005;

int n,m,s;
int e[M],ne[M],w[M],ww[M],h[N],tot;
int e2[M],ne2[M],w2[M],h2[N],tot2;
int cost[N];
vector<int> v;
int dfn[N],low[N],ts;
int id[N],scc;
int scc_cnt[N];
stack<int> stk;
bool flag[N];
queue<int> q;
int in[N];
int dis[N];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a];
    // 1+...+n = n*(n+1)/2 = c
    // n^2+n=c*2
    // n^2+n-c*2=0
    int delta=1*1-4*1*c*2*(-1);
    int d=max(((-1)+sqrt(delta))/(2*1),((-1)-sqrt(delta))/(2*1));
    ww[tot]=d*c-v[d]+c;
    h[a]=tot++;
}

void add2(int a,int b,int c) {
    e2[tot2]=b,w2[tot2]=c,ne2[tot2]=h2[a],h2[a]=tot2++;
}

void init() {
    int sum[30005];
    sum[0]=0;
    for (int i=1;i<=30000;++i) sum[i]=sum[i-1]+i;
    v.push_back(0);
    for (int i=1;i<=30000;++i) v.push_back(v.back()+sum[i]);
}

void tarjan(int u) {
    dfn[u]=low[u]=++ts;
    stk.push(u); flag[u]=true;
    for (int i=h[u];~i;i=ne[i]) {
        if (!dfn[e[i]]) {
            tarjan(e[i]);
            low[u]=min(low[u],low[e[i]]);
        } else if (flag[e[i]]) {
            low[u]=min(low[u],dfn[e[i]]);
        }
    }
    if (low[u]==dfn[u]) {
        scc++;
        int y;
        do {
            y=stk.top(); stk.pop(); flag[y]=false;
            id[y]=scc;
            scc_cnt[scc]++;
        } while (y!=u);
    }
}

void topu() {
    for (int i=1;i<=scc;++i) {
        if (!in[i]) {
            q.push(i);
        }
        dis[i]=-inf;
    }
    dis[id[s]]=cost[id[s]];
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h2[u];~i;i=ne2[i]) {
            in[e2[i]]--;
            if (dis[e2[i]]<dis[u]+cost[e2[i]]+w2[i]) {
                dis[e2[i]]=dis[u]+cost[e2[i]]+w2[i];
            }
            if (!in[e2[i]]) {
                q.push(e2[i]);
            }
        }
    }
}

signed main() {
    init();
    memset(h,-1,sizeof(h));
    memset(h2,-1,sizeof(h2));
    scanf("%lld %lld",&n,&m);
    while (m--) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
    }
    scanf("%lld",&s);
    for (int i=1;i<=n;++i) if (!dfn[i]) tarjan(i);
    for (int i=1;i<=n;++i) {
        for (int j=h[i];~j;j=ne[j]) {
            if (id[i]==id[e[j]]) {
                cost[id[i]]+=ww[j];
            } else {
                add2(id[i],id[e[j]],w[j]);
                in[id[e[j]]]++;
            }
        }
    }
    topu();
    int ans=0;
    for (int i=1;i<=scc;++i) {
        ans=max(ans,dis[i]);
    }
    printf("%lld",ans);
    return 0;
}