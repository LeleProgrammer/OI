#include <bits/stdc++.h>
using namespace std;

const int N=25;

int n;
int a[N];

int gcd(int a,int b) {
    if (!b) return a;
    return gcd(b,a%b);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        a[i]=abs(a[i]);
    }
    int ans=a[1];
    for (int i=2;i<=n;++i) ans=gcd(ans,a[i]);
    printf("%d",ans);
    return 0;
}