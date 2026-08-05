#include <bits/stdc++.h>
using namespace std;

const int inf=2e9;

int T,a,b,c,d;
vector<int> primes;
vector<int> a0,a1,b0,b1;
vector<int> vec;

void init(int k) {
    for (int i=2;i*i<=k;++i) {
        if (k%i) continue;
        primes.push_back(i);
        while (k%i==0) k/=i;
    }
}

int find(int k) {
    return lower_bound(primes.begin(),primes.end(),k)-primes.begin();
}

void sieve(int k,vector<int>& arr) {
    for (int i=2;i*i<=k;++i) {
        if (k%i) continue;
        int t=find(i);
        while (k%i==0) k/=i,arr[t]++;
    }
}

int main() {
    scanf("%d",&T);
    while (T--) {
        primes.clear(); a0.clear(); a1.clear(); b0.clear(); b1.clear();
        scanf("%d %d %d %d",&a,&b,&c,&d);
        init(a),init(b),init(c),init(d);
        sort(primes.begin(),primes.end());
        primes.erase(unique(primes.begin(),primes.end()),primes.end());
        for (int i=0;i<primes.size();++i) {
            a0.push_back(0);
            a1.push_back(0);
            b0.push_back(0);
            b1.push_back(0);
        }
        sieve(a,a0),sieve(b,a1),sieve(c,b0),sieve(d,b1);
        bool ok=true;
        vec.clear();
        for (int i=0;i<primes.size();++i) {
            if (a0[i]<a1[i]) {
                ok=false;
                break;
            } else if (a0[i]==a1[i]) {
                vec.push_back(a0[i]);
            } else {
                vec.push_back(1);
            }
        }
        if (!ok) {
            puts("0");
            continue;
        }
        ok=true;
        for (int i=0;i<primes.size();++i) {
            if (b0[i]>b1[i]) {
                ok=false;
                break;
            } else if (b0[i]==b1[i]) {
                if (vec[i]==1) {
                    if ()
                }
            }
        }
    }
}