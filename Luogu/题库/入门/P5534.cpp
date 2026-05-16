#include <bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    LL a,b,n;
    cin>>a>>b>>n;
    LL gc=b-a;
    LL result=0;
    for (LL i=0;i<n;++i) {
        result+=a+gc*i;
    }
    cout<<result;
    return 0;
}