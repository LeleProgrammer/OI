#include <bits/stdc++.h>
using namespace std;

const int N=55;

int n,m;

struct node {
    int x,y;
};

node a[N],b[N];

int dis(node a,node b) {
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    for (int i=1;i<=m;++i) {
        scanf("%d %d",&b[i].x,&b[i].y);
    }
    for (int i=1;i<=n;++i) {
        int ans=1;
        for (int j=2;j<=m;++j) {
            if (dis(a[i],b[j])<dis(a[i],b[ans])) ans=j;
        }
        printf("%d\n",ans);
    }
    return 0;
}