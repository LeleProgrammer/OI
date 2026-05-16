#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,m;
int a[100005];
int tr[100005];
char op[2];
int l,r,d;

int lowbit(int x) {
    return x & -x;
}

void add(int x,int d) {
    for (int i=x;i<=n;i+=lowbit(i)) tr[i]+=d;
}

int sum(int x) {
    int res=0;
    for (int i=x;i;i-=lowbit(i)) res+=tr[i];
    return res;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
    }
    for (int i=1;i<=n;++i) {
        add(i,a[i]-a[i-1]);
    }
    while (m--) {
        scanf("%s",op);
        if (op[0]=='Q') {
            scanf("%lld",&d);
            printf("%lld\n",sum(d));
        } else {
            scanf("%lld %lld %lld",&l,&r,&d);
            add(l,d);
            add(r+1,-d);
        }
    }
    return 0;
}