#include <bits/stdc++.h>
using namespace std;

const int N=1000005;

int n,m;
char s[N];
int sa[N],cnt[N],lsh[N],st[N];

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

int main() {
    scanf("%s",s+1); n=strlen(s+1); m=255;
    get_sa();
    for (int i=1;i<=n;++i) printf("%d ",sa[i]);
    return 0;
}