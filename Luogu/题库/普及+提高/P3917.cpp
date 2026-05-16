#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=35;

int n;
int arr[N];
int num[M][N];
int one[M][N],zero[M][N];
int ans,sum;

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
        sum+=arr[i];
    }
    for (int i=1;i<=n;++i) {
        int k=arr[i];
        int idx=0;
        while (k) {
            num[++idx][i]=k&1;
            k>>=1;
        }
    }
    for (int i=1;i<=31;++i) {
        for (int j=1;j<=n;++j) {
            if (num[i][j]) {
                zero[i][j]=one[i][j-1];
                one[i][j]=zero[i][j-1]+1;
            } else {
                zero[i][j]=zero[i][j-1]+1;
                one[i][j]=one[i][j-1];
            }
        }
        int sum=0;
        for (int j=1;j<=n;++j) {
            if (num[i][j]==1) one[i][j]--;
            else zero[i][j]--;
            sum+=one[i][j];
            // cout<<zero[i][j]<<" "<<one[i][j]<<" "<<num[i][j]<<endl;
        }
        ans+=(1<<(i-1))*sum;
        // cout<<sum<<endl;
    }
    printf("%lld",ans+sum);
    return 0;
}