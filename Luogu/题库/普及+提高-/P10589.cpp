#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int n;
int a[N];
int tr[N];
int gt[N];
int lw[N];
int res1,res2;

int lowbit(int x) {
    return x & -x;
}

void add(int x,int c) {
    for (int i=x;i<=n;i+=lowbit(i)) tr[i]+=c;
}

int sum(int x) {
    int res=0;
    for (int i=x;i;i-=lowbit(i)) res+=tr[i];
    return res;
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
    for (int i=1;i<=n;++i) {
        gt[i]=sum(n)-sum(a[i]);
        lw[i]=sum(a[i]-1);
        add(a[i],1);
    }
    memset(tr,0,sizeof(tr));
    for (int i=n;i>=1;--i) {
        res1+=gt[i]*(sum(n)-sum(a[i]));
        res2+=lw[i]*sum(a[i]-1);
        add(a[i],1);
    }
    printf("%lld %lld",res1,res2);
    return 0;
}