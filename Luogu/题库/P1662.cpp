#include <bits/stdc++.h>
using namespace std;

bool include_7(long long n) {
    short tmp;
    while (n!=0) {
        tmp=n%10;
        n/=10;
        if (tmp==7) {
            return true;
        }
    }
    return false;
}

int main() {
    long long X;
    scanf("%lld",&X);
    int person=1;
    long long n=1;
    bool mode=1; // 1:plus 0:minus
    while (true) {
        if (n==X) {
            break;
        }
        if (n%7==0 || include_7(n)) {
            mode=(mode==1?0:1);
        }
        ++n;
        person+=(mode==1?1:-1);
        if (person==0) {
            person=1337;
        } else if (person==1338) {
            person=1;
        }
    }
    printf("%d",person);
    return 0;
}