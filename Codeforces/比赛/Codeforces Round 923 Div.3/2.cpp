#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int T,n,a[N];
int cnt[35];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d",a+i);
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;++i) {
            for (int j=0;j<=25;++j) {
                if (cnt[j]==a[i]) {
                    printf("%c",char(j+'a'));
                    cnt[j]++;
                    break;
                }
            }
        }
        putchar(10);
    }
    return 0;
}

/*
abracadabra
00010203114
*/