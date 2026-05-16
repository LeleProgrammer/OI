#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=505;
const int mod=1e9+7;

int n,k;
char arr[N];
int s[N][N];
int f[N][N][5];

bool check(int i,int j) {
    bool ans1=arr[i]=='?' || arr[i]=='(';
    bool ans2=arr[j]=='?' || arr[j]==')';
    return ans1 && ans2;
}

signed main() {
    scanf("%lld %lld",&n,&k);
    scanf("%s",arr+1);
    for (int len=1;len<=n;++len) {
        for (int i=1,j=len;j<=n;++i,++j) {
            bool ok=len<=k;
            for (int k=i;k<=j && ok;++k) {
                if (arr[k]!='*' && arr[k]!='?') ok=false;
            }
            if (ok) s[i][j]=1;
            if (len==1) continue;
            if (check(i,j)) {
                if (len==2) f[i][j][0]=1;
                else f[i][j][0]=s[i+1][j-1]+f[i+1][j-1][1]+f[i+1][j-1][2]+f[i+1][j-1][3]+f[i+1][j-1][4]; f[i][j][0]%=mod;
                for (int k=i;k<j;++k) {
                    f[i][j][1]+=f[i][k][0]*(f[k+1][j][0]+f[k+1][j][1]);
                    f[i][j][1]%=mod;
                    f[i][j][4]+=f[i][k][3]*(f[k+1][j][0]+f[k+1][j][1]);
                    f[i][j][4]%=mod;
                }
            }
            for (int k=i;k<j;++k) {
                f[i][j][2]+=s[i][k]*(f[k+1][j][0]+f[k+1][j][1]);
                f[i][j][2]%=mod;
                f[i][j][3]+=(f[i][k][0]+f[i][k][1])*s[k+1][j];
                f[i][j][3]%=mod;
            }
            printf("%lld %lld:\n",i,j);
            printf("%lld %lld %lld %lld %lld\n\n",f[i][j][0],f[i][j][1],f[i][j][2],f[i][j][3],f[i][j][4]);
        }
    }
    int ans=f[1][n][0]+f[1][n][1]+f[1][n][4];
    printf("%lld",ans);
    return 0;
}