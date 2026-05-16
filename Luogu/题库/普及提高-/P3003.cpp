#include <bits/stdc++.h>

#define inf 2100000000

using namespace std;

const int N=100005;
const int M=400005;

typedef pair<int,int> pii;

int n,m,da,db,dc,a,b,c;
int e[M],ne[M],w[M],h[N],tot;
int dis[N];
bool check[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s) {
    for (int i=1;i<=n;++i) dis[i]=inf,check[i]=false;
    dis[s]=0;
    q.push(make_pair(dis[s],s));
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int curr=tp.second;
        check[curr]=true;
        for (int i=h[curr];~i;i=ne[i]) {
            if (dis[e[i]]>dis[curr]+w[i] && !check[e[i]]) {
                dis[e[i]]=dis[curr]+w[i];
                q.push(make_pair(dis[e[i]],e[i]));
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d %d %d",&m,&n,&da,&db,&dc);
    while (m--) {
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    int ans;
    dijkstra(da);
    ans=min(dis[db],dis[dc]);
    dijkstra(db);
    ans+=dis[dc];
    printf("%d",ans);
    return 0;
}