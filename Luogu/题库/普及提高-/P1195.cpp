#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int n,m,k;
int x,y,l;

struct edge {
    int a;
    int b;
    int w;
    friend bool operator < (const edge& a,const edge &b) {
        return a.w<b.w;
    }
} e[10005];

int p[10005];

int search(int x) {
    if (p[x]!=x) p[x]=search(p[x]);
    return p[x];
}

int kruskal() {
    sort(e+1,e+1+m);
    for (int i=1;i<=n;++i) p[i]=i;
    int cnt=0,tot=0;
    for (int i=1;i<=m;++i) {
        if (cnt>=n-k) break;
        int fa,fb;
        fa=search(e[i].a);
        fb=search(e[i].b);
        if (fa!=fb) {
            p[fa]=fb;
            tot+=e[i].w;
            cnt++;
        }
    }
    if (cnt<n-k) return inf;
    return tot;
}

int main() {
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=m;++i) {
        scanf("%d %d %d",&x,&y,&l);
        e[i].a=x;
        e[i].b=y;
        e[i].w=l;
    }
    int ans=kruskal();
    if (ans==inf) {
        puts("No Answer");
    } else {
        printf("%d",ans);
    }
    return 0;
}