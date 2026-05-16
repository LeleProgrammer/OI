#include <bits/stdc++.h>
using namespace std;

int main() {
    int jz;
    scanf("%d",&jz);
    string in_a,in_b;
    cin>>in_a>>in_b;
    int a[2001],b[2001],c[2001];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for (int i=in_a.length()-1;i>=0;--i) {
        if (isdigit(in_a.c_str()[i])) {
            a[in_a.length()-1-i]=in_a.c_str()[i]-'0';
        } else {
            a[in_a.length()-1-i]=in_a.c_str()[i]-'A'+10;
        }
    }
    for (int i=in_b.length()-1;i>=0;--i) {
        if (isdigit(in_b.c_str()[i])) {
            b[in_b.length()-1-i]=in_b.c_str()[i]-'0';
        } else {
            b[in_b.length()-1-i]=in_b.c_str()[i]-'A'+10;
        }
    }
    string jw_num="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int jw=0;
    for (int i=0;i<2001;++i) {
        c[i]=a[i]+b[i]+jw;
        jw=c[i]/jz;
        c[i]%=jz;
    }
    int length=2000;
    while (c[length]==0) {
        --length;
    }
    for (int i=length;i>=0;--i) {
        cout<<jw_num[c[i]];
    }
    return 0;
}