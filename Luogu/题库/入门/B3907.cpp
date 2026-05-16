#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,k;
int cnt=0;

signed main() {
    scanf("%lld %lld",&n,&k);
    long long maxx=pow((long long)n,(long long)n);
    for (int x=n;x<=maxx;x+=10) {
        if ((x%k)%n==0) cnt++;
    }
    printf("%lld",cnt);
    return 0;
}

/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
4 6

*/