#include <bits/stdc++.h>
using namespace std;

const int N=85;
const int M=10005;
const int inf=1e7;

int n,x,y;
int f[M][N];

struct node {
    int a,b;
} arr[N];

int main() {
    scanf("%d %d %d",&n,&x,&y);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&arr[i].a,&arr[i].b);
    }
    for (int i=0;i<M;++i) {
        for (int j=0;j<N;++j) {
            f[i][j]=inf;
        }
    }
    f[0][0]=0;
    for (int i=1;i<=n;++i) {
        for (int j=x;j-arr[i].a>=0;--j) {
            for (int k=1;k<=i;++k) {
                f[j][k]=min(f[j][k],f[j-arr[i].a][k-1]+arr[i].b);
            }
        }
        // cout<<i<<": "<<endl;
        // for (int j=0;j<=x;++j) {
        //     printf("f[%d][%d] = %d\n",j,i,f[j][i]);
        // }
    }
    for (int i=n;~i;--i) {
        for (int j=0;j<=x;++j) {
            if (f[j][i]<=y) {
                if (i==n) i--;
                printf("%d",i+1);
                return 0;
            }
        }
    }
    printf("0");
    return 0;
}