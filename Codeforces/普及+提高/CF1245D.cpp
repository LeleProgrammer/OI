#include <bits/stdc++.h>
using namespace std;

const int N=2005;

int n;
int c[N];
int k[N];
int x[N];
int y[N];

int tot;
int h[N];
int ne[N];
int to[N];
int e[N];

void add_edge(int u,int v,int w) {
    ne[++tot]=h[u];
    h[u]=tot;
    e[u]=w;
    to[tot]=v;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&x[i],&y[i]);
    }
    for (int i=1;i<=n;++i) scanf("%d",&c[i]);
    for (int i=1;i<=n;++i) scanf("%d",&k[i]);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            ;
        }
    }
}