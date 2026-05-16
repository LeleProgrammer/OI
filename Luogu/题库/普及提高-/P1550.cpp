#include <bits/stdc++.h>
using namespace std;

const int N=305;

int n;
int w[N];

struct edge {
    int a,b,w;
    friend bool operator < (const edge& a,const edge& b) {
        return a.w<b.w;
    }
} e[N*N];

int tot;

int p[N];

int search(int x) {
    if (x==p[x]) return x;
    else return p[x]=search(p[x]);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&w[i]);
        e[++tot]={i,n+1,w[i]};
        e[++tot]={n+1,i,w[i]};
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            int v;
            scanf("%d",&v);
            if (i==j) continue;
            e[++tot].a=i;
            e[tot].b=j;
            e[tot].w=v;
        }
    }
    sort(e+1,e+1+tot);
    for (int i=1;i<=n;++i) p[i]=i;
    int res=0;
    for (int i=1;i<=tot;++i) {
        int a,b;
        a=search(e[i].a);
        b=search(e[i].b);
        if (a!=b) {
            res+=e[i].w;
            p[a]=b;
        }
    }
    printf("%d\n",res);
    return 0;
}