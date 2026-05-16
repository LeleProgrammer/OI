#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n,w;
int a[N];
int b[N];

int main() {
    scanf("%d %d",&n,&w);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;++i) {
        b[a[i]]++;
        int k=max(1,i*w/100);
        // cout<<k<<endl;
        int p=0;
        for (int j=600;~j;--j) {
            p+=b[j];
            if (p>=k) {
                printf("%d ",j);
                break;
            }
        }
    }
    return 0;
}