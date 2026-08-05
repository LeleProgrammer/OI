#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=10005;
const int M=50005;

int n,m;
int e[M],ne[M],h[N],tot;
int arr[N];
int f[N];
int in[N],out[N];
int ans;
queue<int> q;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void topu() {
    for (int i=1;i<=n;++i) if (!in[i]) q.push(i),f[i]=arr[i];
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            f[e[i]]=max(f[e[i]],f[u]+arr[e[i]]);
            in[e[i]]--;
            if (!in[e[i]]) q.push(e[i]);
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) scanf("%lld",&arr[i]);
    while (m--) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        add(a,b);
        out[a]++,in[b]++;
    }
    topu();
    for (int i=1;i<=n;++i) if (!out[i]) ans=max(ans,f[i]);
    printf("%lld",ans);
    return 0;
}