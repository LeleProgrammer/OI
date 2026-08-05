#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

int n,m;
int e[M],ne[M],h[N],tot;
int f[N],in[N];
queue<int> q;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void topu() {
    for (int i=1;i<=n;++i) {
        if (!in[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            f[e[i]]=max(f[e[i]],f[u]+1);
            if (!--in[e[i]]) q.push(e[i]);
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) f[i]=1;
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        in[b]++;
    }
    topu();
    for (int i=1;i<=n;++i) printf("%d\n",f[i]);
    return 0;
}