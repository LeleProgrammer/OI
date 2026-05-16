#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

int n;
int e[M],ne[M],w[M],h[N],tot;
int f[N];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa) {
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        if (w[i]%2) f[e[i]]=f[u]^1;
        else f[e[i]]=f[u];
        dfs(e[i],u);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n-1;++i) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,0);
    for (int i=1;i<=n;++i) {
        printf("%d\n",f[i]);
    }
    return 0;
}