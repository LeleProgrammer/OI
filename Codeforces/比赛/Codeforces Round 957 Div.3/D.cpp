#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int inf=1e8;

int T,n,m,k;
int arr[N];
int f[N];

int main() {
    scanf("%d",&T);
    arr[0]=2; // log
    while (T--) {
        scanf("%d %d %d",&n,&m,&k);
        for (int i=1;i<=n;++i) {
            char c;
            scanf(" %c",&c);
            if (c=='W') arr[i]=0; // water
            else if (c=='C') arr[i]=1; // crocodile
            else arr[i]=2; // log
        }
        arr[n+1]=2; // log
        for (int i=0;i<=n+1;++i) f[i]=inf;
        f[0]=0;
        for (int i=1;i<=n+1;++i) {
            if (arr[i]==1) continue; // crocodile
            if (arr[i-1]==0) { // swim
                f[i]=min(f[i],f[i-1]+1);
            }
            for (int j=1;j<=m;++j) {
                if (i-j<0) continue; // exceed
                if (arr[i-j]==2) { // log
                    f[i]=min(f[i],f[i-j]);
                }
            }
        }
        if (f[n+1]>k) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
    return 0;
}