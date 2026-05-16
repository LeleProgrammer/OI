#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=400005;
const int M=1000005;

int n,m,ans;
int arr[N];
int pre[N];
int cnt[M];

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
        arr[i+n]=arr[i];
    }
    for (int i=1;i<=n*2-1;++i) {
        pre[i]=pre[i-1]+arr[i];
    }
    for (int i=0;i<=n*2-1;++i) {
        if (i-n>=0) cnt[pre[i-n]%m]--;
        ans+=cnt[pre[i]%m];
        if (i<=n-1) cnt[pre[i]%m]++;
        // for (int i=0;i<m;++i) {
        //     printf("%d ",cnt[i]);
        // }
        // printf("%d %d",ans,pre[i]);
        // putchar(10);
    }
    printf("%lld",ans);
    return 0;
}