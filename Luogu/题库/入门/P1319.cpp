#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int val;
    int i=1;
    int now=0;
    while (cin>>val) {
        for (int j=1;j<=val;++j) {
            cout<<now;
            if (i==n) {
                i=0;
                cout<<endl;
            }
            i++;
        }
        now=(now+1)%2;
    }
    return 0;
}