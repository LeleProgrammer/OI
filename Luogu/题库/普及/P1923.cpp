#include <bits/stdc++.h>
using namespace std;

int arr[5000005];

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;++i) {
        scanf("%d",arr+i);
    }
    nth_element(arr,arr+k,arr+n);
    printf("%d",arr[k]);
    return 0;
}