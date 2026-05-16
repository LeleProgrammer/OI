#include <bits/stdc++.h>
using namespace std;

int n;

int pre[100005];

int ans=0;

int main() {
    scanf("%d",&n);
    pre[0]=0;
    for (int i=1;i<=n;++i) {
        int val;
        scanf("%d",&val);
        pre[i]=pre[i-1]+val;
    }
    for (int i=1;i<=n-1;++i) { // seperate after i
        if (pre[i]==pre[n]-pre[i]) ans++;
    }
    printf("%d",ans);
    return 0;
}