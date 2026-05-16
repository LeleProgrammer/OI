#include <bits/stdc++.h>
using namespace std;

const int N=105;

int T;
int x[N],y[N];
// int a1[N],a2[N];
int lenx,leny;

int main() {
    scanf("%d",&T);
    while (T--) {
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        // memset(a1,0,sizeof(a1));
        // memset(a2,0,sizeof(a2));
        string a,b;
        cin>>a>>b;
        lenx=a.size();
        leny=b.size();
        for (int i=a.size()-1;i>=0;--i) {
            x[a.size()-i]=a[i]-'0';
        }
        for (int i=b.size()-1;i>=0;--i) {
            y[b.size()-i]=b[i]-'0';
        }
        // int jw=0,lena1=0;
        // while (len1<max(lenx,leny) || jw) {
        //     lena1++;
        //     a1[lena1]=x[lena1]+y[lena1]+jw;
        //     jw=a1[lena1]/10;
        //     a1[lena1]%=10;
        // }
        // int k=0,lena2=0;
        // for (int i=lena1;i>=1;--i) {
        //     k=k*10+a1[i];
        //     if (k<2) continue;
        //     lena2=max(lena2,i);
        //     a2[i]=k/2;
        //     k%=2;
        // }
        int sta=0; // 0: equal
        for (int i=lenx;i>=1;--i) {
            if (x[i]==y[i]) continue;
            if (!sta) {
                if (y[i]<x[i]) swap(x[i],y[i]);
                sta=1;
            } else if (sta==1) {
                if (y[i]>x[i]) swap(x[i],y[i]);
            }
        }
        for (int i=lenx;i>=1;--i) {
            printf("%d",x[i]);
        }
        putchar(10);
        for (int i=leny;i>=1;--i) {
            printf("%d",y[i]);
        }
        putchar(10);
    }
    return 0;
}

/*
1573
1269

avg:1421

1563
1279

15234
  253
*/