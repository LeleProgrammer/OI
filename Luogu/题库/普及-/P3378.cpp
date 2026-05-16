#include <bits/stdc++.h>
using namespace std;

priority_queue<unsigned long long,vector<unsigned long long>,greater<unsigned long long> > pq;

int main() {
    unsigned long long n;
    unsigned long long type;
    unsigned long long x;
    scanf("%llu",&n);
    for (unsigned long long i=1ull;i<=n;++i) {
        scanf("%llu",&type);
        if (type==1) {
            scanf("%llu",&x);
            pq.push(x);
        } else if (type==2) {
            printf("%llu\n",pq.top());
        } else {
            pq.pop();
        }
    }
    return 0;
}