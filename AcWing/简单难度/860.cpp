#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

int n,m;
int h[N],ne[M],e[M],tot;
int color[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

bool dfs(int curr,int c) {
    color[curr]=c;
    for (int i=h[curr];~i;i=ne[i]) {
        if (!color[e[i]]) {
            if (!dfs(e[i],3-c)) return false;
        } else if (color[e[i]]==c) return false;
    }
    return true;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b); add(b,a);
    }
    bool ok=true;
    for (int i=1;i<=n && ok;++i) {
        if (!color[i]) {
            ok&=dfs(i,1);
        }
    }
    if (ok) puts("Yes");
    else puts("No");
    return 0;
}