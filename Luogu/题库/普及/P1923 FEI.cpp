#include <bits/stdc++.h>
using namespace std;

int arr[5000005];

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i=0;i<n;++i) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    printf("%d",arr[k]);
    return 0;
}