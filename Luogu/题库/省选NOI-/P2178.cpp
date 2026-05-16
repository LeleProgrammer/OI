#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=300005;
const int inf=9e18;

typedef pair<int,int> pii;

int n,m;
char s[N];
int sa[N],cnt[N],lsh[N],st[N],height[N],rk[N];
int arr[N];
int p[N];
int mx[N],smx[N],mn[N],smn[N];
int sz[N];
vector<int> h[N];
pii ans[N];

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

int find(int x) {
    return (p[x]==x)?p[x]:(p[x]=find(p[x]));
}

int C(int k) {
    return k*(k-1)/2;
}

int cc=0,mxx=-inf;

pii solve(int k) {
    int &cnt=cc;
    for (int i=0;i<h[k].size();++i) {
        int x=h[k][i];
        int a=find(x),b=find(x-1);
        p[b]=a;
        cnt-=C(sz[a]);
        cnt-=C(sz[b]);
        sz[a]+=sz[b];
        cnt+=C(sz[a]);
        int c,d;
        c=max(mx[a],mx[b]);
        if (c==mx[a]) {
            d=max(mx[b],smx[a]);
        } else {
            d=max(mx[a],smx[b]);
        }
        mx[a]=c,smx[a]=d;
        c=min(mn[a],mn[b]);
        if (c==mn[a]) {
            d=min(smn[a],mn[b]);
        } else {
            d=min(mn[a],smn[b]);
        }
        mn[a]=c,smn[a]=d;
        // if (mx[b]>=mx[a]) {
        //     smx[a]=max(mx[a],smx[b]);
        //     mx[a]=mx[b];
        // } else if (mx[b]>smx[a]) smx[a]=mx[b];
        // if (mn[b]<=mn[a]) {
        //     smn[a]=min(mn[a],smn[b]);
        //     mn[a]=mn[b];
        // } else if (mn[b]<smn[a]) smn[a]=mn[b];
        mxx=max(mxx,mx[a]*smx[a]);
        mxx=max(mxx,mn[a]*smn[a]);
    }
    if (mxx==-inf) return {cnt,0LL};
    return {cnt,mxx};
}

signed main() {
    scanf("%lld",&n); m=255;
    scanf("%s",s+1);
    for (int i=1;i<=n;++i) scanf("%lld",&arr[i]);
    get_sa();
    get_rk();
    get_height();
    for (int i=1;i<=n;++i) p[i]=i,sz[i]=1,mx[i]=mn[i]=arr[sa[i]],smx[i]=-inf,smn[i]=inf;
    for (int i=2;i<=n;++i) h[height[i]].push_back(i);
    for (int i=n-1;~i;--i) ans[i]=solve(i);
    for (int i=0;i<=n-1;++i) printf("%lld %lld\n",ans[i].first,ans[i].second);
    return 0;
}