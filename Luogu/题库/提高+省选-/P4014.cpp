#include <bits/stdc++.h>
using namespace std;

const int N=107;
const int M=5205;
const int inf=1e9;

int n,S,T;
int arr[N][N];
int e[M],f[M],ne[M],c[M],h[N],tot;
int dis[N],flow[N],back[N];
bool inq[N];
int mode;
const int infs[]={inf,-inf};

void add(int a,int b,int flow,int cost) {
    e[tot]=b,f[tot]=flow,c[tot]=cost,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,c[tot]=-cost,ne[tot]=h[b],h[b]=tot++;
}

bool cmp(int a,int b) {
    if (!mode) return a>b;
    else return a<b;
}

bool spfa() {
    queue<int> q;
    for (int i=0;i<N;++i) dis[i]=infs[mode],flow[i]=inf;
    q.push(S),dis[S]=0,inq[S]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop(); inq[u]=false;
        for (int i=h[u];~i;i=ne[i]) {
            if (cmp(dis[e[i]],dis[u]+c[i]) && f[i]) {
                dis[e[i]]=dis[u]+c[i];
                back[e[i]]=i;
                flow[e[i]]=min(flow[u],f[i]);
                if (!inq[e[i]]) {
                    inq[e[i]]=true;
                    q.push(e[i]);
                }
            }
        }
    }
    return dis[T]!=infs[mode];
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

void restore() {
    for (int i=0;i<=tot;i+=2) {
        f[i]+=f[i^1];
        f[i^1]-=f[i^1];
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n); S=0,T=N-1;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            add(i,n+j,1,arr[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        add(S,i,1,0);
        add(n+i,T,1,0);
    }
    printf("%d\n",EK());
    mode=1;
    restore();
    printf("%d",EK());
    return 0;
}