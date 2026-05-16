#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1005];
bool changed=false;
int ansl,ansr;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",arr+i);
    }
    for (int i=1;i<=n;++i) {
        if (arr[i]==i) continue;
        if (changed) {
            printf("0 0");
            return 0;
        }
        changed=true;
        int j;
        for (j=i+1;j<=n;++j) {
            if (arr[j]==i) break;
        }
        for (int l=i,r=j;l<r;++l,--r) {
            swap(arr[l],arr[r]);
        }
        ansl=i,ansr=j;
        --i;
    }
    if (!changed) {
        printf("0 0");
    } else {
        printf("%d %d",ansl,ansr);
    }
    return 0;
}