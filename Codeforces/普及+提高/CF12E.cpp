#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> permutation;
int arr[1005][1005];

int main() {
    scanf("%d",&n);
    permutation.push_back(-0x3f);
    for (int i=1;i<=n-1;++i) {
        permutation.push_back(i);
    }
    for (int i=1;i<=n-1;++i) {
        for (int j=1;j<=n-1;++j) {
            arr[i][j]=permutation[j];
        }
        arr[i][n]=0;
        permutation.push_back(permutation[1]);
        permutation.erase(permutation.begin()+1);
    }
    for (int j=1;j<=n;++j) {
        arr[n][j]=0;
    }
    for (int i=1;i<=n-1;++i) {
        swap(arr[i][i],arr[i][n]);
    }
    for (int i=1,j=1;i<=n-1;i+=2,++j) {
        arr[n][j]=i;
    }
    for (int i=2,j=n/2+1;i<=n-1;i+=2,++j) {
        arr[n][j]=i;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}