#include <bits/stdc++.h>
using namespace std;

int a;
int ans;

int main() {
    scanf("%d",&a);
    a--;
    ans=(1+2*a-1)*a/2*6+6*a;
    ans++;
    printf("%d",ans);
    return 0;
}