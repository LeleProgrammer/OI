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

const int mod=1e9+7;

int T,n,m,v;
unordered_map<int,int> hs;
vector<int> vec;

int qpow(int a,int b) {
    if (!b) return 1;
    if (b==1) return a%mod;
    int k=qpow(a,b>>1);
    if (b&1) return (k*k%mod)*a%mod;
    else return k*k%mod;
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&n,&m,&v);
        hs.clear();
        bool flag=true;
        while (m--) {
            int c,d;
            scanf("%lld %lld",&c,&d);
            if (hs.count(c) && hs[c]!=d) flag=false;
            hs[c]=d;
        }
        if (!flag) {
            puts("0");
            continue;
        }
        vec.clear();
        _iter(it,hs) vec.emplace_back(it->first);
        sort(vec.begin(),vec.end());
        int las=n;
        int ans=1;
        _rrep(i,(int)vec.size()-1,0) {
            int k=qpow(v,2*(las-vec[i]));
            if (i!=(int)vec.size()-1) k=k-qpow(v,las-vec[i]-1)*(v-1)%mod;
            ans*=k;
            ans=(ans%mod+mod)%mod;
            las=vec[i];
            // cout<<"now: "<<vec[i]<<" "<<ans<<endl;
        }
        if (las!=1) {
            int k=qpow(v,2*(las-1));
            ans*=k;
            ans=(ans%mod+mod)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}