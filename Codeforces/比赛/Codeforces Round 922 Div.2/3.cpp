#include <bits/stdc++.h>

#define int long long

using namespace std;

int T;
int a,b,r;
int na[155],nb[155],lena,lenb;
int lmt[155],lenl;
int x;
int cz;

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&a,&b,&r);
        int ori_a,ori_b;
        ori_a=a,ori_b=b;
        memset(lmt,0,sizeof(lmt));
        memset(na,0,sizeof(na));
        memset(nb,0,sizeof(nb));
        lenl=0;
        while (r) lmt[++lenl]=r&1LL,r>>=1LL;
        lena=lenb=0;
        while (a) na[++lena]=a&1LL,a>>=1LL;
        while (b) nb[++lenb]=b&1LL,b>>=1LL;
        /*
        x1xx10x01xxxxxxx0xxx
        x0xx01x10xxxxxxx1xxx
        */
        x=0;
        bool limited=true;
        int up=-1; // 除了第一个有分歧的 1，其余的 1 退到哪一边
        for (int i=max(lena,max(lenb,lenl));i>=1;--i) {
            if (na[i]==nb[i]) {
                if (limited && lmt[i]!=0) limited=false;
                continue;
            }
            else if (limited) {
                if (na[i]==1 && up==-1) up=0; // 上面 1，后面全归下面
                else if (nb[i]==1 && up==-1) up=1; // 反之...
                if (lmt[i]==0) continue;
                if ((up==1 && nb[i]==1) || (na[i]==1 && up==0)) x+=(1LL<<(int)(i-1));
                else limited=false;
                continue;
            } else {
                if ((up==1 && nb[i]==1) || (na[i]==1 && up==0)) {
                    x+=(1LL<<(int)(i-1));
                }
            }
        }
        // bool limited=true;
        // x=0; cz=ori_a-ori_b;
        // for (int i=max(lena,lenb);i>=1;--i) {
        //     cout<<"TEST: "<<limited<<" "<<cz<<" "<<x<<endl;
        //     if (limited && lmt[i]==0) { // 有限制，啥也填不了
        //         continue;
        //     } else if (limited && lmt[i]==1) { // 有限制，二选一
        //         if (na[i]==nb[i]) { // 转不转无所谓，干脆不转
        //             limited=false; // 限制解除，填零
        //             continue;
        //         } else { // 此时两位刚好有一个一和一个零
        //             if (na[i]==1 && cz>0) {
        //                 x+=(1<<(i-1)); // 填 1
        //                 cz-=(1<<i);
        //             } else if (nb[i]==1 && cz<0) {
        //                 x+=(1<<(i-1));
        //                 cz+=(1<<i);
        //             } else {
        //                 limited=false;
        //                 continue;
        //             }
        //         }
        //     } else { // 没限制
        //         if (na[i]==nb[i]) { // 还是无所谓
        //             continue;
        //         } else {
        //             if (na[i]==1 && cz>0) {
        //                 x+=(1<<(i-1)); // 填 1
        //                 cz-=(1<<i);
        //             } else if (nb[i]==1 && cz<0) {
        //                 x+=(1<<(i-1));
        //                 cz+=(1<<i);
        //             } else {
        //                 continue;
        //             }
        //         }
        //     }
        // }
        // cout<<"x: "<<x<<endl;
        printf("%lld\n",llabs((ori_a^x)-(ori_b^x)));
    }
    return 0;
}

/*
1 14 5
0001
1110
0101
0100

2 7 2
0010
0111
0010
000

165 839 201
xx00 101x xx0x
xx11 010x xx1x
0000 1100 1001

11101000101010100101
10100101001010101101

x1xx10x01xxxxxxx0xxx
x0xx01x10xxxxxxx1xxx

a b x
1 1 0 -> 1 1
1 1 1 -> 0 0
0 0 0 -> 0 0
0 0 1 -> 1 1
1 0 0 -> 1 0
1 0 1 -> 0 1
0 1 0 -> 0 1
0 1 1 -> 1 0
x = 0 -> no changing
x = 1 -> a and b -> reverse

错误：
|a-b+32| 二进制位分别出现 1 和 0 时，1 给 a  a-b 小于 0
|a-b-32| 1 给 b  a-b 大于 0
1 0 交换位置耗费的位是 1

一个 1 一个 0：
|a-b| r -> 0
|a-32-b-32| 1 出现在 a 里面 |a-b-64| cz>0
|a+32-b+32| 1 出现在 b 里面 |a-b+64| cz<0
对应的位 (2^i) -> +-(2^(i+1))

0 3 2
0000 a
0011 b
0010 lmt
00

9 6 10
1001 a
0110 b
1010 lmt
0001
*/