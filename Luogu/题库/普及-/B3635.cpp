#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int f[N];

int main() {
    int n;
    cin>>n;
    f[0]=0;
    for (int i=1;i<=n;++i) {
        int cost=0x3f3f3f3f;
        if (i-1>=0) cost=min(cost,f[i-1]);
        if (i-5>=0) cost=min(cost,f[i-5]);
        if (i-11>=0) cost=min(cost,f[i-11]);
        f[i]=cost+1;
    }
    cout<<f[n];
    return 0;
}