#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,K;
int f[10][1<<9][82];
int ans=0;

inline int count1s(int k) {
    return ((k>>0)&1)+((k>>1)&1)+((k>>2)&1)+((k>>3)&1)+((k>>4)&1)+((k>>5)&1)+((k>>6)&1)+((k>>7)&1)+((k>>8)&1);
}

signed main() {
    scanf("%lld %lld",&n,&K);
    for (int i=0;i<=(1<<n)-1;++i) {
        if ((i&(i<<1))==0) f[1][i][count1s(i)]=1;
    }
    for (int i=2;i<=n;++i) {
        for (int j=0;j<=(1<<n)-1;++j) {
            for (int p=0;p<=(1<<n)-1;++p) {
                for (int k=count1s(j);k<=K;++k) {
                    if (((j&p)==0) && ((j&(p<<1))==0) && ((j&(p>>1))==0) && ((j&(j<<1))==0)) {
                        f[i][j][k]+=f[i-1][p][k-count1s(j)];
                    }
                }
            }
        }
    }
    for (int i=0;i<=(1<<n)-1;++i) {
        ans+=f[n][i][K];
    }
    printf("%lld",ans);
    return 0;
}