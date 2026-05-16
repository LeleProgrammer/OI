#include <bits/stdc++.h>
using namespace std;

int n,x;
int cnt;

int main() {
    scanf("%d %d",&n,&x);
    for (int i=1;i<=n;++i) {
        int j=i;
        while (j) {
            if (j%10==x) cnt++;
            j/=10;
        }
    }
    printf("%d",cnt);
    return 0;
}