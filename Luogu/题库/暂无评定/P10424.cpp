#include <bits/stdc++.h>
using namespace std;

int n;

bool check(int k) {
    int cnt=0;
    while (k) {
        ++cnt;
        int a=k%10;
        k/=10;
        if (cnt%2) {
            if (a%2==0) return false;
        } else {
            if (a%2) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d",&n);
    int cnt=0;
    for (int i=1;i<=n;++i) {
        if (check(i)) cnt++;
    }
    printf("%d",cnt);
    return 0;
}