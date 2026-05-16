#include <bits/stdc++.h>
using namespace std;

int T,n;
int a[6]={0,1,3,6,10,15};
int f[35];

int main() {
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for (int i=1;i<=32;++i) {
        for (int j=1;j<=5;++j) {
            if (i-a[j]<0) break;
            f[i]=min(f[i],f[i-a[j]]+1);
        }
    }
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        int cnt=0;
        if (n>=30) {
            cnt=(n-30)/15;
            n=n-((n-30)/15)*15;
            if (n>30) cnt++,n-=15;
        }
        cnt+=f[n];
        printf("%d\n",cnt);
    }
    return 0;
}

/*
1
1+2
1+2+3
1+2+3+4
1+2+3+4+5
22:
1+2+3+4+5
1+2+3
1
98=15+15+15+15+15+15+6+1+1
98=15+15+15+15+15+10+10+3
*/