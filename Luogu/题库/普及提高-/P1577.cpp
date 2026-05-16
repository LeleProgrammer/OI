#include <bits/stdc++.h>
using namespace std;

const int N=10005;

int n,k;
double a[N];
double eps=0.01;

bool check(double mid) {
    int cnt=0;
    for (int i=1;i<=n;++i) {
        cnt+=floor(a[i]/mid);
    }
    return cnt>=k;
}

int main() {
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i) {
        scanf("%lf",&a[i]);
    }
    double l=eps,r=100000.00;
    while (r-l>=eps) {
        double mid=(l+r)/2;
        if (check(mid)) l=mid;
        else r=mid-eps;
    }
    printf("%.3lf",l);
    return 0;
}