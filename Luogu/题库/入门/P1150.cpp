#include <bits/stdc++.h>
using namespace std;

int n,k,ans=0;

int main() {
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i) {
        ans++;
        if (i%k==0) n++;
    }
    printf("%d",ans);
    return 0;
}