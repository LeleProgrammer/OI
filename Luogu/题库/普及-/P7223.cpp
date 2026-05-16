#include <bits/stdc++.h>
using namespace std;

// 开个longlong啥也不怕......哈哈~~~~~~
typedef long long LL;

const int maxn=1e6+5;
const int mod=998244353; 

LL n,p;
LL volumn[maxn];
LL result;

LL qpow(LL base,LL power) {
    if (power==1) {
        return base%mod;
    } else if (power==0) {
        return 1LL;
    } else if (power%2==0) {
        LL l;
        l=qpow(base,power/2)%mod;
        return (l*l)%mod;
    } else {
        LL l;
        l=qpow(base,(power-1)/2)%mod;
        return (((l*l)%mod)*base)%mod;
    }
}

int main() {
    scanf("%lld %lld",&n,&p);
    for (LL i=1LL;i<=n;++i) {
        scanf("%lld",&volumn[i]);
    }
    result=1LL;
    for (LL i=1;i<=n;++i) {
        result*=(qpow(p,volumn[i])+1);
        result%=mod;
    }
    printf("%lld",result);
    return 0;
}

// int main() {
//     scanf("%lld %lld",&n,&p);
//     for (LL i=1LL;i<=n;++i) {
//         scanf("%lld",&volumn[i]);
//     }
//     result=1LL; // 不拿的情况 k=0 p^k=p^0=1
//     LL sum;
//     for (LL i=1LL;i<=n;++i) { // 拿i个物品
//         sum=0LL;
//         for (LL g=1;g<=i;++g) { // 初始体积和
//             sum+=volumn[g];
//         }
//         // 从1开始的情况
//         result+=qpow(p,sum);
//         result%=mod;
//         for (LL j=2LL;j+i-1<=n;++j) { // 从j开始
//             // 现在获取体积和只需像滑动窗口一样
//             // 去除前一个，添加新一个
//             sum-=volumn[j-1];
//             sum+=volumn[j+i-1];
//             result+=qpow(p,sum);
//             result%=mod;
//         }
//     }
//     printf("%lld",result);
//     return 0;
// }