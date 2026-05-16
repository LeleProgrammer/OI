#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> a,b;
int ans;

void seperate(int k,vector<int>& v) {
    while (k) {
        v.push_back(k&1);
        k>>=1;
    }
    while (v.size()<63) v.push_back(0);
    reverse(v.begin(),v.end());
}

// HACKED

signed main() {
    int n,m;
    scanf("%lld %lld",&n,&m);
    if (n>m) {
        printf("0");
        return 0;
    }
    seperate(n,a);
    seperate(m,b);
    int i;
    for (i=0;i<a.size();++i) {
        int da,db;
        da=a[i];
        db=b[i];
        if (da==db) ans+=da;
        else break;
    }
    bool flag=true;
    for (int j=i;j<a.size();++j) {
        flag&=b[j];
    }
    for (i+=(flag^1);i<a.size();++i) {
        ans++;
    }
    printf("%lld",ans);
    return 0;
}

/*
00011100...
00011100...
take: 00011100...

...0...
...1...
take: ...0...

any
any
take: 111111...
*/