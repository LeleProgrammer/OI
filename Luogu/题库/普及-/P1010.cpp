#include <bits/stdc++.h>
using namespace std;

const int MAXN=16; // 2的16次方超出题目20000

void to_bin(int num,int* to_num) { // 将num转为二进制数并保存
    int digit=0;
    while (num) {
        to_num[digit]=num%2;
        num/=2;
        ++digit;
    }
    return ;
}

/*
草稿
1= 2(0)
2= 2
3= 11 2(1)+2(0) 2+2(0)
4= 001 2(2)
5= 101 2(2)+2(0)
6= 011 2(2)+2
7= 111 2(2)+2+2(0)
8= 0001 2(3) [ 3= 11 2(1)+2(0) 2+2(0) ] 2(2+2(0))
10=0101 2(3)+2(1)
*/

void dg(int num) { // 递归输出
    int bin[MAXN];
    memset(bin,0,sizeof(bin)); // 填充为0，以免出现未初始化的值
    to_bin(num,bin); // 获取递归的数字对应的二进制数，存为bin数组
    bool output=false; // 此次递归是否已经输出过东西了
    for (int i=MAXN-1;i>=0;--i) {
        if (bin[i]==1) { // 二进制位是1，需要操作
            if (output) { // 已经输出过了，同层级该数前有数，需要输出加号
                printf("+");
            }
            if (i>2) { // 2的3次方或以上，可以再拆分，递归
                printf("2("); // 先输出左边部分
                dg(i); // 中间进行拆分
                printf(")"); // 输出右边部分
            } else if (i==2) { // 2的2次方，无需拆分
                printf("2(2)");
            } else if (i==1) { // 2的1次方，2的本身
                printf("2");
            } else if (i==0) { // 2的0次方，=1，依题意需要输出2(0)而非1
                printf("2(0)");
            }
            output=true; // 已经输出了
        }
    }
}

int main() {
    int n;
    scanf("%d",&n); // 输入
    dg(n); // 递归输出
    return 0;
}