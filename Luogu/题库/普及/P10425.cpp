#include <bits/stdc++.h>
using namespace std;

const int N=1000005;

int n;
int a[N];
int len;
int mt;

int main() {
    scanf("%d",&n);
    string d;
    cin>>d;
    bool flag=false;
    for (int i=d.size()-1;~i;--i) {
        if (d[i]=='.') {
            flag=true;
            continue;
        }
        a[++len]=d[i]-'0';
        if (!flag) mt++;
    }
    for (int i=1;i<=n;++i) {
        int j=1,jw=0;
        while (j<=len || jw) {
            a[j]<<=1;
            a[j]+=jw;
            jw=a[j]/10;
            a[j]%=10;
            ++j;
        }
        --j;
        len=j;
    }
    if (a[mt]>=5) {
        int i=mt+1;
        a[i]++;
        while (a[i]>=10) {
            a[i+1]+=a[i]/10;
            a[i]%=10;
            ++i;
        }
    }
    int t=N-1;
    while (t>=mt+1 && !a[t]) t--;
    if (t<mt+1) puts("0");
    else {
        for (int i=t;i>=mt+1;--i) {
            printf("%d",a[i]);
        }
    }
    return 0;
}