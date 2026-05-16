#include <bits/stdc++.h>
using namespace std;

int n,k;
int cnt;
int curr;

int main() {
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i) {
        int a;
        scanf("%d",&a);
        if (curr+a>k) cnt++,curr=0;
        curr+=a;
    }
    cnt++;
    printf("%d",cnt);
    return 0;
}