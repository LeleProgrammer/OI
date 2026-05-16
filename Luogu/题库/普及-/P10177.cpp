#include <bits/stdc++.h>
using namespace std;

const int N=1000005;

int n;
int a[N];
int ans=-2000000000;

bool cmp(const int a,const int b) {
    return a<b;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n-1;++i) {
        ans=max(ans,a[i]-a[i+1]);
    }
    printf("%d",ans);
    return 0;
}