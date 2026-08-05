#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=300005;

int n,m;
int len[2];
int cnt[2];
int ans;

struct node {
    int v;
    int type;
    friend bool operator < (const node& a,const node& b) {
        return a.v<b.v;
    }
} arr[N<<1];

signed main() {
    scanf("%lld %lld",&n,&m);
    len[0]=m-1,len[1]=n-1;
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i].v);
        arr[i].type=0;
    }
    for (int i=1;i<=m;++i) {
        scanf("%lld",&arr[n+i].v);
        arr[n+i].type=1;
    }
    sort(arr+1,arr+1+n+m);
    for (int i=1;i<=n+m;++i) {
        int v,type;
        v=arr[i].v;
        type=arr[i].type;
        int t;
        if (!cnt[type^1] || !cnt[type]) t=0;
        else t=cnt[type^1]-1;
        t=len[type]-t;
        if (!t) continue;
        ans+=t*v;
        cnt[type]++;
    }
    printf("%lld",ans);
    return 0;
}