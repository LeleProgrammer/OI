#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=500005;
const int M=500005;

int r,c,d,n,S,T;
int e[M],f[M],ne[M],h[N],tot;
int layer[N],cur[N];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

int gett(int i,int j) {
    return (i-1)*c+j;
}

bool outOfBound(int i,int j,int k) {
    if (i-k<1 || i+k>r || j-k<1 || j+k>c) return true;
    else return false;
}

double get_dis(double a,double b,double c,double d) {
    double x=a-c;
    double y=b-d;
    return sqrt(x*x+y*y);
}

bool bfs() {
    memset(layer,-1,sizeof(layer));
    queue<int> q;
    q.push(S); layer[S]=0; cur[S]=h[S];
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (layer[e[i]]==-1 && f[i]) {
                layer[e[i]]=layer[u]+1;
                cur[e[i]]=h[e[i]];
                if (e[i]==T) return true;
                q.push(e[i]);
            }
        }
    }
    return false;
}

int dfs(int u,int limit) {
    if (u==T) return limit;
    int k=0;
    for (int i=cur[u];~i && k<limit;i=ne[i]) {
        cur[u]=i;
        if (layer[e[i]]==layer[u]+1 && f[i]) {
            int ret=dfs(e[i],min(f[i],limit-k));
            if (!ret) layer[e[i]]=-1;
            k+=ret,f[i]-=ret,f[i^1]+=ret;
        }
    }
    return k;
}

int dinic() {
    int ans=0,k;
    while (bfs()) while (k=dfs(S,inf)) ans+=k;
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d",&r,&c,&d);
    n=r*c; S=0; T=N-1;
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=c;++j) {
            int v;
            scanf("%1d",&v);
            if (v) add(gett(i,j),gett(i,j)+n,v);
        }
    }
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=c;++j) {
            if (outOfBound(i,j,d)) {
                add(gett(i,j)+n,T,inf);
            }
        }
    }
    for (int a=1;a<=r;++a) {
        for (int b=1;b<=c;++b) {
            for (int k=1;k<=r;++k) {
                for (int g=1;g<=c;++g) {
                    if (a==k && b==g) continue;
                    if (get_dis(a,b,k,g)<=d) {
                        add(gett(a,b)+n,gett(k,g),inf);
                    }
                }
            }
        }
    }
    int cnt=0;
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=c;++j) {
            char c;
            scanf(" %c",&c);
            if (c=='L') {
                add(S,gett(i,j),1);
                cnt++;
            }
        }
    }
    printf("%d",cnt-dinic());
    return 0;
}