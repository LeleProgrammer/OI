#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int T,n,k;
int a[N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&k);
        for (int i=1;i<=n;++i) a[i]=0;
        int i=n,j;
        for (j=1;j<=n;j+=k) {
            a[j]=i;
            i--;
        }
        if (j>n) j-=k;
        int stop=j;
        if (j!=n) {
            j++;
            // cout<<"STOP: "<<stop<<endl;
            for (int g=1;g<=n-stop;++g) {
                if (g%2) {
                    for (;j>=1;j-=k) {
                        // cout<<"TEST: "<<j<<" "<<i<<endl;
                        a[j]=i;
                        i--;
                    }
                    if (j<=0) j+=k;
                    j++;
                } else {
                    for (;j<=n;j+=k) {
                        // cout<<"TEST: "<<j<<" "<<i<<endl;
                        a[j]=i;
                        i--;
                    }
                    if (j>n) j-=k;
                    j++;
                }
            }
        }
        j=stop-1;
        while (i>=1) {
            for (int g=1;i>=1;++g) {
                if (g%2) {
                    for (;j>=1;j-=k) {
                        // cout<<"TEST: "<<j<<" "<<i<<endl;
                        a[j]=i;
                        i--;
                    }
                    if (j<=0) j+=k;
                    j--;
                } else {
                    for (;j<=n;j+=k) {
                        // cout<<"TEST: "<<j<<" "<<i<<endl;
                        a[j]=i;
                        i--;
                    }
                    if (j>n) j-=k;
                    j--;
                }
            }
        }
        for (int i=1;i<=n;++i) printf("%d ",a[i]);
        putchar(10);
    }
    return 0;
}