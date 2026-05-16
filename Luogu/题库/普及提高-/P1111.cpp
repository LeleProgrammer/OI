#include <bits/stdc++.h>
using namespace std;

const int N=1005;
const int M=100005;

int n,m;

struct node {
    int x,y,t;
    friend bool operator < (const node& a,const node& b) {
        return a.t<b.t;
    }
} arr[M];

int p[N];

int fd(int x) {
    if (p[x]!=x) p[x]=fd(p[x]);
    return p[x];
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) p[i]=i;
    for (int i=1;i<=m;++i) {
        scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].t);
    }
    sort(arr+1,arr+1+m);
    for (int i=1;i<=m;++i) {
        p[fd(arr[i].x)]=fd(arr[i].y);
        int j,tmp;
        for (j=2,tmp=fd(1);fd(j)==fd(tmp) && j<=n;++j);
        if (j==n+1) {
            printf("%d",arr[i].t);
            return 0;
        }
    }
    printf("-1");
    return 0;
}