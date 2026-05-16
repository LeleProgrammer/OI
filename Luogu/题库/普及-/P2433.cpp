#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    if (n==1) {
        printf("I love Luogu!");
    } else if (n==2) {
        printf("6 4");
    } else if (n==3) {
        printf("3\n12\n2");
    } else if (n==4) {
        printf("166.667");
    } else if (n==5) {
        printf("15");
    } else if (n==6) {
        cout<<sqrt(117.00);
    } else if (n==7) {
        printf("110\n90\n0");
    } else if (n==8) {
        double r=5.00;
        double pi=3.141593;
        cout<<2*pi*r<<endl;
        cout<<pi*r*r<<endl;
        cout<<4.00/3.00*pi*r*r*r;
    } else if (n==9) {
        printf("22");
    } else if (n==10) {
        printf("9");
    } else if (n==11) {
        cout<<100.00/3.00;
    } else if (n==12) {
        printf("%d\n%c",'m'-'a'+1,'A'+18-1);
    } else if (n==13) {
        double pi=3.141593;
        double v1,v2;
        v1=4.00/3.00*pi*4*4*4;
        v2=4.00/3.00*pi*10*10*10;
        double v3=v1+v2;
        printf("%d",(int)(floor(cbrt(v3))));
    } else {
        printf("50");
    }
    return 0;
}