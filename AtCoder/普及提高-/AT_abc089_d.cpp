#include <bits/stdc++.h>
using namespace std;

const int N=90505;
const int M=1000005;

typedef pair<int,int> pii;

int n,m,d,Q;
int arr[305][305];
int dis[305][305];
int f[N];
pii s[N];

int get(int i,int j) {
    return (i-1)*m+j;
}

int get_dis(int a,int b,int c,int d) {
    return abs(a-c)+abs(b-d);
}

int main() {
    scanf("%d %d %d",&n,&m,&d);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf("%d",&arr[i][j]);
            s[arr[i][j]]={i,j};
        }
    }
    scanf("%d",&Q);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (arr[i][j]+d>n*m) continue;
            dis[i][j]=get_dis(i,j,s[arr[i][j]+d].first,s[arr[i][j]+d].second);
        }
    }
    for (int i=d;i<=n*m;++i) {
        auto t=s[i-d];
        int a=t.first,b=t.second;
        f[i]=f[i-d]+dis[a][b];
    }
    while (Q--) {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",f[b]-f[a]);
    }
    return 0;
}