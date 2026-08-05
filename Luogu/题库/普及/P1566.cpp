#include <bits/stdc++.h>
using namespace std;

const int N=35;
const int K=1005;

int t,n;
int f[N*K];
int arr[N];
int res;

int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d",arr+i);
        sort(arr+1,arr+1+n);
        memset(f,0,sizeof(f));
        f[0]=1; res=0;
        for (int i=1;i<=n;++i) {
            res+=f[arr[i]];
            for (int j=1000;j>=arr[i];--j) {
                f[j]+=f[j-arr[i]];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}