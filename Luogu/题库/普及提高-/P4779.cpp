#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define int_max 0x7fffffff
#define MAXX 200005
#define int long long

using namespace std;

int n,m,s;
int u,v,w;
struct edge {
    int w;
    int to;
    int next;
} e[MAXX];
int h[MAXX];
int cnt;
int dis[MAXX];
bool chk[MAXX];

typedef pair<int,int> pii;

void add(int u,int v,int w) {
    e[cnt].w=w;
    e[cnt].to=v;
    e[cnt].next=h[u];
    h[u]=cnt++;
}

void dijkstra() {
    priority_queue< pii,vector<pii>,greater<pii> > q;
    q.push(make_pair(0,s));
    dis[s]=0;
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

signed main() {
    scanf("%lld %lld %lld",&n,&m,&s);
    for (int i=1;i<=MAXX-1;++i) dis[i]=inf,h[i]=-1;
    memset(chk,false,sizeof(chk));
    for (int i=1;i<=m;++i) {
        scanf("%lld %lld %lld",&u,&v,&w);
        add(u,v,w);
    }
    dijkstra();
    for (int i=1;i<=n;++i) printf("%lld ",dis[i]==inf?int_max:dis[i]);
    return 0;
}