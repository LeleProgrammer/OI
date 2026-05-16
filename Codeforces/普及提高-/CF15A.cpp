#include <bits/stdc++.h>
using namespace std;

const int N=1005;

int n;
double t;
int ans;

struct node {
    double x,a,l,r;
    friend bool operator < (const node& a,const node& b) {
        return a.x<b.x;
    }
} arr[N];

int main() {
    scanf("%d %lf",&n,&t);
    for (int i=1;i<=n;++i) {
        scanf("%lf %lf",&arr[i].x,&arr[i].a);
        arr[i].l=arr[i].x-(arr[i].a/2.0);
        arr[i].r=arr[i].x+(arr[i].a/2.0);
    }
    sort(arr+1,arr+1+n);
    for (int i=1;i<=n;++i) {
        if (i==1) ans++;
        else if (t<=arr[i].l-arr[i-1].r) ans++;
        if (i==n) ans++;
        else if (t<arr[i+1].l-arr[i].r) ans++;
    }
    printf("%d",ans);
    return 0;
}