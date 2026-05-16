#include <bits/stdc++.h>
using namespace std;

int n;
int ans,days;

int main() {
    scanf("%d",&n);
    while (n) {
        ++days;
        if (n%3==1 && !ans) ans=days;
        if (n%3) n-=n/3+1;
        else n-=n/3;
    }
    printf("%d %d",days,ans);
    return 0;
}