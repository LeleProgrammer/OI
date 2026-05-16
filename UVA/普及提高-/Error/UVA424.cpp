#include <bits/stdc++.h>
using namespace std;

string in;
int a[115],b[115],c[115];

int main() {
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    while (true) {
        cin>>in;
        if (in.size()==1 && in.back()=='0') break;
        memset(b,0,sizeof(b));
        for (int i=in.size()-1;i>=0;--i) {
            b[in.size()-i]=in[i]-'0';
        }
        memset(c,0,sizeof(c));
        int jw=0;
        for (int i=1;i<=110;++i) {
            c[i]=a[i]+b[i]+jw;
            jw=c[i]/10;
            c[i]%=10;
        }
        swap(a,c);
    }
    int len=110;
    while (!a[len]) --len;
    for (int i=len;i>=1;--i) {
        cout<<a[i];
    }
    return 0;
}