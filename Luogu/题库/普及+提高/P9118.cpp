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

int n,k;
unordered_set<int> hs;

int acc_sqrt(int k) {
    int l=1,r=1e9;
    while (l<r) {
        int mid=(l+r>>1)+1;
        if (mid*mid<=k) l=mid;
        else r=mid-1;
    }
    return l;
}

signed main() {
    scanf("%lld %lld",&n,&k);
    if (k==1) {
        printf("%lld",n);
        return 0;
    }
    int ex=0;
    _rep(i,max(k,3ll),100) {
        if (k==2 && i==4) continue;
        _rep(j,1,n) {
            int k=1;
            bool ok=true;
            _rep(t,1,i) {
                k=k*j;
                if (k>n) {
                    ok=false;
                    break;
                }
            }
            if (!ok) break;
            int g=acc_sqrt(k);
            if (g*g==k && !hs.count(k)) ex--;
            hs.emplace(k);
        }
    }
    if (k==2) ex+=acc_sqrt(n);
    else ex=0;
    printf("%lld",(int)hs.size()+ex);
    return 0;
}

/*
576460752303423488 2
760085356
*/