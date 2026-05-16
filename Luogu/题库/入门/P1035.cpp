#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    scanf("%d",&k);
    double ans=0;
    for (double i=1.0;i<=1919810;++i) {
        ans+=1.0/i;
        if (ans>k) {
            printf("%d",(int)i);
            return 0;
        }
    }
    return 0;
}