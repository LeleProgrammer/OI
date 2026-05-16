#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=505;
const int mod=1e9+7;

int n,k;
int f[N][N]; // A
int s[N][N]; // S
int p[N][N]; // AS
char arr[N];

bool checkPair(int i,int j) {
    bool ans1=arr[i]=='(' || arr[i]=='?';
    bool ans2=arr[j]==')' || arr[j]=='?';
    return ans1 && ans2;
}

signed main() {
    scanf("%lld %lld",&n,&k);
    scanf("%s",arr+1);
    for (int len=1;len<=k;++len) {
        for (int i=1,j=len;j<=n;++i,++j) {
            bool ok=true;
            for (int k=i;k<=j;++k) {
                if (arr[k]!='?' && arr[k]!='*') {
                    ok=false;
                    break;
                }
            }
            if (ok) s[i][j]=1;
            else s[i][j]=0;
        }
    }
    for (int len=2;len<=n;++len) {
        for (int i=1,j=len;j<=n;++i,++j) {
            for (int k=i;k<j;++k) {
                p[i][j]+=f[i][k]*s[k+1][j];
                p[i][j]%=mod;
            }
            if (!checkPair(i,j)) continue;
            if (len==2) {
                f[i][j]=1; // ()
            } else {
                for (int k=i;k<j;++k) {
                    f[i][j]+=f[i][k]*f[k+1][j]; f[i][j]%=mod; // AB
                    if (i==2 && j==9) cout<<1<<" "<<f[i][j]<<endl;
                    f[i][j]+=p[i][k]*f[k+1][j]; f[i][j]%=mod; // ASB
                    if (i==2 && j==9) cout<<2<<" "<<f[i][j]<<" "<<p[i][k]<<endl;
                }
                f[i][j]+=s[i+1][j-1]; f[i][j]%=mod; // (S)
                if (i==2 && j==9) cout<<3<<" "<<f[i][j]<<endl;
                f[i][j]+=f[i+1][j-1]; f[i][j]%=mod; // (A)
                if (i==2 && j==9) cout<<4<<" "<<f[i][j]<<endl;
                f[i][j]+=p[i+1][j-1]; f[i][j]%=mod; // (AS)
                if (i==2 && j==9) cout<<5<<" "<<f[i][j]<<endl;
                for (int k=i+1;k<j-1;++k) {
                    f[i][j]+=s[i+1][k]*f[k+1][j-1]; f[i][j]%=mod; // (SA)
                    if (i==2 && j==9) cout<<6<<" "<<f[i][j]<<endl;
                }
            }
            printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
            // printf("p[%lld][%lld]=%lld\n",i,j,p[i][j]);
        }
    }
    printf("%lld",f[1][n]);
    return 0;
}

/*
f 数组或许需要再按情况分出来。
(x(x))()
()(xx)()
()(x)x()
这三种情况，在代码注释 AB 那一行，k=3 时 2 3 两种情况被计入，
k=7 时情况 1 被 AB 计入，情况 2 会重复计入一次，
情况 3 会被 ASB 重复计入一次，所以相较于正解 f[2][9] 多计入了两次。
*/