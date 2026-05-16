#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=105;
const int P=15;

int n,p;
int G[N][N];
int task[P];

bool cmp(const int& a,const int& b) {
    return a<b;
}

void floyd() {
    for (int k=1;k<=n;++k) {
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            scanf("%lld",&G[i][j]);
        }
    }
    floyd();
    scanf("%lld",&p);
    for (int i=1;i<=p;++i) scanf("%lld",task+i);
    sort(task+1,task+1+p,cmp);
    int ans=1000000000000000000;
    do {
        int k=0;
        k+=G[1][task[1]];
        for (int i=2;i<=p;++i) {
            k+=G[task[i-1]][task[i]];
        }
        k+=G[task[p]][n];
        ans=min(ans,k);
    } while (next_permutation(task+1,task+1+p));
    printf("%lld",ans);
    return 0;
}