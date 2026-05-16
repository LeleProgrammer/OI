#include <bits/stdc++.h>
using namespace std;

const int N=25;

int T,n;
char a[N],b[N],c[N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        scanf("%s %s %s",a,b,c);
        bool ok=false;
        for (int i=0;i<n;++i) {
            if (a[i]==b[i] && a[i]==c[i]) continue;
            else if (a[i]==c[i] || b[i]==c[i]) continue;
            else {
                ok=true;
                printf("YES\n");
                break;
            }
        }
        if (!ok) printf("NO\n");
    }
    return 0;
}