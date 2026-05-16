#include <bits/stdc++.h>

#define int long long
#define inf 1000000000000000000

using namespace std;

const int N=200005;
const int M=200005;

int n,m;
int x[M];
int now,ne;
int ans;
int a[M],b[M];
int pre[N];

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=m;++i) scanf("%lld",&x[i]);
    for (int i=1;i<=m-1;++i) {
        now=x[i],ne=x[i+1];
        if (ne>now) swap(ne,now);
        a[i]=now-ne,b[i]=n-a[i];
        int sub=abs(a[i]-b[i]);
        if (a[i]<b[i]) {
            pre[now]-=sub;
            pre[ne]+=sub;
        } else if (a[i]>b[i]) {
            pre[now]+=sub;
            pre[n+1]-=sub;
            pre[1]+=sub;
            pre[ne]-=sub;
        }
        ans+=min(a[i],b[i]);
    }
    int minn=inf;
    int now=0;
    for (int i=1;i<=n;++i) {
        now+=pre[i];
        minn=min(minn,now);
    }
    printf("%lld\n",ans+minn);
    return 0;
}