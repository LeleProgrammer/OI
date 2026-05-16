#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=55;

int w,n;
int arr[N];
vector<int> a,b;

bool cmp(const int& a,const int& b) {
    return a<b;
}

signed main() {
    scanf("%lld %lld",&w,&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    if (n==1) {
        printf("%lld",arr[1]);
        return 0;
    }
    for (int i=1;i<=n/2;++i) {
        int k=a.size();
        for (int j=0;j<k;++j) {
            a.push_back(a[j]+arr[i]);
        }
        a.push_back(arr[i]);
    }
    for (int i=n/2+1;i<=n;++i) {
        int k=b.size();
        for (int j=0;j<k;++j) {
            b.push_back(b[j]+arr[i]);
        }
        b.push_back(arr[i]);
    }
    a.push_back(0);
    b.push_back(0);
    sort(b.begin(),b.end(),cmp);
    int ans=0;
    for (int i=0;i<a.size();++i) {
        int l=a[i];
        int r=w-a[i];
        if (r<0) continue;
        int pos=upper_bound(b.begin(),b.end(),r)-b.begin()-1;
        ans=max(ans,a[i]+b[pos]);
    }
    printf("%lld",ans);
    return 0;
}