#include <bits/stdc++.h>
using namespace std;

int n;
int ans=2e9;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=3;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        int k=n/a;
        if (n%a) k++;
        ans=min(ans,b*k);
    }
    printf("%d",ans);
    return 0;
}