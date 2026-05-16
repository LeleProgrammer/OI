#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;
const int inf=1e18;

int n,x,y;

struct node {
    int a,b;
} arr[N];

bool cmp(const node& a,const node& b) {
    return a.a>b.a;
}

bool cmp2(const node& a,const node& b) {
    return a.b>b.b;
}

signed main() {
    scanf("%lld %lld %lld",&n,&x,&y);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i].a);
    }
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i].b);
    }
    sort(arr+1,arr+1+n,cmp);
    int ans=inf;
    int cnt=0;
    int a=0,b=0;
    for (int i=1;i<=n;++i) {
        a+=arr[i].a;
        b+=arr[i].b;
        cnt++;
        if (a>x || b>y) break;
    }
    ans=min(ans,cnt);
    sort(arr+1,arr+1+n,cmp2);
    cnt=0,a=0,b=0;
    for (int i=1;i<=n;++i) {
        a+=arr[i].a;
        b+=arr[i].b;
        cnt++;
        if (a>x || b>y) break;
    }
    ans=min(ans,cnt);
    printf("%d",ans);
    return 0;
}