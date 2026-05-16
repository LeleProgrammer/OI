#include <bits/stdc++.h>
using namespace std;

const int N=15005;

int T,n,q;
int a[N];
int ne[N];
int b[15];

void init() {
    memset(ne,0,sizeof(ne));
    memset(b,0,sizeof(b));
    for (int i=1;i<=n;++i) {
        if (b[a[i]]) {
            ne[b[a[i]]]=i;
        }
        b[a[i]]=i;
    }
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            scanf("%d",&a[i]);
        }
        init();
        scanf("%d",&q);
        while (q--) {
            int l,r;
            scanf("%d %d",&l,&r);
            int ans=0;
            for (int i=l;i<=r;++i) {
                if (ne[i] && ne[i]<=r) {
                    i=ne[i];
                } else {
                    ans++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}