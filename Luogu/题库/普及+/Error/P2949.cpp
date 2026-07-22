#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL ans=0;
int n,d,p;

unordered_map<int,int> ps;

int main() {
    freopen("Test/P2949_2.in","r",stdin);
    scanf("%d",&n);
    while (n--) {
        scanf("%d %d",&d,&p);
        auto iter=ps.find(d);
        if (iter==ps.end()) ps.insert(make_pair(d,p));
        else ps[d]=max(ps[d],p);
    }
    for (auto iter=ps.begin();iter!=ps.end();++iter) {
        ans+=iter->second;
    }
    printf("%lld",ans);
    return 0;
}