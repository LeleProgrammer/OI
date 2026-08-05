#include <bits/stdc++.h>
using namespace std;

const int N=5005;
const int M=500005;
const int mod=80112002;

int n,m;
int e[M],ne[M],h[N],tot;
int in[N],out[N];
int f[N];
queue<int> q;
int ans;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void topu() {
    for (int i=1;i<=n;++i) {
        if (!in[i]) {
            q.push(i);
            f[i]=1;
        }
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            f[e[i]]+=f[u];
            f[e[i]]%=mod;
            in[e[i]]--;
            if (!in[e[i]]) q.push(e[i]);
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        out[a]++;
        in[b]++;
    }
    topu();
    for (int i=1;i<=n;++i) {
        if (!out[i]) {
            ans+=f[i];
            ans%=mod;
        }
    }
    printf("%d",ans);
    return 0;
}