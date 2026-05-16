#include <bits/stdc++.h>

#define int long long

using namespace std;

int k,p;
int ans;
vector<int> pw;

void init() {
    pw.push_back(1);
    for (int i=1;i<=18;++i) {
        pw.push_back(pw.back()*10);
    }
}

int getlen(int k) {
    int len=0;
    while (k) len++,k/=10;
    return len;
}

int getrev(int k) {
    int rev=0;
    while (k) rev*=10,rev+=k%10,k/=10;
    return rev;
}

int getsum(int k) {
    int len=getlen(k),rev=getrev(k);
    return k*pw[len]+rev;
}

signed main() {
    init();
    scanf("%lld %lld",&k,&p);
    for (int i=1;i<=k;++i) {
        ans+=getsum(i);
        ans%=p;
    }
    printf("%lld",ans);
    return 0;
}