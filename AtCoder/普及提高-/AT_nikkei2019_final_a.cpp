#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
int arr[3005];
int pre[3005];
int result;

signed main() {
    scanf("%lld",&n);
    pre[0]=0;
    for (int i=1;i<=n;++i) {
        scanf("%lld",arr+i);
        pre[i]=pre[i-1]+arr[i];
    }
    for (int len=1;len<=n;++len) {
        result=0;
        for (int l=1,r=l+len-1;r<=n;++l,++r) {
            result=max(result,pre[r]-pre[l-1]);
        }
        printf("%lld\n",result);
    }
    return 0;
}