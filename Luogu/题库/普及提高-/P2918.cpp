#include <bits/stdc++.h>
using namespace std;

const int N=105;
const int H=50005;
const int P=5005;

int n,h;
int w[N];
int c[N];
int f[H+P];
int minn=0x3f3f3f3f;

int main() {
    scanf("%d %d",&n,&h);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&w[i],&c[i]);
    }
    for (int i=1;i<=n;++i) {
        for (int j=w[i];j<=H+P;++j) {
            f[j]=min(f[j],f[j-w[i]]+c[i]);
        }
    }
    for (int i=H;i<=H+P;++i) {
        minn=min(minn,f[i]);
    }
    printf("%d",minn);
    return 0;
}