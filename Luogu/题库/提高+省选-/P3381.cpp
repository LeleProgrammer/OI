#include <bits/stdc++.h>
using namespace std;

const int N=5005;
const int M=100005;
const int inf=2147483647;

int n,m,S,T;
int e[M],ne[M],c[M],f[M],h[N],tot;
int dis[N],flow[N];
bool inq[N];
int back[N];

void add(int a,int b,int flow,int cost) {
    e[tot]=b,f[tot]=flow,c[tot]=cost,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,c[tot]=-cost,ne[tot]=h[b],h[b]=tot++;
}

bool spfa() {
    queue<int> q;
    memset(inq,0,sizeof(inq));
    for (int i=1;i<=n;++i) flow[i]=dis[i]=inf;
    q.push(S); inq[S]=true; dis[S]=0;
    while (!q.empty()) {
        int u=q.front(); q.pop(); inq[u]=false;
        for (int i=h[u];~i;i=ne[i]) {
            if (dis[e[i]]>dis[u]+c[i] && f[i]) {
                dis[e[i]]=dis[u]+c[i];
                flow[e[i]]=min(flow[u],f[i]);
                back[e[i]]=i;
                if (inq[e[i]]) continue;
                q.push(e[i]);
                inq[e[i]]=true;
            }
        }
    }
    return dis[T]!=inf;
}

pair<int,int> EK() {
    int max_flow=0;
    int min_cost=0;
    while (spfa()) {
        max_flow+=flow[T];
        int u=T;
        while (u!=S) {
            f[back[u]]-=flow[T];
            f[back[u]^1]+=flow[T];
            min_cost+=flow[T]*c[back[u]];
            u=e[back[u]^1];
        }
    }
    return {max_flow,min_cost};
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d %d",&n,&m,&S,&T);
    while (m--) {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        add(a,b,c,d);
    }
    auto ans=EK();
    printf("%d %d",ans.first,ans.second);
    return 0;
}