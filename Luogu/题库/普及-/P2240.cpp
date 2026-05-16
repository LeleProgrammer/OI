#include <bits/stdc++.h>
using namespace std;

double value[105];
double num[105];

int main() {
    int n,t;
    scanf("%d %d",&n,&t);
    int m,v;
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&m,&v);
        value[i]=((double)(v)/(double)(m));
        num[i]=m;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n-1;++j) {
            if (value[j]<value[j+1]) {
                swap(value[j],value[j+1]);
                swap(num[j],num[j+1]);
            }
        }
    }
    // 谁说一定要dp呢~~~哈哈
    double result=0.00;
    for (int i=1;i<=n;++i) {
        if (t-num[i]>=0) { // 全拿走
            result+=num[i]*value[i];
            t-=num[i]; // 剩余空间更小了
        } else { // 没法全拿走
            result+=value[i]*t; // 把剩下空间填满就好了
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<result;
    return 0;
}