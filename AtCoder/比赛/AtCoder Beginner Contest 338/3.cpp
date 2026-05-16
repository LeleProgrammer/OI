#include <bits/stdc++.h>
using namespace std;

const int N=15;

int n;
int a[N],b[N];
int q[N];
int ans=0;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&q[i]);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1;i<=n;++i) scanf("%d",&b[i]);
    int cnta,cntb;
    cnta=-1; cntb=0;
    while (true) {
        cnta++;
        if (cnta) {
            bool ok=true;
            for (int i=1;i<=n;++i) {
                q[i]-=a[i];
                if (q[i]<0) {
                    ok=false;
                    break;
                }
            }
            if (!ok) break;
        }
        int minn=0x3f3f3f3f;
        for (int i=1;i<=n;++i) {
            if (b[i]==0) continue;
            minn=min(minn,q[i]/b[i]);
        }
        cntb=(minn==0x3f3f3f3f?0:minn);
        ans=max(ans,cnta+cntb);
    }
    printf("%d\n",ans);
    return 0;
}