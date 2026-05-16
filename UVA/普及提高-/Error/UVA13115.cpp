#include <bits/stdc++.h>
using namespace std;

int T,n;
int sudoku[30][30];
bool flag[30];
bool ok;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                scanf("%d",&sudoku[i][j]);
            }
        }
        bool check=true;
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                if (sudoku[i][j]>n || sudoku[i][j]<1) {
                    check=false;
                    break;
                }
            }
            if (!check) break;
        }
        if (!check) {
            if (T==0) printf("no");
            else printf("no\n");
            continue;
        }
        check=true;
        for (int i=1;i<=n;++i) {
            memset(flag,false,sizeof(flag));
            ok=true;
            for (int j=1;j<=n;++j) {
                if (!flag[sudoku[i][j]]) flag[sudoku[i][j]]=true;
                else {
                    ok=false;
                    break;
                }
            }
            if (!ok) {
                check=false;
                break;
            }
        }
        if (!check) {
            if (T==0) printf("no");
            else printf("no\n");
            continue;
        }
        check=true;
        for (int j=1;j<=n;++j) {
            memset(flag,false,sizeof(flag));
            ok=true;
            for (int i=1;i<=n;++i) {
                if (!flag[sudoku[i][j]]) flag[sudoku[i][j]]=true;
                else {
                    ok=false;
                    break;
                }
            }
            if (!ok) {
                check=false;
                break;
            }
        }
        if (!check) {
            if (T==0) printf("no");
            else printf("no\n");
        }
        check=true;
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                memset(flag,false,sizeof(flag));
                ok=true;
                for (int a=i;a<=i+sqrt(n)-1;++a) {
                    for (int b=j;b<=j+sqrt(n)-1;++b) {
                        if (!flag[sudoku[a][b]]) flag[sudoku[a][b]]=true;
                        else {
                            ok=false;
                            break;
                        }
                    }
                    if (!ok) break;
                }
                if (!ok) {
                    check=false;
                    break;
                }
            }
            if (!check) break;
        }
        if (!check) {
            if (T==0) printf("no");
            else printf("no\n");
            continue;
        }
        if (T==0) printf("yes");
        else printf("yes\n");
        continue;
    }
    return 0;
}