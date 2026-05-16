#include <bits/stdc++.h>
using namespace std;

int T,ans;

int main() {
    scanf("%d",&T);
    while (T--) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        ans=0;
        for (int i=0;i<=5;++i) {
            for (int j=0;j<=5;++j) {
                for (int k=0;k<=5;++k) {
                    if (i+j+k>5) continue;
                    ans=max(ans,(a+i)*(b+j)*(c+k));
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}