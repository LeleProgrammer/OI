#include <bits/stdc++.h>
using namespace std;

const int N=1005;
const int M=20005;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int n,m,S,T,K;
int e[M],ne[M],w[M],h[N],rev_h[N],tot;
int dis[N];
bool check[N];

void add(int* h,int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra() {
    priority_queue< pii,vector<pii>,greater<pii> > q;
    memset(dis,0x3f,sizeof(dis));
    memset(check,0,sizeof(check));
    dis[T]=0;
    q.push(make_pair(dis[T],T));
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        check[u]=true;
        for (int i=rev_h[u];~i;i=ne[i]) {
            if (dis[e[i]]>dis[u]+w[i] && !check[e[i]]) {
                dis[e[i]]=dis[u]+w[i];
                q.push(make_pair(dis[e[i]],e[i]));
            }
        }
    }
}

int A_star() {
    priority_queue< piii,vector<piii>,greater<piii> > q; // estimate distance, real distance, pos
    int k[N]={0};
    q.push(make_pair(dis[S],make_pair(0,S)));
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second.second;
        int d=tp.second.first;
        k[u]++;
        if (k[T]==K) return d;
        for (int i=h[u];~i;i=ne[i]) {
            if (k[e[i]]<K) {
                q.push(make_pair(d+w[i]+dis[e[i]],make_pair(d+w[i],e[i])));
            }
        }
    }
    return -1;
}

int main() {
    memset(h,-1,sizeof(h));
    memset(rev_h,-1,sizeof(rev_h));
    scanf("%d %d",&n,&m);
    while (m--) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        add(h,a,b,c);
        add(rev_h,b,a,c);
    }
    scanf("%d %d %d",&S,&T,&K);
    if (S==T) K++; // 至少经过一条边
    dijkstra();
    printf("%d",A_star());
    return 0;
}