// 提交的时候加O2，手动加，OJ不允许下面这行
// #pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;

int _sum(int a,int b,int c) {
    return a/100+a%100/10+a%100%10+b/100+b%100/10+b%100%10+c/100+c%100/10+c%100%10;
}

int _mul(int a,int b,int c) {
    return (a/100)*(a%100/10)*(a%100%10)*(b/100)*(b%100/10)*(b%100%10)*(c/100)*(c%100/10)*(c%100%10);
}

const int s_sum=1+2+3+4+5+6+7+8+9;
const int s_mul=1*2*3*4*5*6*7*8*9;

int main() {
    int a,b,c;
    bool have=false;
    int check[10];
    scanf("%d %d %d",&a,&b,&c);
    for (register int aa=100;aa<=333;++aa) {
        for (register int bb=100;bb<=666;++bb) {
            for (register int cc=100;cc<=999;++cc) {
                if (_sum(aa,bb,cc)==s_sum && _mul(aa,bb,cc)==s_mul) {
                    memset(check,0,sizeof(check));
                    check[aa/100]=1;
                    check[aa%100/10]=1;
                    check[aa%100%10]=1;
                    check[bb/100]=1;
                    check[bb%100/10]=1;
                    check[bb%100%10]=1;
                    check[cc/100]=1;
                    check[cc%100/10]=1;
                    check[cc%100%10]=1;
                    if (aa*b*c==bb*a*c && aa*b*c==cc*a*b && 
                    check[1]+check[2]+check[3]+check[4]+
                    check[5]+check[6]+check[7]+check[8]+check[9]==9) {
                        printf("%d %d %d\n",aa,bb,cc);
                        have=true;
                    }
                }
            }
        }
    }
    if (!have) {
        printf("No!!!");
    }
    return 0;
}