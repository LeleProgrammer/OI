#include <bits/stdc++.h>
using namespace std;

int arr[10005];

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        scanf("%d",arr+i);
    }
    int ans=0;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n-1;++j) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                ++ans;
            }
        }
    }
    printf("%d",ans);
    return 0;
}