#include <bits/stdc++.h>
using namespace std;

int prefix[200005];

int main() {
    int n;
    scanf("%d",&n);
    prefix[0]=0;
    int in;
    for (int i=1;i<=n;++i) {
        scanf("%d",&in);
        prefix[i]=prefix[i-1]+in;
    }
    int maxx=-0x7fffffff;
    for (int len=1;len<=n;++len) {
        for (int start=1;start+len-1<=n;++start) {
            maxx=max(prefix[start+len-1]-prefix[start-1],maxx);
        }
    }
    printf("%d",maxx);
    return 0;
}