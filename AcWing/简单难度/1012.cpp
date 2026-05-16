#include <bits/stdc++.h>
using namespace std;

const int N=5005;

int n;
int a[N];
int f[N];

struct node {
    int a,b;
    friend bool operator < (const node& a,const node& b) {
        return a.a<b.a;
    }
} arr[N];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d %d",&arr[i].a,&arr[i].b);
    sort(arr+1,arr+1+n);
    for (int i=1;i<=n;++i) a[i]=arr[i].b;
    for (int i=1;i<=n;++i) f[i]=1;
    for (int i=2;i<=n;++i) for (int j=1;j<=i-1;++j) if (a[j]<a[i]) f[i]=max(f[i],f[j]+1);
    int ans=0;
    for (int i=1;i<=n;++i) ans=max(ans,f[i]);
    printf("%d",ans);
    return 0;
}