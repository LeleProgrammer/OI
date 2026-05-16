#include <bits/stdc++.h>

#define inf 2147483647

using namespace std;

const int N=500005;
const int M=1500005;
const int K=505;

typedef pair<int,int> pii;

int n,m;
int a[K][K];
int b[K][K];
int dis[N];
int e[M],ne[M],h[N],w[M],tot;
priority_queue<pii,vector<pii>,greater<pii> > q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

int get(int i,int j) {
    return (i-1)*m+j;
}

void dijkstra() {
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            dis[get(i,j)]=inf;
            dis[get(i,j)+n*m]=inf;
        }
    }
    dis[1]=0;
    q.push({dis[1],1});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        for (int i=h[u];~i;i=ne[i]) {
            if (dis[e[i]]>dis[u]+w[i]) {
                dis[e[i]]=dis[u]+w[i];
                q.push({dis[e[i]],e[i]});
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m-1;++j) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=1;i<=n-1;++i) {
        for (int j=1;j<=m;++j) {
            scanf("%d",&b[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (j<m) {
                add(get(i,j),get(i,j+1),a[i][j]);
            }
            if (j>=2) {
                add(get(i,j),get(i,j-1),a[i][j-1]);
            }
            if (i<n) {
                add(get(i,j),get(i+1,j),b[i][j]);
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            add(get(i,j),get(i,j)+n*m,1);
            add(get(i,j)+n*m,get(i,j),0);
            if (i==1) continue;
            add(get(i,j)+n*m,get(i-1,j)+n*m,1);
        }
    }
    dijkstra();
    printf("%d\n",dis[get(n,m)]);
    return 0;
}