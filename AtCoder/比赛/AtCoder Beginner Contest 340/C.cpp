#include <bits/stdc++.h>

#define int unsigned long long

using namespace std;

int n;
int ans;

signed main() {
    scanf("%llu",&n);
    int l=log2(n);
    ans+=l*n;
    if (n-(1ULL<<l)<=(1ULL<<(l+1ULL)-(1ULL<<l))) ans+=(n-(1ULL<<l))*2ULL;
    else ans+=((1ULL<<(l+1ULL)-n))*2ULL;
    printf("%llu",ans);
    return 0;
}

/*
2: 2
3: 3+2
4: 4+2+2
5: 5+3+2+2
6: 6+3+3+2+2
10: 10+5+5+3+3+2+2+2+2
20:20+10+10+5+5+5+5+2+3+2+3+2+3+2+3
*/