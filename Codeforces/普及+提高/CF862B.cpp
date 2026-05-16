#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=200005;

int n;
int e[M],ne[M],h[N],tot;
int color[N];
int cnt[3];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int curr,int c) {
    color[curr]=c;
    cnt[c]++;
    for (int i=h[curr];~i;i=ne[i]) {
        if (!color[e[i]]) {
            dfs(e[i],3-c);
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=1;i<=n-1;++i) {
        int u,v;
        scanf("%lld %lld",&u,&v);
        add(u,v); add(v,u);
    }
    dfs(1,1);
    printf("%lld",cnt[1]*cnt[2]-(n-1));
    return 0;
}