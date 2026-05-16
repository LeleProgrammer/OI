#include <bits/stdc++.h>
using namespace std;

const int N=55;

int T;
int n;
char str[N];
int f[N];
int ans;
int conn;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        scanf("%s",str+1);
        memset(f,0,sizeof(f));
        ans=0;
        conn=0;
        for (int i=2;i<=n;++i) {
            if (str[i]!='*') {
                conn=0;
                if (i>=3) f[i]=max(f[i-1],f[i-2]);
                else f[i]=f[i-1];
                if (str[i]=='@') f[i]++;
                ans=max(ans,f[i]);
            } else conn++;
            if (conn>=2) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}