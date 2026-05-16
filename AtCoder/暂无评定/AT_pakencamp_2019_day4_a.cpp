#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int res;
    res=n/400;
    if (n%400) res++;
    cout<<res<<endl;
    return 0;
}