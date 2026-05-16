#include <bits/stdc++.h>
using namespace std;

const int MAXN=5005;

int n;

int h[MAXN],t[MAXN];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",h+i);
    }
    memset(t,0x3f,sizeof t);
    for (int i=1;i<=n;++i) {
        int s,r,l;
        for (l=i,r=i,s=0;l>=1 && r<=n;--l,++r) {
            s+=abs(h[l]-h[r]);
            t[r-l+1]=min(t[r-l+1],s);
        }
        for (l=i,r=i+1,s=0;l>=1 && r<=n;--l,++r) {
            s+=abs(h[l]-h[r]);
            t[r-l+1]=min(t[r-l+1],s);
        }
    }
    for (int i=1;i<=n;++i) {
        printf("%d ",t[i]);
    }
    return 0;
}