#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    long long res=1;
    for (int i=0;i<b;++i) {
        res*=a;
        if (res>1000000000) {
            printf("-1");
            return 0;
        }
    }
    printf("%lld",res);
    return 0;
}