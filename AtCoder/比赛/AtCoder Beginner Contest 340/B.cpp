#include <bits/stdc++.h>
using namespace std;

const int N=105;

int a[N],cnt;
int q,op,k;

int main() {
    scanf("%d",&q);
    while (q--) {
        scanf("%d %d",&op,&k);
        if (op==1) {
            a[++cnt]=k;
        } else {
            printf("%d\n",a[cnt-k+1]);
        }
    }
    return 0;
}