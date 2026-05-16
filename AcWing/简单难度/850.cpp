#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int n,m;
int u,v,w;
struct edge {
    int w;
    int to;
    int next;
} e[150005];
int h[150005];
int cnt;
int dis[150005];
bool chk[150005];

typedef pair<int,int> pii;

void add(int u,int v,int w) {
    e[cnt].w=w;
    e[cnt].to=v;
    e[cnt].next=h[u];
    h[u]=cnt++;
}

void dijkstra() {
    priority_queue< pii,vector<pii>,greater<pii> > q;
    q.push(make_pair(0,1));
    dis[1]=0;
    while (!q.empty()) {
        pii p=q.top(); q.pop();
        int curr=p.second,dist=p.first;
        if (chk[curr]) continue;
        chk[curr]=true;
        for (int i=h[curr];i!=-1;i=e[i].next) {
            if (dis[e[i].to]>dist+e[i].w) {
                dis[e[i].to]=dist+e[i].w;
                q.push(make_pair(dis[e[i].to],e[i].to));
            }
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=100000;++i) dis[i]=inf,h[i]=-1;
    memset(chk,false,sizeof(chk));
    for (int i=1;i<=m;++i) {
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
    }
    dijkstra();
    printf("%d",dis[n]!=inf?dis[n]:-1);
    return 0;
}