#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=4005;
const int M=8005;
const int inf=1e18;

typedef pair<int,int> pii;

int n;
int S,T;
int e[M],ne[M],w[M],h[N],tot;
int idx;
vector<int> nodes[N];
int dis[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

struct node {
    int l,r,h,i;
    friend bool operator < (const node& a,const node& b) {
        return a.h>b.h;
    }
} arr[N];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s) {
    for (int i=0;i<N;++i) dis[i]=inf;
    q.push({dis[s]=0,s});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        for (int i=h[u];~i;i=ne[i]) {
            if (dis[e[i]]>dis[u]+w[i]) {
                q.push({dis[e[i]]=dis[u]+w[i],e[i]});
            }
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n); idx=2*n;
    scanf("%lld %lld",&S,&T);
    for (int i=1;i<=n;++i) {
        int l,r,h;
        scanf("%lld %lld %lld",&l,&r,&h);
        arr[i]={l,r,h,i};
    }
    if (S==T) {
        printf("0");
        return 0;
    }
    sort(arr+1,arr+1+n);
    for (int i=1;i<=n;++i) {
        if (arr[i].i==S) {
            S=i;
            break;
        }
    }
    for (int i=1;i<=n;++i) {
        if (arr[i].i==T) {
            T=i;
            break;
        }
    }
    if (S>T) {
        printf("-1");
        return 0;
    }
    for (int i=1;i<=n;++i) {
        int l,r,h;
        l=arr[i].l;
        r=arr[i].r;
        h=arr[i].h;
        nodes[i].push_back(i);
        nodes[i].push_back(n+i);
        add(i,n+i,r-l);
        add(n+i,i,r-l);
        int j;
        for (j=i+1;j<=n;++j) {
            if (arr[j].h<h && l>=arr[j].l && l<=arr[j].r) {
                break;
            }
        }
        if (j<=n) {
            int t=++idx;
            nodes[j].push_back(t);
            add(i,idx,h-arr[j].h);
            add(idx,j,l-arr[j].l);
            add(idx,n+j,arr[j].r-l);
        }
        for (j=i+1;j<=n;++j) {
            if (arr[j].h<h && r>=arr[j].l && r<=arr[j].r) {
                break;
            }
        }
        if (j<=n) {
            int t=++idx;
            nodes[j].push_back(t);
            add(n+i,idx,h-arr[j].h);
            add(idx,j,r-arr[j].l);
            add(idx,n+j,arr[j].r-r);
        }
    }
    dijkstra(S);
    int ans=inf;
    for (int p:nodes[T]) {
        ans=min(ans,dis[p]);
    }
    if (ans==inf) ans=-1;
    printf("%lld",ans);
    return 0;
}