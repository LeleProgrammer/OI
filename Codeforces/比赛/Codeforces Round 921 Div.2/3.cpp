#include <bits/stdc++.h>
using namespace std;

int T,n,k,m;
char s[1005];
int cnt[35];
int pre[1005][35];
int now[35];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d %d",&n,&k,&m);
        scanf("%s",s+1);
        memset(cnt,0,sizeof(cnt));
        memset(pre[0],0,sizeof(pre[0]));
        for (int i=1;i<=m;++i) {
            cnt[s[i]-'a']++;
            for (int j=0;j<=k-1;++j) {
                pre[i][j]=pre[i-1][j];
                if (j==s[i]-'a') {
                    pre[i][j]++;
                }
            }
        }
        bool ok=true;
        int ans1;
        for (int i=0;i<=k-1;++i) {
            if (cnt[i]<n) {
                ans1=i;
                ok=false;
                break;
            }
        }
        if (!ok) {
            puts("NO");
            for (int i=1;i<=n;++i) printf("%c",char(ans1+'a'));
            putchar(10);
            continue;
        } else {
            memset(now,0,sizeof(now));
            bool yes=true;
            for (int i=1;i<=m;++i) {
                now[s[i]-'a']++;
                bool ok=true;
                int ans2;
                for (int j=0;j<=k-1;++j) {
                    if ((pre[m][j]-pre[i][j])<n-now[s[i]-'a']) {
                        ok=false;
                        ans2=j;
                        break;
                    }
                }
                if (!ok) {
                    puts("NO");
                    for (int j=1;j<=now[s[i]-'a'];++j) {
                        printf("%c",s[i]);
                    }
                    for (int j=1;j<=n-now[s[i]-'a'];++j) {
                        printf("%c",char(ans2+'a'));
                    }
                    putchar(10);
                    yes=false;
                    break;
                }
            }
            if (!yes) {
                continue;
            }
            puts("YES");
        }
    }
    return 0;
}