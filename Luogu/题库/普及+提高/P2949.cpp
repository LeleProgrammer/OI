#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;

int n;

struct node {
    int a,b;
} arr[N];

bool cmp(const node& a,const node& b) {
    return a.a<b.a;
}

priority_queue< int,vector<int>,greater<int> > q;

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld %lld",&arr[i].a,&arr[i].b);
    }
    sort(arr+1,arr+1+n,cmp);
    int ans=0;
    for (int i=1;i<=n;++i) {
        if (arr[i].a<=q.size()) {
            if (arr[i].b>q.top()) {
                ans-=q.top();
                q.pop();
                ans+=arr[i].b;
                q.push(arr[i].b);
            }
        } else {
            ans+=arr[i].b;
            q.push(arr[i].b);
        }
    }
    printf("%lld",ans);
    return 0;
}