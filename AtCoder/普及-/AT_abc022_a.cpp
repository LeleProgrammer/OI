#include <bits/stdc++.h>
using namespace std;

int n,s,t;
int k;
int ans;

int main() {
    scanf("%d %d %d",&n,&s,&t);
    while (n--) {
        int v;
        scanf("%d",&v);
        k+=v;
        if (k>=s && k<=t) ans++;
    }
    printf("%d\n",ans);
    return 0;
}