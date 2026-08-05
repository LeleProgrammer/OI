#include <bits/stdc++.h>

#define int long long

using namespace std;

int l,r;
int f[15][10][10]; // f[i][j][k] i位数字，最高位是j，数码k的次数
int ans[10]; // 储存结果

template<class T>
T pow(T base,T power) {
    T res=1;
    for (int i=1;i<=power;++i) {
        res*=base;
    }
    return res;
}

void init() {
    // 初始化
    memset(f,0,sizeof(f));
    // 一位数
    for (int i=0;i<=9;++i) {
        f[1][i][i]=1;
    }
    // 多位数
    for (int i=2;i<=12;++i) {
        for (int j=0;j<=9;++j) { // j=1 WA 0pts??????
            for (int k=0;k<=9;++k) { // 数码
                for (int p=0;p<=9;++p) { // 次高位
                    f[i][j][k]+=f[i-1][p][k]; // 数码统计
                }
            }
            f[i][j][j]+=pow(10,i-1); // 最高位的数码统计
        }
    }
}

void solve(int num) {
    // 初始化
    memset(ans,0,sizeof(ans));
    // 分离数位
    vector<int> nums;
    nums.push_back(-0x3f3f3f3f); // 下标从1开始，0的位置用任意数字占位
    while (num) {
        nums.push_back(num%10);
        num/=10;
    }
    int n=nums.size()-1;
    // 统计结果
    // 位数低于num的位数
    for (int i=1;i<=n-1;++i) {
        for (int j=1;j<=9;++j) { // 去除前导零
            for (int k=0;k<=9;++k) {
                ans[k]+=f[i][j][k];
            }
        }
    }
    // 位数等于num的位数
    // 最高位不是num的最高位
    for (int i=1;i<=nums[n]-1;++i) { // 去除前导零
        for (int j=0;j<=9;++j) {
            ans[j]+=f[n][i][j];
        }
    }
    // 最高位是num的最高位
    // 从个位开始枚举，i表示不同的位数，除了个位到第i位，其余全部是最大值
    for (int i=1;i<=n-1;++i) { // 最高位是最大的，所以i只到n-1
        for (int j=0;j<nums[i];++j) { // 小于号，除了个位到第i位，其余都是最大值，那第i位就不可以是最大值
            for (int k=0;k<=9;++k) {
                ans[k]+=f[i][j][k];
            }
        }
        // 前面那些位数确定了，但没有算进去，也要再统计一下
        for (int j=i+1;j<=n;++j) {
            ans[nums[j]]+=pow(10,i-1)*nums[i];
        }
    }
}

signed main() {
    init();
    scanf("%lld %lld",&l,&r);
    int ans1[10],ans2[10];
    solve(l);
    for (int i=0;i<=9;++i) ans1[i]=ans[i];
    solve(r+1);
    for (int i=0;i<=9;++i) ans2[i]=ans[i];
    for (int i=0;i<=9;++i) printf("%lld ",ans2[i]-ans1[i]);
    return 0;
}