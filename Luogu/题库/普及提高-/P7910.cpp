#include <bits/stdc++.h>
using namespace std;

const int N=8005;

int n,q;
int a[N];
int b[N];
int c[N];

int main() {
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        b[i]=i;
    }
    for (int i=1;i<=n;++i) {
        for (int j=i;j>=2;--j) {
            if (a[j]<a[j-1]) {
                swap(a[j],a[j-1]);
                swap(b[j],b[j-1]);
            }
        }
    }
    for (int i=1;i<=n;++i) {
        c[b[i]]=i;
    }
    while (q--) {
        int op;
        scanf("%d",&op);
        if (op==1) {
            int x,v;
            scanf("%d %d",&x,&v);
            a[c[x]]=v;
            int j=c[x];
            while (j>=2) {
                if ((a[j]<a[j-1]) || (a[j]==a[j-1] && b[j]<b[j-1])) {
                    swap(a[j],a[j-1]);
                    swap(b[j],b[j-1]);
                    --j;
                } else {
                    break;
                }
            }
            ++j;
            while (j<=n) {
                if ((a[j-1]>a[j]) || (a[j-1]==a[j] && b[j-1]>b[j])) {
                    swap(a[j-1],a[j]);
                    swap(b[j-1],b[j]);
                    ++j;
                } else {
                    break;
                }
            }
            for (int i=1;i<=n;++i) {
                c[b[i]]=i;
            }
        } else {
            int x;
            scanf("%d",&x);
            printf("%d\n",c[x]);
        }
    }
    return 0;
}