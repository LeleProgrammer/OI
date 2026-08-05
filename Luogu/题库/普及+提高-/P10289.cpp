#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int M=400005;

typedef pair<int,int> pii;

int n,k,Q;
int e[M],ne[M],w[M],h[N],tot;
bool flag[N];
vector<pii> edges;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

int main() {
    scanf("%d %d %d",&n,&k,&Q);
    for (int i=1;i<=n-1;++i) {
        int x,y;
        scanf("%d %d",&x,&y);
        edges.push_back({x,y});
    }
    for (int i=1;i<=k;++i) {
        int u;
        scanf("%d",&u);
        flag[u]=true;
    }
    for (int i=0;i<edges.size();++i) {
        auto u=edges[i];
        int x=u.first;
        int y=u.second;
        if (flag[x] && flag[y]) continue;
        if (flag[x]) x=N-1;
        if (flag[y]) y=N-1;
        add(x,y,1);
        add(y,x,1);
    }
}