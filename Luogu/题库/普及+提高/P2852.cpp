#include <bits/stdc++.h>
using namespace std;

const int N=1000005;

typedef pair<int,int> pii;

int n,m,K;
int sa[N],cnt[N],lsh[N],st[N],rk[N],height[N];
int s[N];
deque<pii> q;
int ans;

void get_sa() {
    for (int i=1;i<=n;++i) cnt[lsh[i]=s[i]]++;
    for (int i=2;i<=m;++i) cnt[i]+=cnt[i-1];
    for (int i=n;i;--i) sa[cnt[lsh[i]]--]=i;
    for (int k=1;k<=n;k<<=1) {
        int idx=0;
        for (int i=n-k+1;i<=n;++i) st[++idx]=i;
        for (int i=1;i<=n;++i) if (sa[i]>k) st[++idx]=sa[i]-k;
        for (int i=1;i<=m;++i) cnt[i]=0;
        for (int i=1;i<=n;++i) cnt[lsh[i]]++;
        for (int i=2;i<=m;++i) cnt[i]+=cnt[i-1];
        for (int i=n;i;--i) sa[cnt[lsh[st[i]]]--]=st[i],st[i]=0;
        swap(lsh,st);
        idx=1; lsh[sa[1]]=1;
        for (int i=2;i<=n;++i) lsh[sa[i]]=(st[sa[i]]==st[sa[i-1]] && st[sa[i]+k]==st[sa[i-1]+k])?idx:++idx;
        if (idx==n) break;
        m=idx;
    }
}

void get_rk() {
    for (int i=1;i<=n;++i) rk[sa[i]]=i;
}

void get_height() {
    for (int i=1,k=0;i<=n;++i) {
        if (rk[i]==1) continue;
        if (k) k--;
        int j=sa[rk[i]-1];
        while (i+k<=n && j+k<=n && s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}

int main() {
    scanf("%d %d",&n,&K); m=1e6;
    for (int i=1;i<=n;++i) scanf("%d",&s[i]);
    get_sa();
    get_rk();
    get_height();
    // for (int i=1;i<=n;++i) {
    //     printf("%d ",height[i]);
    // }
    // putchar(10);
    for (int i=2;i<=n;++i) {
        while (!q.empty() && i-q.front().second+1>=K) q.pop_front();
        while (!q.empty() && q.back().first>=height[i]) q.pop_back();
        q.push_back({height[i],i});
        // cout<<height[i]<<" "<<i<<" "<<q.size()<<endl;
        if (i>=K-1) ans=max(ans,q.front().first);
    }
    printf("%d",ans);
    return 0;
}