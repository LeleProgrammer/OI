#include <bits/stdc++.h>

#define inf 9000000000000000000LL
#define int long long

using namespace std;

const int N=200005;
const int M=200005;

int n,m;
int e[M],ne[M],h[N],w[M],L[M],D[M],K[M],tot;
int maxs[N];

void add(int a,int b,int c,int l,int d,int k) {
    e[tot]=b,w[tot]=c,L[tot]=l,D[tot]=d,K[tot]=k,ne[tot]=h[a],h[a]=tot++;
}

int go_lower(int edge,int k) {
    int s=L[edge];
    int st=D[edge];
    k-=s;
    k/=st;
    return s+st*k;
}

void bfs() {
    queue<int> q;
    q.push(n);
    maxs[n]=inf;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            int maxx=L[i]+(K[i]-1)*D[i];
            maxx=min(maxx,maxs[u]-w[i]);
            maxx=go_lower(i,maxx);
            if (maxx>maxs[e[i]]) {
                maxs[e[i]]=max(maxx,maxs[e[i]]);
                q.push(e[i]);
            }
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) maxs[i]=-1;
    while (m--) {
        int l,d,k,c,a,b;
        scanf("%lld %lld %lld %lld %lld %lld",&l,&d,&k,&c,&a,&b);
        add(b,a,c,l,d,k);
    }
    bfs();
    for (int i=1;i<=n-1;++i) {
        if (maxs[i]==-1) puts("Unreachable");
        else printf("%lld\n",maxs[i]);
    }
    return 0;
}

/*
1000000000000000000
999999999000000000
*/