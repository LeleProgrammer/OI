#include <bits/stdc++.h>
using namespace std;

int G[1000005];
int R[1000005];

/*
GRGGRG
G:1 1 2 3 3 4
R:0 1 1 1 2 2
*/

int main() {
    string s;
    cin>>s;
    for (int i=0;i<s.size();++i) {
        if (s[i]=='G') {
            if (i==0) {
                G[0]=1;
                R[0]=0;
            } else {
                G[i]=G[i-1]+1;
                R[i]=R[i-1];
            }
        } else {
            if (i==0) {
                R[0]=1;
                G[0]=0;
            } else {
                R[i]=R[i-1]+1;
                G[i]=G[i-1];
            }
        }
    }
    for (int l=s.size();l>=1;--l) {
        if (G[l-1]-0==R[l-1]-0) {
            printf("%d",l);
            return 0;
        }
        for (int start=1;start+l-1<s.size();++start) {
            if (G[start+l-1]-G[start-1]==R[start+l-1]-R[start-1]) {
                printf("%d",l);
                return 0;
            }
        }
    }
    printf("0");
    return 0;
}