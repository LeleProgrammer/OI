#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

int ans=0;

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=2;i<=n;++i) {
        bool ok=true;
        for (int j=2;j<=i-1;++j) {
            if (i%j==0) {
                ok=false;
                break;
            }
        }
        if (ok) {
            primes.push_back(i);
        }
    }
    for (int i=2;i<primes.size();++i) {
        for (int j=0;j<i;++j) {
            if (primes[j]+primes[j+1]+1==primes[i]) {
                ans++;
                break;
            }
        }
    }
    if (ans>=k) printf("YES");
    else printf("NO");
    return 0;
}