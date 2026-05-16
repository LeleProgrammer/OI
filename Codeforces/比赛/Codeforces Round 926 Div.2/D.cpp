#include <bits/stdc++.h>

#define int long long
#define mod 998244353

using namespace std;

const int N=300005;
const int M=600005;

int T,n;
int e[M],ne[M],h[N],tot;
int f[N];
int ans;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

int dfs(int u,int fa) {
    f[u]=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        f[u]+=dfs(e[i],u);
    }
    int sum=0; // 两个节点都从子树中不包括自身的节点选的话，以自己为公共祖先的组合的数量
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        sum+=f[e[i]]*(f[u]-1-f[e[i]]);
        sum%=mod;
    }
    cout<<sum<<endl;
    sum/=2;
    ans-=sum;
    for (int i=h[u];~i;i=ne[i]) { // 两个节点都从以同一个子节点为根的子树中选，一个是子节点本身，另一个任选，组合的数量
        if (e[i]==fa) continue;
        ans-=f[e[i]]-1;
        cout<<u<<" test:"<<f[e[i]]-1<<endl;
    }
    return f[u];
}

int gett(int k) { // k 个中取 3 个的排列
    return k*(k-1)*(k-2)/6;
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        for (int i=1;i<=n;++i) h[i]=-1,f[i]=0;
        tot=0;
        for (int i=1;i<=n-1;++i) {
            int a,b;
            scanf("%lld %lld",&a,&b);
            add(a,b);
            add(b,a);
        }
        ans=0;
        ans++; // take 0
        ans+=n; // take 1
        ans+=n*(n-1)/2; // take 2
        ans%=mod;
        ans+=gett(n); // take 3
        ans%=mod;
        dfs(1,-1);
        printf("%lld\n",ans);
    }
    return 0;
}