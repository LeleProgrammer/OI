#include <bits/stdc++.h>
using namespace std;

int T,x,n;
// int arr[1000005],tot;

bool is_prime(int k) {
    // for (int i=2;i*i<=k;++i) {
    //     if (k%i==0) return false;
    // }
    // return true;
    for (int i=1;i<=20;++i) {
        int rd=rand();
        while (rd%k==0) rd=rand();
        if (pow(k,rd-1)!=1) return false;
    }
    return true;
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&x,&n);
        // for (int i=2;i*i<=x;++i) {
        //     while (x%i==0) x/=i,arr[++tot]=i;
        // }
        if (x%n==0) {
            printf("%d\n",x/n);
            continue;
        }
        if (is_prime(x)) {
            printf("%d\n",1);
            continue;
        }
        int a,b;
        a=x/n; b=x%n;
        while (x%a) a--;
        printf("%d\n",a);
    }
    return 0;
}