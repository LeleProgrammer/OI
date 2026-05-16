#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc,char* argv[]) {
    registerGen(argc,argv,1);
    cout<<1<<endl;
    cout<<300000<<endl;
    for (int i=1;i<=300000;++i) {
        if (i!=1) cout<<" ";
        cout<<rnd.next(1,6);
    }
    cout<<endl;
    return 0;
}