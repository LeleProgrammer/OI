#include <bits/stdc++.h>
using namespace std;

const int N=55;

int n;
int a[N];
int ans=1;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    if (a[1]>0) {
        for (int i=2;i<=n;++i) if (abs(a[i])>a[1] && a[i]<0) ans++;
        if (ans!=1) for (int i=2;i<=n;++i) if (abs(a[i])<a[1] && a[i]>0) ans++;
    } else {
        for (int i=2;i<=n;++i) if (abs(a[i])<-a[1] && a[i]>0) ans++;
        if (ans!=1) for (int i=2;i<=n;++i) if (abs(a[i])>-a[1] && a[i]<0) ans++;
    }
    printf("%d",ans);
    return 0;
}