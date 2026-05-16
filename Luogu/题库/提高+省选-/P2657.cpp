#include <bits/stdc++.h>
using namespace std;

int l,r;

// dp数组 f[i][j]表示i位数，最高位为j的方案数
int f[12][10];

// 预处理
void init() {
    // 填充0
    memset(f,0,sizeof(f));
    // 仅有一位数
    for (int i=0;i<=9;++i) f[1][i]=1; // 1位数，最高位为i的方案为1
    // 枚举位数
    for (int i=2;i<=10;++i) {
        // 枚举位上的数字
        for (int j=0;j<=9;++j) {
            // 枚举上一个数字
            for (int k=0;k<=9;++k) {
                // 应符合windy数的特点
                // 相邻位数之差的绝对值大于等于2
                if (abs(j-k)>=2) {
                    // 从若干个k的状态的来，所以是+=而不是直接=
                    f[i][j]+=f[i-1][k];
                }
            }
        }
    }
    return;
}

// 求n及以内的windy数
int dp(int n) {
    // 存放分离的数位
    int nums[12],len=0;
    // 分离数位
    while (n) {
        ++len;
        nums[len]=n%10;
        n/=10;
    }
    // 存放结果
    int res=0;
    // 分部分进行状态处理
    // 1. 长度不达到最高，0~9都可以填
    // 枚举数字长度（i从0开始）
    for (int i=1;i<=len-1;++i) {
        // 枚举最高位，windy数不能含有前导0，因此从1开始
        for (int j=1;j<=9;++j) {
            res+=f[i][j];
        }
    }
    // 2. 长度达到最高，但最高位不填最大值，其余数位仍然可以填0~9
    // 枚举最高位上的值，i<=最大值-1
    for (int i=1;i<=nums[len]-1;++i) {
        res+=f[len][i]; // len位数，最高位为i
    }
    // 3. 长度达到最高，最高位填最高值，其与数位均需看情况
    // 枚举数位，从第二位开始由高到低枚举，方便记录（i从0开始）
    for (int i=len-1;i>=1;--i) {
        // 枚举最高位
        for (int j=0;j<=nums[i]-1;++j) {
            // j要和上一位数相差2或以上
            if (abs(j-nums[i+1])>=2) {
                res+=f[i][j];
            }
        }
        // 与上一位相差2以内，不符合了，就退出
        if (abs(nums[i+1]-nums[i])<2) break;
    }
    // 最后返回结果
    return res;
}

int main() {
    // 预处理
    init();
    // 读入左界，右界
    cin>>l>>r;
    // 计算并输出结果
    cout<<dp(r+1)-dp(l);
    // 退出
    return 0;
}

/*
f[i][j]表示i位数，最高位为j的方案数
f[i][j]的状态可以由f[i-1][k]得来
windy数的数位相差大于等于2，所以|k-j|大于等于2
k可以是多个数，所以枚举k
*/