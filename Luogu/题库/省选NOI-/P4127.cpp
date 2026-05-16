#include <bits/stdc++.h>

#define int long long
#define inf -0x3f

using namespace std;

int a,b,ansa,ansb;
int f[25][220][220];
vector<int> nums;
int len;

void clear() {
    for (int i=0;i<=24;++i) {
        for (int j=0;j<=219;++j) {
            for (int k=0;k<=219;++k) {
                f[i][j][k]=-inf;
            }
        }
    }
}

void seperate(int n) {
    while (!nums.empty()) nums.pop_back();
    nums.push_back(inf);
    while (n) nums.push_back(n%10),n/=10;
    len=nums.size()-1;
}

int dfs(int pos,int add,int ori,bool lmt,bool zero,int tot) {
    if (!pos) {
        if (!ori && !zero && add==tot) return 1;
        else return 0;
    }
    if (!lmt && f[pos][add][ori]!=-inf) return f[pos][add][ori];
    int res=0,maxx=lmt?nums[pos]:9;
    for (int i=0;i<=maxx;++i) {
        res+=dfs(pos-1,add+i,(ori*10+i)%tot,lmt&&i==maxx,zero&&!i,tot);
    }
    if (!lmt) return f[pos][add][ori]=res;
    else return res;
}

signed main() {
    scanf("%lld %lld",&a,&b); a--;
    seperate(a);
    for (int tot=1;tot<=len*9;++tot) clear(),ansa+=dfs(len,0,0,true,true,tot);
    seperate(b);
    for (int tot=1;tot<=len*9;++tot) clear(),ansb+=dfs(len,0,0,true,true,tot);
    printf("%lld",ansb-ansa);
    return 0;
}