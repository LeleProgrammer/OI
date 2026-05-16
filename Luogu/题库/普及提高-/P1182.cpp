#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n,m;
int a[N];

bool check(int mid) {
    int k=1;
    int t=0;
    for (int i=1;i<=n;++i) {
        if (t+a[i]>mid) {
            t=0;
            k++;
        }
        t+=a[i];
    }
    return k<=m;
}

int main() {
    scanf("%d %d",&n,&m);
    int l=0;
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        l=max(l,a[i]);
    }
    int r=1000000000;
    while (l<r) {
        int mid=l+r>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d",l);
    return 0;
}