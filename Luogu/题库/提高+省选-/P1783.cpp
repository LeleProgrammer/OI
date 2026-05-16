#include <bits/stdc++.h>
using namespace std;

const int N=805;
const int M=644005;
const int inf=1e9;

typedef pair<double,int> pdi;

int n,m,S,T;
int e[M],ne[M],h[N],tot;
double w[M];
double dis[N];
bool vis[N];
priority_queue<pdi,vector<pdi>,greater<pdi>> q;

struct node {
    double x,y;
    friend bool operator < (const node& a,const node& b) {
        return a.x<b.x;
    }
} arr[N];

void add(int a,int b,double c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

double getdis(node a,node b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void dijkstra() {
    for (int i=0;i<=m+1;++i) dis[i]=inf;
    q.push({dis[S]=0,S});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=h[u];~i;i=ne[i]) {
            if (dis[e[i]]>max(dis[u],w[i]) && !vis[e[i]]) {
                q.push({dis[e[i]]=max(dis[u],w[i]),e[i]});
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m); S=0,T=m+1;
    for (int i=1;i<=m;++i) {
        double x,y;
        scanf("%lf %lf",&x,&y);
        arr[i]={x,y};
    }
    sort(arr+1,arr+1+m);
    for (int i=1;i<=m;++i) {
        add(S,i,arr[i].x); add(i,S,arr[i].x);
        add(i,T,n-arr[i].x); add(T,i,n-arr[i].x);
        for (int j=i+1;j<=m;++j) {
            if (arr[i].x==arr[j].x) continue;
            add(i,j,getdis(arr[i],arr[j])/2.0);
            add(j,i,getdis(arr[i],arr[j])/2.0);
        }
    }
    dijkstra();
    printf("%.2lf",dis[T]);
    return 0;
}