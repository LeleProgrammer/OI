#include <bits/stdc++.h>

#define int long long
#define mod 998244353

using namespace std;

int l,r,K,ansl,ansr;
int f[20][10][2049];
int g[20][10][2049];

template<class T>
T mypow(T base,T power) {
    T res=1;
    for (int i=1;i<=power;++i) {
        res*=base;
    }
    res%=mod;
    return res;
}

void init() {
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    for (int i=0;i<=9;++i) {
        f[1][i][1<<i]=i;
        g[1][i][1<<i]=1;
    }
    for (int i=2;i<=19;++i) {
        for (int k=1;k<=(1<<10)-1;++k) {
            for (int j=0;j<=9;++j) {
                for (int p=0;p<=9;++p) {
                    if ((k&(1<<j))==(1<<j)) {
                        f[i][j][k]+=f[i-1][p][k];
                        f[i][j][k]%=mod;
                        g[i][j][k]+=g[i-1][p][k];
                        g[i][j][k]%=mod;
                        f[i][j][k]+=((mypow(10LL,i-1)*j)%mod)*g[i-1][p][k];
                        f[i][j][k]%=mod;
                        g[i][j][k]%=mod;
                    } else {
                        f[i][j][k+(1<<j)]+=f[i-1][p][k];
                        f[i][j][k]%=mod;
                        g[i][j][k+(1<<j)]+=g[i-1][p][k];
                        g[i][j][k+(1<<j)]%=mod;
                        f[i][j][k+(1<<j)]+=((mypow(10LL,i-1)*j)%mod)*g[i-1][p][k];
                        f[i][j][k+(1<<j)]%=mod;
                        g[i][j][k+(1<<j)]%=mod;
                    }
                }
            }
        }
    }
}

bool check(int k,int num) {
    int summ=((k>>0)&1)+((k>>1)&1)+((k>>2)&1)+((k>>3)&1)+((k>>4)&1)+((k>>5)&1)+((k>>6)&1)+((k>>7)&1)+((k>>8)&1)+((k>>9)&1);
    if (summ<=num) return true;
    else return false;
}

int solve(int n) {
    vector<int> nums;
    nums.push_back(-0x3f);
    while (n) {
        nums.push_back(n%10);
        n/=10;
    }
    int len=nums.size()-1;
    int ans=0;
    for (int i=1;i<=len-1;++i) {
        for (int j=1;j<=9;++j) {
            for (int k=1;k<=(1<<10)-1;++k) {
                if (check(k,K)) {
                    ans+=f[i][j][k];
                    ans%=mod;
                }
            }
        }
    }
    for (int i=1;i<=nums[len]-1;++i) {
        for (int k=1;k<=(1<<10)-1;++k) {
            if (check(k,K)) {
                ans+=f[len][i][k];
                ans%=mod;
            }
        }
    }
    unordered_set<int> tmp;
    int tmp_num=0;
    for (int i=len;i>=2;--i) {
        tmp.insert(nums[i]);
        tmp_num=tmp_num*10+nums[i];
        for (int j=0;j<=nums[i-1]-1;++j) {
            for (int k=1;k<=(1<<10)-1;++k) {
                int tmpk=k;
                for (unordered_set<int>::iterator iter=tmp.begin();iter!=tmp.end();++iter) {
                    if ((tmpk&(1<<(*iter)))!=(1<<(*iter))) {
                        tmpk=tmpk+(1<<(*iter));
                    }
                }
                if (check(tmpk,K)) {
                    ans+=f[i-1][j][k];
                    ans%=mod;
                    ans+=((mypow(10LL,i-1)*tmp_num)%mod)*g[i-1][j][k];
                    ans%=mod;
                }
            }
        }
    }
    return ans;
}

signed main() { 
    init();
    cin>>l>>r>>K;
    ansl=solve(l);
    ansr=solve(r+1);
    if (ansr-ansl<0) cout<<ansr-ansl+mod;
    else cout<<ansr-ansl;
    return 0;
}

// #4
// l: 427896435961371452
// r: 630581697708338740
// k: 1
// 427896435961371452 630581697708338740 1