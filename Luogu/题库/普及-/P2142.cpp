#include <bits/stdc++.h>
using namespace std;

int a[10087],b[10087],c[10087];
char ina[10087],inb[10087],tmp[10087];

int main() {
    int lena,lenb,lenc;
    cin>>ina>>inb;
    if (strlen(ina)<strlen(inb) || (strlen(ina)==strlen(inb) && strcmp(ina,inb)<0)) {
        strcpy(tmp,ina);
        strcpy(ina,inb);
        strcpy(inb,tmp);
        printf("-");
    }
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    lena=strlen(ina);
    lenb=strlen(inb);
    lenc=lena;
    for (int i=0;i<lena;++i) {
        a[i]=ina[lena-i-1]-'0';
    }
    for (int i=0;i<lenb;++i) {
        b[i]=inb[lenb-i-1]-'0';
    }
    for (int i=0;i<lenc;++i) {
        if (a[i]<b[i]) {
            --a[i+1];
            a[i]+=10;
        }
        c[i]=a[i]-b[i];
    }
    for (int i=lenc-1;i>=0;--i) {
        if (c[i]==0 && lenc>1) --lenc;
        else break;
    }
    for (int i=lenc-1;i>=0;--i) {
        printf("%d",c[i]);
    }
    return 0;
}