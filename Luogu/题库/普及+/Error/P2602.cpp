#include <bits/stdc++.h>

#define int long long

using namespace std;

int a,b;

// f[i][j][k] 表示i位数，最高位为j，k出现的次数
int f[15][10][10];

// dp预处理
void init() {
    for (int i=0;i<=12;++i) {
        for (int j=0;j<=9;++j) {
            for (int p=0;p<=9;++p) {
                f[i][j][p]=0;
            }
        }
    }
    // 一位数，最高位为i，j出现的次数
    for (int i=0;i<=9;++i) {
        f[1][i][i]=1;
    }
    // 位数
    for (int i=2;i<=12;++i) {
        // 最高位
        for (int j=0;j<=9;++j) {
            // 数位
            for (int k=0;k<=9;++k) {
                // 第二高位
                for (int p=0;p<=9;++p) {
                    f[i][j][k]+=f[i-1][p][k];
                }
            }
            // 最高位的数位统计
            int base=10,exp=i-1,num=1;
            for (int k=1;k<=exp;++k) {
                num*=base;
            }
            f[i][j][j]+=num;
        }
    }
}

// 统计[1,x)
void solve(int x,int* result) {
    // 分离数位
    vector<int> nums;
    while (x) {
        nums.push_back(x%10);
        x/=10;
    }
    int len=nums.size();
    // 位数少于len
    for (int i=1;i<=len-2;++i) {
        // 最高位
        for (int j=1;j<=9;++j) { // 前导0不能算进去
            // 数位
            for (int k=0;k<=9;++k) {
                result[k]+=f[i][j][k];
            }
        }
    }
    // len位数，但最高位不是最大
    for (int i=1;i<=nums[len-1]-1;++i) { // 前导0不能算进去
        // 数位
        for (int j=0;j<=9;++j) {
            result[j]+=f[len][i][j];
        }
    }
    // 有位数限制的情况
    // i位数
    for (int i=len-2;i>=0;--i) { // 默认上一位及之前的都是最大值
        // 这一位数比最高位低
        for (int j=0;j<nums[i];++j) { // 因为前面已经有位数了，0可以算进去
            // 数位
            for (int k=0;k<=9;++k) {
                result[k]+=f[i][j][k];
            }
        }
        // 前面的那些位数没有计算到
        // 和init中的最高位数位统计一样，要再统计一下
        // 数位上的数字也是确定的（最大值）
        // 不同的是这次是有多个数位
        // 所以还要枚举各个数位
        int base=10,exp,num;
        for (int j=len-1;j>i;++j) {
            num=1,exp=i-1;
            for (int k=1;k<=exp;++k) {
                num*=base;
            }
            result[nums[j]]+=num*nums[i];
        }
    }
}

signed main() {
    scanf("%lld %lld",&a,&b);
    init();
    cout<<f[2][9][9]<<endl;
    int res_a[12]={0},res_b[12]={0};
    solve(a,res_a);
    solve(b+1,res_b);
    cout<<f[2][9][9]<<endl;
    for (int i=0;i<=9;++i) {
        printf("%lld ",res_b[i]-res_a[i]);
    }
    return 0;
}