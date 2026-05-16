#include <bits/stdc++.h>
using namespace std;

int n;
int a;
int res;

int main() {
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&a);
        res=a;
        for (int i=2;i<=sqrt(a);++i) {
            if (a%i==0) {
                res=res/i*(i-1);
                while (a%i==0) a/=i;
            }
        }
        if (a>=2) {
            res=res/a*(a-1);
        }
        printf("%d\n",res);
    }
    return 0;
}