#include <bits/stdc++.h>
using namespace std;

int four[4];
int two[3];
int ans=0;

int main() {
    for (int i=0;i<4;++i) scanf("%d",&four[i]);
    for (int i=0;i<2;++i) scanf("%d",&two[i]);
    sort(four,four+4,greater<int>());
    sort(two,two+2,greater<int>());
    for (int i=0;i<3;++i) ans+=four[i];
    for (int i=0;i<1;++i) ans+=two[i];
    printf("%d\n",ans);
    return 0;
}