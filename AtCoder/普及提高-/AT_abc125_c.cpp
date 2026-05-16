#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n;
int a[N];
int b[N];
int c[N];
int ans;

int gcd(int a,int b) {
    if (a<b) swap(a,b);
    if (!b) return a;
    return gcd(b,a%b);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    b[1]=a[1];
    c[n]=a[n];
    for (int i=2;i<=n;++i) {
        b[i]=gcd(b[i-1],a[i]);
    }
    for (int i=n-1;i>=1;--i) {
        c[i]=gcd(c[i+1],a[i]);
    }
    ans=max(c[2],b[n-1]);
    for (int i=2;i<=n-1;++i) {
        ans=max(ans,gcd(b[i-1],c[i+1]));
    }
    printf("%d",ans);
    return 0;
}