#include <bits/stdc++.h>
using namespace std;

const int N=505;
const int M=10005;
const int inf=2e9;

int T,E,F,n;
int val[N],cost[N];
int f[M];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&E,&F);
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            scanf("%d %d",&val[i],&cost[i]);
        }
        for (int i=1;i<=F-E;++i) f[i]=inf;
        f[0]=0;
        for (int i=1;i<=n;++i) {
            for (int j=cost[i];j<=F-E;++j) {
                f[j]=min(f[j],f[j-cost[i]]+val[i]);
            }
        }
        if (f[F-E]>=1e9) puts("This is impossible.");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",f[F-E]);
    }
    return 0;
}