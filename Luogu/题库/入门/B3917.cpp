#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int arr[1000005];
int emp;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
        if (!arr[i]) emp=i;
        else {
            a[arr[i]]=i;
        }
    }
    for (int i=1;i<=n-1;++i) {
        swap(arr[emp],arr[a[i]]);
        emp=a[i];
    }
    for (int i=1;i<=n;++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}