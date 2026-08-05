#include <bits/stdc++.h>
using namespace std;

int arr[100005],dp[100005];

int main() {
    int n;
    int i=0;
    while (cin>>arr[i]) {
        ++i;
    }
    n=i;
    int maxx=0;
    dp[0]=1;
    for (i=1;i<n;++i) {
        dp[i]=0;
        for (int j=0;j<i;++j) {
            if (arr[j]>=arr[i] && dp[j]>=dp[i]) {
                dp[i]=dp[j]+1;
                if (dp[i]>maxx) {
                    maxx=dp[i];
                }
            }
        }
    }
    printf("%d\n",maxx);
    int sys=0,remaining=n,biggest;
    while (remaining) {
        biggest=-1;
        for (i=n-1;i>=0;--i) {
            if (arr[i]==-1) {
                continue;
            }
            if (arr[i]>=biggest) {
                biggest=arr[i];
                arr[i]=-1;
                --remaining;
            }
        }
        ++sys;
    }
    printf("%d",sys);
    return 0;
}

// test
// 7  8  3  4  3  7  2  1  r=8  sys=0
// 7  x  3  4  3  x  x  x  r=4  sys=1
// x  x  3  x  x  x  x  x  r=1  sys=2
// x  x  x  x  x  x  x  x  r=0  sys=3
// sys=3