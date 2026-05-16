#include <bits/stdc++.h>
using namespace std;

const int N=205;
const int M=1605;
const int inf=100000000;

int n,m,S,T;
int e[M],ne[M],h[N],w[M],tot;
double f[M];
int layer[N],cur[N];
double eps=0.00000001;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,w[tot]=c,ne[tot]=h[b],h[b]=tot++;
}

bool bfs() {
    memset(layer,-1,sizeof(layer));
    queue<int> q;
    q.push(S); layer[S]=0; cur[S]=h[S];
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (layer[e[i]]==-1 && f[i]>0) {
                layer[e[i]]=layer[u]+1;
                cur[e[i]]=h[e[i]];
                if (e[i]==T) return true;
                q.push(e[i]);
            }
        }
    }
    return false;
}

double dfs(int u,double limit) {
    if (u==T) return limit;
    double k=0;
    for (int i=cur[u];~i && k<limit;i=ne[i]) {
        cur[u]=i;
        if (layer[e[i]]==layer[u]+1 && f[i]>0) {
            double ret=dfs(e[i],min(f[i],limit-k));
            if (ret<eps) layer[e[i]]=-1;
            k+=ret,f[i]-=ret,f[i^1]+=ret;
        }
    }
    return k;
}

double dinic(double mid) {
    double ans=0;
    for (int i=0;i<tot;i+=2) {
        if (w[i]<=mid) {
            ans+=w[i]-mid;
            f[i]=f[i^1]=0;
        } else {
            f[i]=f[i^1]=w[i]-mid;
        }
    }
    double ans2=0,k;
    while (bfs()) while (k=dfs(S,inf)) ans2+=k;
    return ans+ans2;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d %d",&n,&m,&S,&T);
    while (m--) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c);
    }
    double l=0,r=10000000;
    while (r-l>eps) {
        double mid=(l+r)/2;
        if (dinic(mid)<0) r=mid;
        else l=mid;
    }
    printf("%.2lf",r);
    return 0;
}