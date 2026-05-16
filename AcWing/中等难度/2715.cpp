#include <bits/stdc++.h>
using namespace std;

const int N=1000005;

int n,m;
char s[N];
int sa[N],height[N],rk[N],cnt[N],lsh[N],st[N];

void get_sa() {
    for (int i=1;i<=n;++i) cnt[lsh[i]=s[i]]++;
    for (int i=2;i<=m;++i) cnt[i]+=cnt[i-1];
    for (int i=n;i;--i) sa[cnt[lsh[i]]--]=i;
    for (int k=1;k<=n;k<<=1) {
        int idx=0;
        for (int i=n-k+1;i<=n;++i) st[++idx]=i;
        for (int i=1;i<=n;++i) if (sa[i]>k) st[++idx]=sa[i]-k;
        memset(cnt,0,sizeof(cnt));
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
    height[1]=0;
    for (int i=1,k=0;i<=n;++i) {
        if (rk[i]==1) continue;
        if (k) k--;
        int j=sa[rk[i]-1];
        while (i+k<=n && j+k<=n && s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}

int main() {
    scanf("%s",s+1); n=strlen(s+1); m=255;
    get_sa();
    get_rk();
    get_height();
    for (int i=1;i<=n;++i) printf("%d ",sa[i]); putchar(10);
    for (int i=1;i<=n;++i) printf("%d ",height[i]);
    return 0;
}