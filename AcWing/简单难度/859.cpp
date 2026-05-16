#include <bits/stdc++.h>

#define inf 0x7fffffff

using namespace std;

int n,m;
int a,b,c;

struct edge {
    int a,b,w;
    friend bool operator < (const edge& a,const edge& b) {
        return a.w<b.w;
    }
} e[200005];

int p[100005]; //  p[i] i的祖先

int search(int x) {
    if (p[x]!=x) return p[x]=search(p[x]); // 有祖先就往祖先查找，并将一路经过的点的最原始的祖先更新
    return p[x]; // 自己是祖先，就返回
}

int kruskal() {
    sort(e+1,e+1+m); // 排序
    for (int i=1;i<=n;++i) p[i]=i; // 原先没有祖先
    int cnt=0,res=0; // cnt 表示查询过的点数 res 表示生成树的边权之和
    for (int i=1;i<=m;++i) { // 枚举每一条边
        a=e[i].a;
        b=e[i].b;
        c=e[i].w;
        a=search(a); // a 最原先的祖先
        b=search(b); // b 最原先的祖先
        if (a!=b) { // 最原先的祖先不同，说明两点没有连通
            res+=c;
            p[a]=b; // b 的祖先不变，a 的祖先更新为b，也可以反过来写
            cnt++;
        }
    }
    if (cnt<n-1) return inf;
    else return res;
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i) {
        scanf("%d %d %d",&a,&b,&c);
        e[i].a=a;
        e[i].b=b;
        e[i].w=c;
    }
    int ans=kruskal();
    if (ans==inf) {
        printf("impossible");
    } else {
        printf("%d",ans);
    }
    return 0;
}