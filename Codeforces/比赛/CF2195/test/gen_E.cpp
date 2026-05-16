#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc,char* argv[]) {
    registerGen(argc,argv,1);
    int T=10000;
    cout<<T<<endl;
    while (T--) {
        int n=29;
        cout<<n<<endl;
        int cur=2;
        for (int i=1;i<=29;++i) {
            if (cur<=29) cout<<cur++<<" ";
            else cout<<"0 ";
            if (cur<=29) cout<<cur++<<endl;
            else cout<<"0\n";
        }
    }
    return 0;
}