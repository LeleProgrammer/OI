#include <bits/stdc++.h>
using namespace std;

const int N=405;
const int M=400005;
const int inf=2e9;

int n;
int a[N],b[N];
int f[M];
int ans,sum;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d %d",&a[i],&b[i]),sum+=a[i]<0?0:a[i];
    for (int i=0;i<=M-1;++i) f[i]=-inf;
    f[0]=0;
    for (int i=1;i<=n;++i) {
        if (a[i]<0) {
            for (int j=0;j<=sum+a[i];++j) {
                f[j]=max(f[j],f[j-a[i]]+b[i]);
                cout<<i<<" "<<j<<" "<<f[j]<<endl;
            }
        } else {
            for (int j=sum;j>=a[i];--j) {
                f[j]=max(f[j],f[j-a[i]]+b[i]);
                cout<<i<<" "<<j<<" "<<f[j]<<endl;
            }
        }
    }
    for (int i=0;i<=sum;++i) {
        if (f[i]<0) continue;
        ans=max(ans,f[i]+i);
    }
    printf("%d",ans);
    return 0;
}