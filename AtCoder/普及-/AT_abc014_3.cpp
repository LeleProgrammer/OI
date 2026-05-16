#include <bits/stdc++.h>
using namespace std;

int n,now=0,maxx=0;

int arr[1000005];

int main() {
    memset(arr,0,sizeof(arr));
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a]++;
        arr[b+1]--;
    }
    for (int i=0;i<=1000000;++i) {
        now+=arr[i];
        maxx=max(maxx,now);
    }
    printf("%d\n",maxx);
    return 0;
}