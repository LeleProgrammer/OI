#include <bits/stdc++.h>

#define mod 1000000007
#define int long long

using namespace std;

int n,k,x,y,b,c;
vector<int> tree[100005];
int colored[100005];
int f[100005][4];

void dfs(int pos,int from) {
    if (!colored[pos]) f[pos][1]=f[pos][2]=f[pos][3]=1;
    else {
        f[pos][1]=f[pos][2]=f[pos][3]=0;
        f[pos][colored[pos]]=1;
    }
    for (int i=0;i<tree[pos].size();++i) {
        if (tree[pos][i]==from) continue;
        dfs(tree[pos][i],pos);
        if (colored[pos]==1 || colored[pos]==0) f[pos][1]*=(f[tree[pos][i]][2]+f[tree[pos][i]][3])%mod;
        f[pos][1]%=mod;
        if (colored[pos]==2 || colored[pos]==0) f[pos][2]*=(f[tree[pos][i]][1]+f[tree[pos][i]][3])%mod;
        f[pos][2]%=mod;
        if (colored[pos]==3 || colored[pos]==0) f[pos][3]*=(f[tree[pos][i]][1]+f[tree[pos][i]][2])%mod;
        f[pos][3]%=mod;
    }
}

signed main() {
    scanf("%lld %lld",&n,&k);
    for (int i=1;i<=n-1;++i) {
        scanf("%lld %lld",&x,&y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    memset(colored,0,sizeof(colored));
    for (int i=1;i<=k;++i) {
        scanf("%lld %lld",&b,&c);
        colored[b]=c;
    }
    memset(f,0,sizeof(f));
    dfs(1,-1);
    printf("%lld",(f[1][1]+f[1][2]+f[1][3])%mod);
    return 0;
}