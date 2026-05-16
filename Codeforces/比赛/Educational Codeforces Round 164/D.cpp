#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=5005;
const int mod=998244353;

int n;
int a[N];

bool cmp(const int& a,const int& b) {
    return a<b;
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
}

/*
4
1 3 3 7

1 3 3 7
3 3 7 3 7 7
4 7 7 7
7

1 3 3 7
3 3 7
3 7 7
4 7
7 7
7

76

===

3
1 1 2

1*3
2*4

11

===

4
1 3 3 7

1*1
3*5
4*1
7*8

1+17+4+56

===

3 3 3 1
3 3 2 0
3 2 1 0
2 2 0 0
1 1 0 0
0 0 0 0

5

3 3 3 2 2 1
3 3 2 2 2 0
3 2 2 2 1 0
2 2 2 2 0 0
2 2 1 1 0 0
1 1 1 1 0 0
1 1 0 0 0 0
0 0 0 0 0 0

7
*/