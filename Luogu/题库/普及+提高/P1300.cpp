#include <bits/stdc++.h>

#define left 0
#define right 1
#define up 2
#define down 3
#define turn_cost 10
#define left_cost 1
#define right_cost 5
#define min4(a,b,c,d) min(min(min(a,b),c),d)

using namespace std;

const int N=3605;
const int M=57605;
const int inf=2e9;

typedef pair<int,int> pii;

int n,m,S,T;
int e[M],ne[M],w[M],h[N],tot;
char arr[35][35];
int dis[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

bool check(int i,int j) {
    if (i>=1 && i<=n && j>=1 && j<=m && arr[i][j]!='.') return true;
    else return false;
}

int get(int i,int j) {
    return m*(i-1)+j;
}

void dijkstra() {
    for (int i=0;i<N-1;++i) dis[i]=inf;
    dis[S]=0;
    q.push({dis[S],S});
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
        for (int j=1;j<=m;++j) {
            scanf(" %c",&arr[i][j]);
            if (arr[i][j]=='F') T=get(i,j);
            else if (arr[i][j]=='E') S=get(i,j)+right*n*m;
            else if (arr[i][j]=='W') S=get(i,j)+left*n*m;
            else if (arr[i][j]=='S') S=get(i,j)+down*n*m;
            else if (arr[i][j]=='N') S=get(i,j)+up*n*m;
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (!check(i,j)) continue;
            if (!check(i,j-1) && !check(i-1,j) && !check(i,j+1) && check(i+1,j)) {
                add(get(i,j)+up*n*m,get(i,j)+down*n*m,turn_cost);
            }
            if (!check(i,j-1) && !check(i-1,j) && check(i,j+1) && !check(i+1,j)) {
                add(get(i,j)+left*n*m,get(i,j)+right*n*m,turn_cost);
            }
            if (!check(i,j-1) && check(i-1,j) && !check(i,j+1) && !check(i+1,j)) {
                add(get(i,j)+down*n*m,get(i,j)+up*n*m,turn_cost);
            }
            if (check(i,j-1) && !check(i-1,j) && !check(i,j+1) && !check(i+1,j)) {
                add(get(i,j)+right*n*m,get(i,j)+left*n*m,turn_cost);
            }
            if (check(i+1,j)) {
                add(get(i,j)+down*n*m,get(i+1,j)+down*n*m,0);
            }
            if (check(i-1,j)) {
                add(get(i,j)+up*n*m,get(i-1,j)+up*n*m,0);
            }
            if (check(i,j+1)) {
                add(get(i,j)+right*n*m,get(i,j+1)+right*n*m,0);
            }
            if (check(i,j-1)) {
                add(get(i,j)+left*n*m,get(i,j-1)+left*n*m,0);
            }
            if (check(i,j-1)) add(get(i,j)+up*n*m,get(i,j-1)+left*n*m,left_cost);
            if (check(i+1,j)) add(get(i,j)+left*n*m,get(i+1,j)+down*n*m,left_cost);
            if (check(i,j+1)) add(get(i,j)+down*n*m,get(i,j+1)+right*n*m,left_cost);
            if (check(i-1,j)) add(get(i,j)+right*n*m,get(i-1,j)+up*n*m,left_cost);
            if (check(i,j+1)) add(get(i,j)+up*n*m,get(i,j+1)+right*n*m,right_cost);
            if (check(i+1,j)) add(get(i,j)+right*n*m,get(i+1,j)+down*n*m,right_cost);
            if (check(i,j-1)) add(get(i,j)+down*n*m,get(i,j-1)+left*n*m,right_cost);
            if (check(i-1,j)) add(get(i,j)+left*n*m,get(i-1,j)+up*n*m,right_cost);
        }
    }
    dijkstra();
    // int direct=right;
    // for (int i=1;i<=n;++i) {
    //     for (int j=1;j<=m;++j) {
    //         if (dis[get(i,j)+direct*n*m]==inf) printf("- ");
    //         else printf("%d ",dis[get(i,j)+direct*n*m]);
    //     }
    //     putchar(10);
    // }
    printf("%d",min4(dis[T+up*n*m],dis[T+down*n*m],dis[T+left*n*m],dis[T+right*n*m]));
    return 0;
}

/*
S: 5,3
*/