#include <bits/stdc++.h>

#define mod 1000000007
#define int long long

using namespace std;

char str[705];
int n;
int f[705][705][3][3];
int mat[705],rmat[705];
int ans=0;

void init() {
    stack<int> stk;
    for (int i=1;i<=n;++i) {
        if (str[i]=='(') {
            stk.push(i);
        } else {
            mat[stk.top()]=i;
            rmat[i]=stk.top();
            stk.pop();
        }
    }
}

signed main() {
    scanf("%s",str+1);
    n=strlen(str+1);
    memset(mat,0,sizeof(mat));
    memset(rmat,0,sizeof(rmat));
    init();
    memset(f,0,sizeof(f));
    for (int i=1;i<=n-1;++i) {
        if (mat[i]==i+1) {
            f[i][i+1][0][1]=1;
            f[i][i+1][0][2]=1;
            f[i][i+1][1][0]=1;
            f[i][i+1][2][0]=1;
        }
    }
    for (int len=4;len<=n;len+=2) {
        for (int l=1,r=l+len-1;r<=n;++l,++r) {
            if (mat[l]==r) { // (...)
                for (int a=0;a<=2;++a) {
                    for (int b=0;b<=2;++b) {
                        for (int c=0;c<=2;++c) {
                            for (int d=0;d<=2;++d) {
                                if ((a==c && a!=0) || (b==d && b!=0)) continue;
                                // if (a==0 && b==0) continue;
                                // if (a!=0 && b!=0) continue;
                                // if (c!=0 && d!=0) continue;
                                // if (c==0 && d==0) continue;
                                f[l][r][a][b]+=f[l+1][r-1][c][d];
                                f[l][r][a][b]%=mod;
                            }
                        }
                    }
                }
            } else if (mat[mat[l]+1]==r) { // (...)(...)
                for (int a=0;a<=2;++a) {
                    for (int b=0;b<=2;++b) {
                        for (int c=0;c<=2;++c) {
                            for (int d=0;d<=2;++d) {
                                if (b==c && b!=0) continue;
                                // if (a!=0 && b!=0) continue;
                                // if (a==0 && b==0) continue;
                                // if (c!=0 && d!=0) continue;
                                // if (c==0 && d==0) continue;
                                f[l][r][a][d]+=f[l][mat[l]][a][b]*f[mat[l]+1][r][c][d];
                                f[l][r][a][d]%=mod;
                            }
                        }
                    }
                }
            } else if (l<mat[l] && mat[l]<r && l<rmat[r] && rmat[r]<r) { // (...)...(...)
                for (int a=0;a<=2;++a) {
                    for (int b=0;b<=2;++b) {
                        for (int c=0;c<=2;++c) {
                            for (int d=0;d<=2;++d) {
                                if (a!=0 && b!=0) continue;
                                // if (a==0 && b==0) continue;
                                // if (c!=0 && d!=0) continue;
                                // if (c==0 && d==0) continue;
                                f[l][r][a][d]+=f[l][mat[l]][a][b]*f[rmat[r]][r][c][d];
                                f[l][r][a][d]%=mod;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int a=0;a<=2;++a) {
        for (int b=0;b<=2;++b) {
            if (a!=0 && b!=0) continue;
            if (a==0 && b==0) continue;
            ans+=f[1][n][a][b];
            ans%=mod;
        }
    }
    printf("%lld",ans);
    return 0;
}