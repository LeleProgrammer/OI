#include <bits/stdc++.h>
using namespace std;

const int N=1000005;

int n,m;
bool arr[N];
int a[N];

void init() {
    for (int i=0;i<=n;++i) arr[i]=true;
    arr[0]=arr[1]=false;
    for (int i=2;i<=n;++i) {
        for (int j=i+i;j<=n;j+=i) {
            arr[j]=false;
        }
    }
    for (int i=1;i<=n;++i) {
        a[i]=a[i-1]+arr[i];
    }
}

int main() {
    scanf("%d %d",&m,&n);
    init();
    while (m--) {
        int l,r;
        scanf("%d %d",&l,&r);
        if (l<1 || l>n || r<1 || r>n) puts("Crossing the line");
        else printf("%d\n",a[r]-a[l-1]);
    }
    return 0;
}