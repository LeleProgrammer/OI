#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,now;
int arr[105];

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i) {
        scanf("%d %d",&a,&b);
        arr[a]++;
        arr[b+1]--;
    }
    int now=0;
    for (int i=1;i<=n;++i) {
        now+=arr[i];
        if (now!=1) {
            printf("%d %d",i,now);
            return 0;
        }
    }
    printf("OK");
    return 0;
}