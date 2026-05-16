#include <bits/stdc++.h>
using namespace std;

/*
ok:
75=[3]*(5*5) 25
150=[2]*[3]*(5*5) 25
75=[3]*(5*5) 25
50=[2]*(5*5) 25

not ok:
100=[2]*[2]*(5*5) 25
150=[2]*[3]*(5*5) 25
250=[2]*5*(5*5) 125
*/

int main() {
    int n;
    scanf("%d",&n);
    int number;
    int remain=-1;
    while (n--) {
        scanf("%d",&number);
        // 除去所有2和3，因为倍增操作可以给它乘回来
        // 只需要判断除去所有2和3之后，剩下的数是否相等
        // 若相等，则Yes，反之，则No
        while (number%2==0) number/=2;
        while (number%3==0) number/=3;
        if (remain==-1) {
            remain=number;
        } else {
            if (remain!=number) {
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes");
    return 0;
}