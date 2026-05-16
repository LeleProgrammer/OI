#include <bits/stdc++.h>
using namespace std;

int primes[1005];
int tot;
int n;

typedef unsigned long long LL;

LL f[1005];

void make_primes() {
    for (int i=2;i<=1000;++i) {
        bool is_prime=true;
        for (int j=2;j*j<=i;++j) {
            if (i%j==0) {
                is_prime=false;
                break;
            }
        }
        if (is_prime) primes[++tot]=i;
    }
}

int main() {
    make_primes();
    scanf("%d",&n);
    f[0]=1llu;
    for (int i=1;i<=tot;++i) {
        for (int j=primes[i];j<=n;++j) {
            f[j]+=f[j-primes[i]];
        }
    }
    printf("%llu",f[n]);
    return 0;
}