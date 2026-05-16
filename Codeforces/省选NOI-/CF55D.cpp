#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=25;
const int M=2520; // lcm(1,...,9)
const int K=105;

int t;
int l,r;
int ansl,ansr;
vector<int> nums;
int factors[M+55];
int len;
int f[N][M+55][K];

inline void init() {
    for (int i=0;i<=19;++i) {
        for (int j=0;j<=M+10;++j) {
            for (int k=0;k<=75;++k) {
                f[i][j][k]=-1;
            }
        }
    }
    int tot=0;
    for (int i=1;i<=M;++i) {
        if (!(M%i)) factors[i]=++tot;
    }
}

inline int gcd(int a,int b) {
    if (a<b) swap(a,b);
    if (!b) return a;
    return gcd(b,a%b);
}

inline int lcm(int a,int b) {
    return b/gcd(a,b)*a;
}

inline void seperate(int k) {
    while (!nums.empty()) nums.pop_back();
    nums.push_back(-0x3f);
    while (k) nums.push_back(k%10),k/=10;
    len=nums.size()-1;
}

inline int dfs(int pos,int sum,int gbs,bool lmt) {
    if (!pos) return sum%gbs?0:1;
    if (!lmt && f[pos][sum][factors[gbs]]!=-1) return f[pos][sum][factors[gbs]];
    int res=0,maxx=lmt?nums[pos]:9;
    for (int i=0;i<=maxx;++i) {
        res+=dfs(pos-1,(sum*10+i)%M,i?lcm(gbs,i):gbs,lmt&&i==maxx);
    }
    if (lmt) return res;
    return f[pos][sum][factors[gbs]]=res;
}

inline void solve(int n,int& ans) {
    ans=0; seperate(n);
    ans=dfs(len,0,1,true);
}

signed main() {
    init();
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld %lld",&l,&r); l--;
        solve(l,ansl); solve(r,ansr);
        printf("%lld\n",ansr-ansl);
    }
    return 0;
}