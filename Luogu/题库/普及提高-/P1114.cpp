#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
int b[100005];

/*
 0 1  0  0  0  1  1  0  0
-1 0 -1 -2 -3 -2 -1 -2 -3
*/

int zdh(int l,int r) { // ×Ó¶ÎºÍ
    if (l==0) {
        return b[r];
    }
    return b[r]-b[l-1];
}

int main() {
    scanf("%d",&n);
    scanf("%d",arr);
    if (arr[0]==0) {
        arr[0]=-1;
    }
    b[0]=arr[0];
    for (int i=1;i<n;++i) {
        scanf("%d",arr+i);
        if (arr[i]==0) {
            arr[i]=-1;
        }
        b[i]=arr[i]+b[i-1];
    }
    for (int length=n;length>=0;--length) {
        if (length%2==0) {
            for (int l=0;l<n-length+1;++l) {
                if (zdh(l,l+length-1)==0) {
                    printf("%d",length);
                    return 0;
                }
            }
        }
    }
    printf("0");
    return 0;
}