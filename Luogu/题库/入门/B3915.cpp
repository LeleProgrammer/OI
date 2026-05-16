#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int cnt;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    int i;
    for (i=1;i<n;i+=a[i]) {
        cnt++;
    }
    if (i==n) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    printf("%d\n",cnt);
    return 0;
}