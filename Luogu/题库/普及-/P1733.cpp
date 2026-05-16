#include <bits/stdc++.h>
using namespace std;

int main() {
    int left=1,right=1e9+1;
    int res;
    while (true) {
        cout<<(left+right)/2<<endl;
        cin>>res;
        if (res==-1) {
            left=(left+right)/2;
        } else if (res==1) {
            right=(left+right)/2;
        } else {
            return 0;
        }
    }
    return 0;
}