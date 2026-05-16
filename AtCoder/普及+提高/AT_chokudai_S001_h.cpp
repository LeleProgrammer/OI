#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
int q[100005];
int l,r,mid;
int ans=0;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",arr+i);
    }
    for (int i=1;i<=n;++i) {
        l=0,r=ans;
        while (l<r) {
            mid=(l+r+1)/2;
            if (q[mid]<arr[i]) l=mid;
            else r=mid-1;
        }
        ans=max(ans,r+1);
        q[r+1]=arr[i];
    }
    printf("%d\n",ans);
    return 0;
}