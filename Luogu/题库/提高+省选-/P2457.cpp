#include <bits/stdc++.h>
using namespace std;

const int N=307;
const int M=45605;
const int inf=1e9;

int n,S,T;
int arr[N][N],sum[N];
int e[M],f[M],ne[M],c[M],h[N],tot;
int dis[N],flow[N],back[N];
bool inq[N];

void add(int a,int b,int flow,int cost) {
    e[tot]=b,f[tot]=flow,c[tot]=cost,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,c[tot]=-cost,ne[tot]=h[b],h[b]=tot++;
}

bool spfa() {
    queue<int> q;
    for (int i=0;i<N;++i) flow[S]=dis[i]=inf;
    q.push(S),dis[S]=0,inq[S]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop(); inq[u]=false;
        for (int i=h[u];~i;i=ne[i]) {
            if (dis[e[i]]>dis[u]+c[i] && f[i]) {
                dis[e[i]]=dis[u]+c[i];
                flow[e[i]]=min(flow[u],f[i]);
                back[e[i]]=i;
                q.push(e[i]);
                inq[e[i]]=true;
            }
        }
    }
    return dis[T]!=inf;
}

int EK() {
    int ans=0;
    while (spfa()) {
        int u=T;
        while (u!=S) {
            ans+=flow[T]*c[back[u]];
            f[back[u]]-=flow[T];
            f[back[u]^1]+=flow[T];
            u=e[back[u]^1];
        }
    }
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n); S=0,T=N-1;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            scanf("%d",&arr[i][j]);
            sum[j]+=arr[i][j];
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            add(i,n+j,1,sum[j]-arr[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        add(S,i,1,0);
    }
    for (int i=1;i<=n;++i) {
        add(n+i,T,1,0);
    }
    int ans=EK();
    printf("%d",ans);
    return 0;
}