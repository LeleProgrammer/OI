#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=50005;
const int M=200005;
const int inf=9000000000000000000LL;

typedef pair<int,int> pii;

int n,m;
int e[M],ne[M],h[N],w[M],tot;
int sta[6];
int dis[6][N];
priority_queue< pii,vector<pii>,greater<pii> > q;
int arr[6]={0,1,2,3,4,5};

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s) {
    while (!q.empty()) q.pop();
    dis[s][sta[s]]=0;
    q.push({dis[s][sta[s]],sta[s]});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        for (int i=h[u];~i;i=ne[i]) {
            if (dis[s][e[i]]>dis[s][u]+w[i]) {
                dis[s][e[i]]=dis[s][u]+w[i];
                q.push({dis[s][e[i]],e[i]});
            }
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    for (int i=0;i<=5;++i) {
        for (int j=0;j<=N-1;++j) {
            dis[i][j]=inf;
        }
    }
    scanf("%lld %lld",&n,&m);
    sta[0]=1;
    for (int i=1;i<=5;++i) scanf("%lld",&sta[i]);
    while (m--) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    for (int i=0;i<=5;++i) {
        dijkstra(i);
    }
    int ans=inf;
    do {
        int curr=0;
        for (int i=1;i<=5;++i) {
            curr+=dis[arr[i-1]][sta[arr[i]]];
        }
        ans=min(ans,curr);
    } while (next_permutation(arr+1,arr+6));
    printf("%lld",ans);
    return 0;
}