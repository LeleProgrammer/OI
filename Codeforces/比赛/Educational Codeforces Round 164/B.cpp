#include <bits/stdc++.h>
using namespace std;

const int N=300005;

int T,n,a[N];
int b[N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            scanf("%d",&a[i]);
        }
        bool ok=false;
        for (int i=2;i<=n;++i) {
            if (a[i]!=a[1]) {
                ok=true;
                break;
            }
        }
        if (!ok) {
            puts("-1");
            continue;
        }
        if (a[1]!=a[n]) {
            puts("0");
            continue;
        }
        // int l=1,r=n;
        // bool dif=false;
        // while (l<r) {
        //     while (a[l+1]==a[l]) l++;
        //     while (a[r-1]==a[r]) r--;
        //     if (l==r) break;
        //     if ((a[l+1]!=a[l] || a[r-1]!=a[r]) && l!=r-2) dif=true;
        //     l++,r--;
        // }
        // if (dif) puts("1");
        // else {
        //     int llen=1,rlen=1;
        //     for (int i=2;i<=n;++i) {
        //         if (a[i]==a[1]) llen++;
        //         else break;
        //     }
        //     for (int i=n-1;i>=1;--i) {
        //         if (a[i]==a[n]) rlen++;
        //         else break;
        //     }
        //     printf("%d\n",min(llen,rlen));
        // }
        // int l,r;
        // for (l=2;l<=n;++l) if (a[l]!=a[1]) break; l--;
        // for (r=2;r<=n;++r) if (a[n-r+1]!=a[n]) break; r--;
        // if (l+r+1==n) printf("%d\n",min(l,r));
        // else puts("1");
        int t=a[1];
        int ans=n;
        int i=1;
        while (i<=n) {
            if (a[i]!=t) {
                i++;
                continue;
            }
            int len=0;
            for (;i<=n;++i) {
                if (a[i]==t) len++;
                else break;
            }
            ans=min(ans,len);
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
10
3 3 3 5 3 3 3 3 3 3

x [] x

5 5 1 1 1 1 3 4 2 4 4 3 3 1 1 5 5 5 5
5 1 1 1 1 3 4 2 4 4 3 3 1 1 5
1 3 4 2 4 4 3 3 1
3 4 2 4 4 3
4 2 4
2

1 2 2 3 2 2 2 1 2 1 2 2 3 3 3 3 2 1
2 3 2 2 2 1 2 1 2 2 3 3 3 3 2
3 2 2 2 1 2 1 2 2 3
2 1 2 1 2
1 2 1
2

14
1 1 1 2 1 1 2 1 1 3 1 1 1 1
1 2 1 1 2 1 1 3 1
1 2 2 1 2 1 1 3 1

1 1 1 1 1 1 2 1 2 1 1 1 2 1 1 2 1 1 1 1
1 2 1 2 1 1 1 2 1 1 2 1
*/