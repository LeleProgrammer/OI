#include <bits/stdc++.h>
using namespace std;

const int N=105;

int n;
int p[N];
int pos[N];
int q;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&p[i]);
        pos[p[i]]=i;
    }
    scanf("%d",&q);
    while (q--) {
        int a,b;
        scanf("%d %d",&a,&b);
        if (pos[a]<pos[b]) printf("%d\n",a);
        else printf("%d\n",b);
    }
    return 0;
}