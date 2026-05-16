#include <bits/stdc++.h>
using namespace std;

int main() {
    int in,maxx=-0x7fffffff;
    for (int i=0;i<3;++i) {
        cin>>in;
        if (in>maxx) {
            maxx=in;
        }
    }
    printf("%d",maxx);
    return 0;
}