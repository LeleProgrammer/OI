#include <bits/stdc++.h>
using namespace std;

const int N=1005;
const int M=2005;
const int inf=2e7;

int n;
int e[M],ne[M],h[N],tot;
int f[N][N];
int ans;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

bool cmp(const int& a,const int& b) {
    return a>b;
}

void dfs(int s,int u,int fa) {
    vector<int> v;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        dfs(s,e[i],u);
        v.push_back(f[s][e[i]]);
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=1;i<=v.size();++i) {
        f[s][u]=max(f[s][u],v[i-1]+i);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=2;i<=n;++i) {
        int a;
        scanf("%d",&a);
        add(a,i);
        add(i,a);
    }
    for (int i=1;i<=n;++i) {
        dfs(i,i,0);
    }
    ans=inf;
    for (int i=1;i<=n;++i) {
        ans=min(ans,f[i][i]);
    }
    printf("%d\n",ans+1);
    for (int i=1;i<=n;++i) {
        if (f[i][i]==ans) {
            printf("%d ",i);
        }
    }
    return 0;
}