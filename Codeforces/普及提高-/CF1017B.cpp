#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;

int n;
int a[N];
int b[N];
int zero_zero,one_one,one_zero,zero_one;

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) scanf("%1lld",&a[i]);
    for (int i=1;i<=n;++i) scanf("%1lld",&b[i]);
    for (int i=1;i<=n;++i) {
        if (a[i]==b[i] && b[i]==0) zero_zero++;
        else if (a[i]==b[i] && b[i]==1) one_one++;
        else if (a[i]==1 && b[i]==0) one_zero++;
        else if (a[i]==0 && b[i]==1) zero_one++;
    }
    printf("%lld",zero_zero*one_zero+zero_zero*one_one+zero_one*one_zero);
    return 0;
}

/*
01
00

01
01

01
10
*/