#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=200005;
const int K=105;
const int mod=1000000007;
const int inf=1000000007;

int n,R;
int e[M],ne[M],h[N],w[M],tot;
int f[N][K];
int g[N][K];
int p1[K];
int p2[K];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int fa) {
    for (int i=1;i<=R;++i) {
        g[u][i]=1;
    }
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        dfs1(e[i],u);
        int sum=0;
        for (int j=1;j<=R;++j) {
            sum+=g[e[i]][j];
        }
        for (int j=1;j<=R;++j) {
            if (w[i]==0) {
                g[u][j]*=(sum-g[e[i]][j])%mod;
            } else if (w[i]==1) {
                g[u][j]*=sum%mod;
            } else {
                g[u][j]*=g[e[i]][j];
            }
            g[u][j]%=mod;
        }
    }
}

void dfs2(int u,int fa) {
    for (int i=1;i<=R;++i) {
        f[u][i]=i;
    }
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        dfs2(e[i],u);
        p1[0]=inf;
        p2[R+1]=inf;
        for (int j=1;j<=R;++j) {
            p1[j]=min(p1[j-1],f[e[i]][j]);
        }
        for (int j=R;j;--j) {
            p2[j]=min(p2[j+1],f[e[i]][j]);
        }
        for (int j=1;j<=R;++j) {
            if (w[i]==0) {
                f[u][j]+=min(p1[j-1],p2[j+1]);
            } else if (w[i]==1) {
                f[u][j]+=p1[R];
            } else {
                f[u][j]+=f[e[i]][j];
            }
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld",&n,&R);
    bool flag=false;
    for (int i=1;i<=n-1;++i) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
        if (c==0) flag=true;
    }
    if (flag && R==1) {
        puts("0 0");
        return 0;
    }
    dfs1(1,0);
    int ans1=0;
    for (int i=1;i<=R;++i) {
        ans1+=g[1][i];
    }
    ans1%=mod;
    dfs2(1,0);
    int ans2=inf;
    for (int i=1;i<=R;++i) {
        ans2=min(ans2,f[1][i]);
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}