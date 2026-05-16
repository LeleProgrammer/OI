#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n;
int a[N];
int pos;
int ans;

bool cmp(const int& a,const int& b) {
    return a<b;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+1+n,cmp);
    pos=a[n/2+1];
    for (int i=1;i<=n;++i) ans+=abs(a[i]-pos);
    printf("%d",ans);
    return 0;
}