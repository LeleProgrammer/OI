#include <bits/stdc++.h>
using namespace std;

int a[100005];
int dp[100005][18]; // 2的18次方刚好超过100000

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;++i) {
        scanf("%d",a+i); // 输入
        dp[i][0]=a[i]; // 初始化st表
    }
    // 预处理，dp建立st表
    // O(n log n)
    for (int i=1;i<18;++i) {
        for (int j=0;j<=n-(1<<i)+1;++j) {
            // 状态转移
            dp[j][i]=max(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
        }
    }
    // 查询
    // 每次查询只需 O(1) 时间复杂度
    int l,r;
    while (m--) {
        scanf("%d %d",&l,&r);
        --l;
        --r;
        // 求次方 log(2)(r-l+1)=lg 2的lg次方小于等于(r-l+1)
        int lg=log2(r-l+1);
        // 区间合并
        // r-(1<<lg)+1开始往右长度为2的lg次方的区间最大值
        // 可重复贡献问题
        int maxx=max(dp[l][lg],dp[r-(1<<lg)+1][lg]);
        printf("%d\n",maxx);
    }
    return 0;
}