#include <bits/stdc++.h>
using namespace std;

const int N=400005;
const int M=400005;

int T,n,m,k;
int a[N],b[M];
bool fa[N],fb[M];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d %d",&n,&m,&k);
        for (int i=1;i<=n;++i) scanf("%d",a+i);
        for (int i=1;i<=m;++i) scanf("%d",b+i);
        memset(fa,0,sizeof(fa));
        memset(fb,0,sizeof(fb));
        for (int i=1;i<=n;++i) {
            if (a[i]<=k) {
                fa[a[i]]=true;
            }
        }
        for (int i=1;i<=m;++i) {
            if (b[i]<=k) {
                fb[b[i]]=true;
            }
        }
        int cnta=0,cntb=0,both=0;
        bool ok=true;
        for (int i=1;i<=k;++i) {
            if (fa[i] && !fb[i]) cnta++;
            else if (fb[i] && !fa[i]) cntb++;
            else if (fa[i] && fb[i]) both++;
            else {
                ok=false;
                break;
            }
        }
        if (cnta>k/2 || cntb>k/2 || !ok) {
            puts("NO");
            continue;
        }
        if (cntb+(both-(k/2-cnta))==k/2) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}