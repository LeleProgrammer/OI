#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,m,a,b,ans=0;

struct match_box {
    int num,match;
    friend bool operator < (const match_box& a,const match_box& b) {
        return a.match>b.match;
    }
};

vector<match_box> q;

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=m;++i) {
        scanf("%lld %lld",&a,&b);
        match_box mb;
        mb.num=a;
        mb.match=b;
        q.push_back(mb);
    }
    sort(q.begin(),q.end());
    while (n && q.size()) {
        if (n>=q[0].num) {
            ans+=q[0].match*q[0].num;
            n-=q[0].num;
        } else {
            ans+=q[0].match*n;
            n-=n;
        }
        q.erase(q.begin());
    }
    printf("%lld",ans);
    return 0;
}