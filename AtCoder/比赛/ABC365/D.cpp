#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int n;
char s[N];
int arr[N];
int f[N][3];

bool loseto(int a,int b) {
    if (b==-1) return false;
    if (a==0 && b==1) return true;
    if (a==1 && b==2) return true;
    if (a==2 && b==0) return true;
    return false;
}

int max3(int a,int b,int c) {
    return max(max(a,b),c);
}

int main() {
    scanf("%d",&n);
    scanf("%s",s+1);
    for (int i=1;i<=n;++i) {
        if (s[i]=='R') arr[i]=0;
        else if (s[i]=='P') arr[i]=1;
        else arr[i]=2;
    }
    arr[0]=-1;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=2;++j) {
            if (loseto(j,arr[i])) continue;
            for (int k=0;k<=2;++k) {
                if (loseto(k,arr[i-1]) || j==k) continue;
                if (j==arr[i]) {
                    f[i][j]=max(f[i][j],f[i-1][k]);
                } else {
                    f[i][j]=max(f[i][j],f[i-1][k]+1);
                }
            }
        }
    }
    printf("%d",max3(f[n][0],f[n][1],f[n][2]));
    return 0;
}