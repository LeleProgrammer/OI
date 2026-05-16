#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d",&n);
    int sum=0;
    int i;
    for (i=1;i<=n;++i) {
        if (sum+i>=n) break;
        sum+=i;
    }
    int k=n-sum;
    if (i%2) {
        printf("%d/%d",i-k+1,k);
    } else {
        printf("%d/%d",k,i-k+1);
    }
    return 0;
}