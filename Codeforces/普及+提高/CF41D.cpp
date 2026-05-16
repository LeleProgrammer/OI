#include <bits/stdc++.h>
using namespace std;

const int N=105;
const int M=15;

int n,m,k;
int a[N][N];
int f[N][N][M];
int g[N][N][M];

int main() {
    scanf("%d %d %d",&n,&m,&k); k++;
    for (int i=n;i;--i) {
        for (int j=m;j;--j) {
            scanf("%1d",&a[i][j]);
        }
    }
    memset(f,-1,sizeof(f));
    for (int i=1;i<=m;++i) {
        f[1][i][a[1][i]%k]=a[1][i];
    }
    for (int i=2;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            for (int p=0;p<k;++p) {
                if (j!=1 && ~f[i-1][j-1][(p-a[i][j]+k*100)%k]) {
                    f[i][j][p]=max(f[i][j][p],f[i-1][j-1][(p-a[i][j]+k*100)%k]+a[i][j]);
                }
                if (j!=m && ~f[i-1][j+1][(p-a[i][j]+k*100)%k]) {
                    f[i][j][p]=max(f[i][j][p],f[i-1][j+1][(p-a[i][j]+k*100)%k]+a[i][j]);
                }
            }
        }
    }
    int ans=-1;
    for (int i=1;i<=m;++i) {
        ans=max(ans,f[n][i][0]);
    }
    if (!~ans) printf("-1");
    else {
        vector<char> res;
        int j,p=0;
        for (int i=1;i<=m;++i) {
            if (f[n][i][0]==ans) {
                j=i;
                break;
            }
        }
        for (int i=n;i>=2;--i) {
            if (j!=1 && f[i-1][j-1][(p-a[i][j]+k*100)%k]!=-1 && f[i-1][j-1][(p-a[i][j]+k*100)%k]+a[i][j]==f[i][j][p]) {
                p=(p-a[i][j--]+k*100)%k;
                res.push_back('L');
            } else if (j!=m && f[i-1][j+1][(p-a[i][j]+k*100)%k]!=-1 && f[i-1][j+1][(p-a[i][j]+k*100)%k]+a[i][j]==f[i][j][p]) {
                p=(p-a[i][j++]+k*100)%k;
                res.push_back('R');
            }
        }
        reverse(res.begin(),res.end());
        printf("%d\n",ans);
        printf("%d\n",m-j+1);
        for (int i=0;i<res.size();++i) {
            printf("%c",res[i]);
        }
    }
    return 0;
}

/*
4 3 10
194
707
733
633
*/