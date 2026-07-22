#include <bits/stdc++.h>

#define int long long
#define mod 1000000007

using namespace std;

int l,r,t,res1,res2;
int f[20][10];

template<class T>
inline T pow(T a,T b) {
    T res=1;
    for (register int i=1;i<=b;++i) {
        res*=a;
    }
    return res;
}

void init() {
    memset(f,0,sizeof(f));
    for (int i=0;i<=9;++i) f[1][i]=i;
    for (int i=2;i<=18;++i) {
        for (int j=0;j<=9;++j) {
            for (int p=0;p<=9;++p) {
                f[i][j]+=f[i-1][p];
            }
            f[i][j]+=pow(10LL,i-1)*j;
            f[i][j]%=mod;
        }
    }
}

int solve(int n) {
    int ans=0;
    vector<int> nums;
    nums.push_back(-0x3f3f3f3f);
    while (n) {
        nums.push_back(n%10);
        n/=10;
    }
    int len=nums.size()-1;
    for (int i=1;i<=len-1;++i) {
        for (int j=1;j<=9;++j) {
            ans+=f[i][j];
            ans%=mod;
        }
    }
    for (int i=1;i<=nums[len]-1;++i) {
        ans+=f[len][i];
        ans%=mod;
    }
    int sum=0;
    for (int i=len;i>=2;--i) {
        sum+=nums[i];
        for (int j=0;j<=nums[i-1]-1;++j) {
            ans+=f[i-1][j];
            ans%=mod;
        }
        ans+=pow(10LL,i-2)*sum*nums[i-1];
        ans%=mod;
    }
    return ans;
}

signed main() {
    init();
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld %lld",&l,&r);
        res1=solve(l);
        res2=solve(r+1);
        printf("%lld\n",(res2-res1+mod)%mod);
    }
    return 0;
}