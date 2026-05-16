#include <bits/stdc++.h>
using namespace std;

int n;
string k;

int merge(int k) {
    int res=0;
    while (k) {
        res+=k%10;
        k/=10;
    }
    return res;
}

int main() {
    scanf("%d",&n);
    while (n--) {
        cin>>k;
        int num=0;
        int val;
        for (int i=k.size()-1;i>=0;i-=2) {
            val=k[i]-'0';
            val*=7;
            while (val>9) {
                val=merge(val);
            }
            k[i]=val+'0';
        }
        for (int i=0;i<k.size();++i) {
            num+=k[i]-'0';
        }
        if (num%8==0) {
            printf("T\n");
        } else {
            printf("F\n");
        }
    }
    return 0;
}