#include <bits/stdc++.h>
using namespace std;

int n,m,ans=0;
int arr[100][100];

void dfs(int r,int c) {
    arr[r][c]=-1;
    if (r-1>=0) {
        if (arr[r-1][c]>=1) {
            dfs(r-1,c);
        }
    }
    if (r+1<n) {
        if (arr[r+1][c]>=1) {
            dfs(r+1,c);
        }
    }
    if (c-1>=0) {
        if (arr[r][c-1]>=1) {
            dfs(r,c-1);
        }
    }
    if (c+1<m) {
        if (arr[r][c+1]>=1) {
            dfs(r,c+1);
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            scanf("%1d",&(arr[i][j]));
        }
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if (arr[i][j]>=1) {
                ++ans;
                dfs(i,j);
            }
        }
    }
    printf("%d",ans);
    return 0;
}