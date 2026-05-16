#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=300005;

int T;
int n,k;
int a[N];
int x[N];
int arr[N];

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld",&n,&k);
        for (int i=1;i<=n;++i) arr[i]=0,a[i]=0,x[i]=0;
        for (int i=1;i<=n;++i) {
            scanf("%lld",&a[i]);
        }
        for (int i=1;i<=n;++i) {
            scanf("%lld",&x[i]);
        }
        for (int i=1;i<=n;++i) {
            arr[abs(x[i])]+=a[i];
        }
        int now;
        for (now=1;now<=n && !arr[now];++now);
        bool ok=true;
        for (int i=0;i<=n;++i) {
            if (i>=now) {
                ok=false;
                break;
            }
            if (arr[now]>k) {
                arr[now]-=k;
            } else if (arr[now]==k) {
                arr[now]-=k;
                now++;
            } else {
                int rem=k;
                while (rem && now<=n) {
                    if (rem>arr[now]) {
                        rem-=arr[now];
                        arr[now]=0;
                        now++;
                    } else if (rem==arr[now]) {
                        rem=arr[now]=0;
                        now++;
                    } else {
                        arr[now]-=rem;
                        rem=0;
                    }
                }
            }
            if (now>n) break;
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}