#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,e;
int ans;

int main() {
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    if (a<0) {
        ans+=(-a)*c;
        ans+=d;
        a=0;
    }
    ans+=(b-a)*e;
    printf("%d\n",ans);
    return 0;
}