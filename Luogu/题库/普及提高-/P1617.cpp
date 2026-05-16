#include <bits/stdc++.h>
using namespace std;

int n;
string nums[20]={
    "zero","one","two","three","four","five",
    "six","seven","eight","nine","ten","eleven",
    "twelve","thirteen","fourteen","fifteen","sixteen",
    "seventeen","eighteen","nineteen"
};
string tens[10]={
    "nothing","ten","twenty","thirty","forty","fifty",
    "sixty","seventy","eighty","ninety"
};

int main() {
    scanf("%d",&n);
    if (n<=19) cout<<nums[n];
    else if (n<=99) {
        cout<<tens[n/10]<<" ";
        if (n%10) cout<<nums[n%10];
    } else if (n<=999) {
        cout<<nums[n/100]<<" hundred ";
        if ((n%100)/10>=2) cout<<tens[(n%100)/10]<<" ";
        else if ((n%100)/10==1) cout<<nums[n%100];
        else cout<<"and ";
        if ((n%100)/10!=1) cout<<nums[n%10];
    } else if (n<=9999) {
        if ((n%1000)/100==0 && (n%100)/10==0 && (n%10==0)) cout<<nums[n/1000]<<" thousand "; // x000
        else if ((n%1000)/100==0 && (n%100)/10==0) cout<<nums[n/1000]<<" thousand and "<<nums[n%10]; // x00x
        else if ((n%1000)/100==0 && (n%10==0)) cout<<nums[n/1000]<<" thousand and "<<tens[(n%100)/10]; // x0x0
        else if ((n%100)/10==0 && (n%10==0)) cout<<nums[n/1000]<<" thousand "<<nums[(n%1000)/100]<<" hundred"; // xx00
        else if ((n%10==0)) cout<<nums[n/1000]<<" thousand "<<nums[(n%1000)/100]<<" hundred "<<tens[(n%100)/10]; // xxx0
        else if ((n%100)/10==0) cout<<nums[n/1000]<<" thousand "<<nums[(n%1000)/100]<<" hundred and "<<nums[n%10]; // xx0x
        else if ((n%1000)/100==0 && (n%100)/10==1) cout<<nums[n/1000]<<" thousand and "<<nums[n%100]; // x01x
        else if ((n%1000)/100==0) cout<<nums[n/1000]<<" thousand and "<<tens[(n%100)/10]<<" "<<nums[n%10]; // x0xx
        else if ((n%100)/10==1) cout<<nums[n/1000]<<" thousand "<<nums[(n%1000)/100]<<" hundred "<<nums[n%100]; // xx1x
        else cout<<nums[n/1000]<<" thousand "<<nums[(n%1000)/100]<<" hundred "<<tens[(n%100)/10]<<" "<<nums[n%10]; // xxxx
    }
    return 0;
}