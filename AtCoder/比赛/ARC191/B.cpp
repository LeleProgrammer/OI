#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

int T,n,k,cnt0;
vector<int> bit;

signed main() {
    scanf("%lld",&T);
    while (T--) {
        bit.clear(); cnt0=0;
        scanf("%lld %lld",&n,&k);
        while (n) bit.emplace_back(n&1),n>>=1;
        _iter(it,bit) if (!(*it)) cnt0++;
        if ((1<<cnt0)<k) {
            puts("-1");
            continue;
        }
        k--;
        vector<int> ans;
        _iter(it,bit) {
            if (*it) ans.emplace_back(*it);
            else {
                ans.emplace_back(k&1);
                k>>=1;
            }
        }
        int res=0;
        while (!ans.empty()) res=res<<1|ans.back(),ans.pop_back();
        printf("%lld\n",res);
    }
    return 0;
}

/*
1001101001111111000001110 n 20250126
       *        *****
1001101101111111111111110 x 20381694
0000000100000000111110000 n%x 131568
*/