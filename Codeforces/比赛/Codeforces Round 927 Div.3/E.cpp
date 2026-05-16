#include <bits/stdc++.h>
using namespace std;

const int N=400505;

int T,n;
char a[N];
int sum[N];
int ans[N],tot;
int jw;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        scanf("%s",a+1);
        tot=0; sum[0]=0;
        for (int i=1;i<=n+10;++i) sum[i]=ans[i]=0;
        for (int i=1;i<=n;++i) {
            sum[i]=sum[i-1]+(a[i]-'0');
        }
        reverse(sum+1,sum+1+n);
        jw=0;
        for (int i=1;i<=n || jw;++i) {
            ans[++tot]=sum[i]+jw;
            jw=ans[tot]/10;
            ans[tot]%=10;
        }
        while (!ans[tot]) tot--;
        for (int i=tot;i>=1;--i) {
            printf("%d",ans[i]);
        }
        putchar(10);
    }
    return 0;
}