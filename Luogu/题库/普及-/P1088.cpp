#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    int arr[10005];
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;++i) {
        scanf("%d",arr+i);
    }
    for (int i=0;i<m;++i) {
        next_permutation(arr,arr+n);
    }
    for (int i=0;i<n;++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}