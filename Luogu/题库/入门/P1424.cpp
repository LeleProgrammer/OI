#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,n;
    cin>>x>>n;
    int tot=0;
    for (int i=1;i<=n;++i) {
        if (x<=5) {
            tot+=250;
        }
        x++;
        if (x==8) x=1;
    }
    cout<<tot;
    return 0;
}