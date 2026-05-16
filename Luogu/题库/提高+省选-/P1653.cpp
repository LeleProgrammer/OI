#include <bits/stdc++.h>
using namespace std;

const int N=505;
const int M=1000005;

int n,m;
int G[N][N];
int e[M],ne[M],h[N*N],tot;
int dfn[N*N],low[N*N],ts;
int scc,id[N*N];
int out[N*N];
int in[N*N];
bool flag[N*N];
stack<int> stk;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u) {
    dfn[u]=low[u]=++ts;
    stk.push(u); flag[u]=true;
    for (int i=h[u];~i;i=ne[i]) {
        if (!dfn[e[i]]) {
            tarjan(e[i]);
            low[u]=min(low[u],low[e[i]]);
        } else if (flag[e[i]]) {
            low[u]=min(low[u],dfn[e[i]]);
        }
    }
    if (dfn[u]==low[u]) {
        scc++;
        int y;
        do {
            y=stk.top(); stk.pop(); flag[y]=false;
            id[y]=scc;
        } while (y!=u);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&m,&n);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf("%d",&G[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (i>=2 && G[i-1][j]<=G[i][j]) {
                add((i-1)*m+j,(i-2)*m+j);
            }
            if (i<=n-1 && G[i+1][j]<=G[i][j]) {
                add((i-1)*m+j,i*m+j);
            }
            if (j>=2 && G[i][j-1]<=G[i][j]) {
                add((i-1)*m+j,(i-1)*m+j-1);
            }
            if (j<=m-1 && G[i][j+1]<=G[i][j]) {
                add((i-1)*m+j,(i-1)*m+j+1);
            }
        }
    }
    for (int i=1;i<=n*m;++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    if (scc==1) {
        puts("0");
        return 0;
    }
    for (int i=1;i<=n*m;++i) {
        for (int j=h[i];~j;j=ne[j]) {
            if (id[i]==id[e[j]]) continue;
            in[id[e[j]]]++;
            out[id[i]]++;
        }
    }
    int in_zero=0,out_zero=0;
    for (int i=1;i<=scc;++i) {
        if (!in[i]) in_zero++;
        if (!out[i]) out_zero++;
    }
    printf("%d",max(in_zero,out_zero));
    return 0;
}