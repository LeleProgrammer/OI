#include <bits/stdc++.h>

#define int long long

using namespace std;

int l,r;
int f[20][10][4]; // f[i][j][k] i位数，j开头，放了k个1~9之间的数字

// dp数组初始化
void init() {
    memset(f,0,sizeof(f));
    // 一位数的情况 1~9
    for (int i=1;i<=9;++i) {
        f[1][i][1]=1;
    }
    // 一位数的情况 0
    f[1][0][0]=1;
    // 多位数的情况
    for (int i=2;i<=18;++i) {
        // 1~9
        for (int j=1;j<=9;++j) {
            for (int k=1;k<=3;++k) {
                for (int p=0;p<=9;++p) { // 次高位
                    f[i][j][k]+=f[i-1][p][k-1];
                }
            }
        }
        // 0
        for (int k=0;k<=3;++k) {
            for (int p=0;p<=9;++p) { // 次高位
                f[i][0][k]+=f[i-1][p][k];
            }
        }
    }
}

// 求[1,n)中好数的个数
int solve(int n) {
    int ans=0;
    // 分离数位
    vector<int> nums;
    nums.push_back(-0x3f3f3f3f); // 下标从1开始，占位
    while (n) {
        nums.push_back(n%10);
        n/=10;
    }
    int len=nums.size()-1;
    // 0本身就是一个好数
    // 算不算差不多
    ans++;
    // 位数不到n的位数
    for (int i=1;i<=len-1;++i) {
        for (int j=1;j<=9;++j) { // 去除前导零
            for (int k=1;k<=3;++k) {
                ans+=f[i][j][k];
            }
        }
    }
    // 位数是n的位数，但最高位不是n的最高位
    for (int j=1;j<=nums[len]-1;++j) {
        for (int k=1;k<=3;++k) {
            ans+=f[len][j][k];
        }
    }
    // 受到数位最大值限制
    int flag=0; // 记录从第i位（包括）到最高位中1~9的数码出现的次数
    for (int i=len;i>=2;--i) { // 从第i位（包括）到最高位的数位最大
        if (nums[i]!=0) flag++;
        if (flag>3) break;
        for (int j=0;j<=nums[i-1]-1;++j) { // 此时j是次高位，是第i-1位，受到限制
            for (int k=0;k+flag<=3;++k) { // 下面这些位数中1~9的个数加flag不得超过3
                ans+=f[i-1][j][k];
            }
        }
    }
    return ans;
}

signed main() {
    init();
    int t;
    cin>>t;
    int ans1,ans2;
    while (t--) {
        cin>>l>>r;
        ans1=solve(l);
        ans2=solve(r+1);
        cout<<ans2-ans1<<endl;
    }
    return 0;
}