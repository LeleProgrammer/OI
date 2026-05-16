#include <bits/stdc++.h>
using namespace std;

int n,arr[105];
int cnt,maxx=-1;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",arr+i);
    }
    for (int len=1;len<=n;++len) {
        for (int l=1,r=l+len-1;r<=n;++l,++r) {
            cnt=0;
            for (int i=1;i<=n;++i) {
                if (i>=l && i<=r) {
                    cnt+=(1-arr[i]);
                } else {
                    cnt+=arr[i];
                }
            }
            maxx=max(maxx,cnt);
        }
    }
    printf("%d",maxx);
    return 0;
}