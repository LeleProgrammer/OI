#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=50005;
const int M=200005;

typedef pair<int,int> pii;

int n,m,k,a,b,c,dest;
int e[M],ne[M],w[M],h[N],tot;
int dis[N];
bool check[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra() {
    for (int i=1;i<=n;++i) dis[i]=inf,check[i]=false;
    dis[1]=0;
    q.push(make_pair(dis[1],1));
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
    scanf("%d %d %d",&n,&m,&k);
    while (m--) {
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c); add(b,a,c);
    }
    dijkstra();
    while (k--) {
        scanf("%d %d",&a,&b);
        printf("%d\n",dis[a]+dis[b]);
    }
    return 0;
}