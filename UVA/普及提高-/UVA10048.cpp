#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;

const int N=105;
const int M=2005;

typedef pair<int,int> pii;

int n,m,Q;
int c1,c2,d;
int G[N][N];
int T;

int main() {
    while (scanf("%d %d %d",&n,&m,&Q),n) {
        if (T) putchar(10);
        for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) G[i][j]=inf;
        while (m--) {
            scanf("%d %d %d",&c1,&c2,&d);
            G[c1][c2]=G[c2][c1]=min(G[c1][c2],d);
        }
        for (int k=1;k<=n;++k) {
            for (int i=1;i<=n;++i) {
                for (int j=1;j<=n;++j) {
                    G[i][j]=min(G[i][j],max(G[i][k],G[k][j]));
                }
            }
        }
        printf("Case #%d\n",++T);
        while (Q--) {
            scanf("%d %d",&c1,&c2);
            if (G[c1][c2]==inf) puts("no path");
            else printf("%d\n",G[c1][c2]);
        }
    }
    return 0;
}