#include <bits/stdc++.h>
using namespace std;

const int N=205;
const int M=20405;
const int inf=1e9;

int n,m,S,T;
int arr_a[N],arr_b[N];
int e[M],ne[M],f[M],c[M],h[N],tot;
int dis[N],flow[N],back[N];
bool inq[N];
int cmp_method;
const int flag[2]={inf,-inf};

void add(int a,int b,int flow,int cost) {
    e[tot]=b,f[tot]=flow,c[tot]=cost,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,c[tot]=-cost,ne[tot]=h[b],h[b]=tot++;
}

bool cmp(int a,int b) {
    if (!cmp_method) return a>b;
    else return a<b;
}

bool spfa() {
    queue<int> q;
    for (int i=0;i<N;++i) dis[i]=flag[cmp_method],flow[i]=inf;
    memset(inq,0,sizeof(inq));
    q.push(S),dis[S]=0,inq[S]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop(); inq[u]=false;
        for (int i=h[u];~i;i=ne[i]) {
            if (cmp(dis[e[i]],dis[u]+c[i]) && f[i]) {
                dis[e[i]]=dis[u]+c[i];
                flow[e[i]]=min(flow[u],f[i]);
                back[e[i]]=i;
                if (!inq[e[i]]) {
                    q.push(e[i]);
                    inq[e[i]]=true;
                }
            }
        }
    }
    return dis[T]!=flag[cmp_method];
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
    scanf("%d %d",&n,&m); S=0,T=N-1;
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr_a[i]);
    }
    for (int i=1;i<=m;++i) {
        scanf("%d",&arr_b[i]);
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            int k;
            scanf("%d",&k);
            add(i,n+j,arr_a[i],k);
        }
    }
    for (int i=1;i<=n;++i) {
        add(S,i,arr_a[i],0);
    }
    for (int i=1;i<=m;++i) {
        add(n+i,T,arr_b[i],0);
    }
    cmp_method=0;
    printf("%d\n",EK());
    restore();
    cmp_method=1;
    printf("%d",EK());
    return 0;
}