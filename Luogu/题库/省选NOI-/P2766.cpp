#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=1005;
const int M=251005;

int n,S,T,s;
int arr[N];
int e[M],f[M],ne[M],h[N],tot;
int layer[N],cur[N];
int dp[N];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

bool bfs() {
    memset(layer,-1,sizeof(layer));
    queue<int> q;
    q.push(S); layer[S]=0; cur[S]=h[S];
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (layer[e[i]]==-1 && f[i]) {
                layer[e[i]]=layer[u]+1;
                cur[e[i]]=h[e[i]];
                if (e[i]==T) return true;
                q.push(e[i]);
            }
        }
    }
    return false;
}

int dfs(int u,int limit) {
    if (u==T) return limit;
    int k=0;
    for (int i=cur[u];~i  && k<limit;i=ne[i]) {
        if (layer[e[i]]==layer[u]+1 && f[i]) {
            int ret=dfs(e[i],min(f[i],limit-k));
            if (!ret) layer[e[i]]=-1;
            k+=ret,f[i]-=ret,f[i^1]+=ret;
        }
    }
    return k;
}

int dinic() {
    int ans=0,k;
    while (bfs()) while (k=dfs(S,inf)) ans+=k;
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n); S=0,T=n+n+1;
    for (int i=1;i<=n;++i) scanf("%d",&arr[i]);
    for (int i=1;i<=n;++i) {
        dp[i]=1;
        for (int j=1;j<=i-1;++j) {
            if (arr[j]<=arr[i]) {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        s=max(s,dp[i]);
    }
    for (int i=1;i<=n;++i) if (dp[i]==1) add(S,i,1);
    for (int i=1;i<=n;++i) if (dp[i]==s) add(n+i,T,1);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=i-1;++j) {
            if (arr[j]<=arr[i] && dp[j]+1==dp[i]) {
                add(n+j,i,1);
            }
        }
    }
    for (int i=1;i<=n;++i) add(i,n+i,1);
    printf("%d\n",s);
    if (s==1) {
        printf("%d\n",n);
        printf("%d",n);
    } else {
        int ans=dinic();
        printf("%d\n",ans);
        for (int i=0;i<tot;i+=2) {
            if ((e[i^1]==S && e[i]==1) || (e[i^1]==1 && e[i]==n+1) || (e[i^1]==n && e[i]==n+n) || (e[i^1]==n+n && e[i]==T)) f[i]=inf;
        }
        printf("%d",ans+dinic());
    }
    return 0;
}