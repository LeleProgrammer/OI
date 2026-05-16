#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=105;

int T,n,l,h;

struct node {
    int t,l,h;
    friend bool operator < (const node& a,const node& b) {
        return a.t<b.t;
    }
} arr[N];

bool have(int a,int b,int c,int d) {
    if ((a>=c && a<=d) || (b>=c && b<=d) || (a<c && b>d)) return true;
    else return false;
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld",&n,&l);
        h=l;
        for (int i=1;i<=n;++i) {
            scanf("%lld %lld %lld",&arr[i].t,&arr[i].l,&arr[i].h);
        }
        sort(arr+1,arr+1+n);
        bool ok=true;
        int now=0;
        for (int i=1;i<=n;++i) {
            int delta=arr[i].t-now;
            h+=delta,l-=delta;
            if (!have(l,h,arr[i].l,arr[i].h)) {
                ok=false;
                break;
            }
            l=max(l,arr[i].l);
            h=min(h,arr[i].h);
            now=arr[i].t;
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}