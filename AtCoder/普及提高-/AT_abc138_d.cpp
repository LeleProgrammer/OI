#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int M=400005;

int n,q;
int e[M],ne[M],h[N],tot;
int arr[N];
int f[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa) {
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        f[e[i]]=f[u]+arr[e[i]];
        dfs(e[i],u);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n-1;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    while (q--) {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a]+=b;
    }
    f[1]=arr[1];
    dfs(1,0);
    for (int i=1;i<=n;++i) printf("%d ",f[i]);
    return 0;
}