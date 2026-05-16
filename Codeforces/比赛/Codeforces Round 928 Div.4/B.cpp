#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        char c;
        int last=0;
        int conn=0;
        int ans=0; // 1:sq 2:tri
        for (int i=1;i<=n;++i) {
            conn=0;
            for (int j=1;j<=n;++j) {
                scanf(" %c",&c);
                if (c=='1') conn++;
            }
            if (!conn) continue;
            if (!last) last=conn;
            if (conn!=last) {
                ans=2;
            } else {
                ans=1;
            }
        }
        if (ans==1) puts("SQUARE");
        else puts("TRIANGLE");
    }
    return 0;
}