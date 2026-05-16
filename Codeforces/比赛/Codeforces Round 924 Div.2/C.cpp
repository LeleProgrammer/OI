#include <bits/stdc++.h>
using namespace std;

int T,x,n;

unordered_set<int> s;

bool ok(int a) {
    if (a/2+1>=n && a/2+1<=x && a%2==0) return true;
    else return false;
}

void fj(int k) {
    for (int i=1;i<=sqrt(k);++i) {
        if (k%i) continue;
        if (ok(i)) s.insert(i);
        if (ok(k/i)) s.insert(k/i);
    }
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&x,&n);
        s.clear();
        fj(x-n); fj(x+n-2);
        printf("%d\n",s.size());
    }
    return 0;
}

/*
x mod y = n or y-n

x mod y = n >>>>>> (x-n) 的因数 (>=2 and g/2+1>=n and %2==0 and g/2+1<=x)
x mod y = y-n+2 >>>>>> (x+n-2) 的因数 (>=2 and %2==0 and g/2+1<=x and g/2+1>=n)                      
*/