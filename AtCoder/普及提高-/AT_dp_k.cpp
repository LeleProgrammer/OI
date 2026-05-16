#include <bits/stdc++.h>
using namespace std;

const int N=105;
const int K=100005;

int n,k;
int a[N];
int f[K];

int main() {
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=k;++i) {
        for (int j=1;j<=n;++j) {
            if (i-a[j]<0) continue;
            if (!f[i-a[j]]) {
                f[i]=1;
                break;
            }
        }
    }
    if (f[k]) puts("First");
    else puts("Second");
    return 0;
}