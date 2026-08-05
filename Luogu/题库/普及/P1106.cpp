#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    int s;
    cin>>n>>s;
    int nLength=n.size();
    while (s--) {
        for (int i=0;i<nLength-1;++i) {
            if (n[i]>n[i+1]) {
                for (int j=i;j<nLength-1;++j) {
                    n[j]=n[j+1];
                }
                break;
            }
        }
        --nLength;
    }
    int start=0;
    while (n[start]=='0' && start<nLength-1) {
        ++start;
    }
    for (int i=start;i<nLength;++i) {
        cout<<n[i];
    }
    return 0;
}