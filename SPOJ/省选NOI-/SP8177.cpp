#include <bits/stdc++.h>

#define int long long
#define il inline
#define sf scanf
#define wl while
#define rt return

using namespace std;

const int N=25,M=2520,K=75;

int t,l,r,ll,rr,fc[M+55],le,f[N][M+55][K];
vector<int> ns;

il void it() {
    for (int i=0;i<=19;++i) for (int j=0;j<=M+10;++j) for (int k=0;k<=75;++k)  f[i][j][k]=-1;
    int tot=0;
    for (int i=1;i<=M;++i) if (!(M%i)) fc[i]=++tot;
}

il int gcd(int a,int b) {
    if (a<b) swap(a,b);
    if (!b) rt a;
    rt gcd(b,a%b);
}

il int lcm(int a,int b) {
    rt b/gcd(a,b)*a;
}

il void seperate(int k) {
    wl (!ns.empty()) ns.pop_back();
    ns.push_back(-0x3f);
    wl (k) ns.push_back(k%10),k/=10;
    le=ns.size()-1;
}

il int dfs(int p,int s,int g,bool t) {
    if (!p) rt s%g?0:1;
    if (!t && f[p][s][fc[g]]!=-1) rt f[p][s][fc[g]];
    int res=0,maxx=t?ns[p]:9;
    for (int i=0;i<=maxx;++i) res+=dfs(p-1,(s*10+i)%M,i?lcm(g,i):g,t&&i==maxx);
    if (t) rt res;
    rt f[p][s][fc[g]]=res;
}

inline void sv(int n,int& ans) {
    ans=0; seperate(n); ans=dfs(le,0,1,true);
}

signed main() {
    it();
    sf("%lld",&t);
    wl (t--) {
        sf("%lld %lld",&l,&r); l--;
        sv(l,ll); sv(r,rr);
        printf("%lld\n",rr-ll);
    }
    rt 0;
}