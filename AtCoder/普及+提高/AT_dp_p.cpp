#include <bits/stdc++.h>

#define mod 1000000007
#define int long long

using namespace std;

int n,u,v;
vector<int> tree[100005];
int f[100005][2]; // 0:black 1:white

void dfs(int pos,int from) {
    f[pos][0]=1;
    f[pos][1]=1;
    for (int i=0;i<tree[pos].size();++i) {
        if (tree[pos][i]==from) continue;
        dfs(tree[pos][i],pos);
        f[pos][0]=f[pos][0]*f[tree[pos][i]][1]; f[pos][0]%=mod;
        f[pos][1]=f[pos][1]*((f[tree[pos][i]][0]+f[tree[pos][i]][1])%mod); f[pos][1]%=mod;
    }
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n-1;++i) {
        scanf("%lld %lld",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(f,0,sizeof(f));
    dfs(1,-1);
    printf("%lld\n",(f[1][0]+f[1][1])%mod);
    return 0;
}