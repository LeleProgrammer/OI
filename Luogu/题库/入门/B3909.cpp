#include <bits/stdc++.h>
using namespace std;

int cnt,maxx,res,maxi;
int n,m,v;

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        cnt=0; maxx=0; res=0; maxi=0;
        for (int j=1;j<=m;++j) {
            scanf("%d",&v);
            if (v) cnt++;
            if (v>maxx) {
                maxx=v;
                maxi=j;
                res=cnt-1;
            }
        }
        printf("%d %d\n",maxi,res);
    }
    return 0;
}