#include <bits/stdc++.h>
using namespace std;

int arr[10000];

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;++i) {
        scanf("%d",&(arr[i]));
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<n-1;++j) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    int c=1;
    int last=arr[0];
    for (int i=1;i<n;++i) {
        if (arr[i]==last) {
            last=arr[i];
            continue;
        } else {
            last=arr[i];
            ++c;
            if (c==k) {
                printf("%d",arr[i]);
                return 0;
            }
        }
    }
    printf("NO RESULT");
    return 0;
}