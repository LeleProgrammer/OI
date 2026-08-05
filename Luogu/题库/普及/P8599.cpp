#include <bits/stdc++.h>
using namespace std;

int n,a,b,c,res;
int arr[9]={1,2,3,4,5,6,7,8,9};

// a+b/c

int getnum(int l,int r) {
    int ans=0;
    for (int i=l;i<=r;++i) {
        ans=ans*10+arr[i];
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    res=0;
    do {
        for (int i=1;i<=7;++i) { // a的位数
            a=getnum(0,i-1); // 获取数字a
            if (a>=n) {
                break;
            }
            for (int j=1;j+i<=8;++j) { // b的位数
                b=getnum(i,i+j-1); // 获取数字b
                c=getnum(i+j,8); // 获取数字c
                if (a+(b*1.0)/(c*1.0)==n) {
                    ++res;
                }
            }
        }
    } while (next_permutation(arr,arr+9)); // 全排列
    printf("%d",res);
    return 0;
}