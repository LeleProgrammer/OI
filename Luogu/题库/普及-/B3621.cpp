#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[6];

void dfs(int pos) {
    if (pos>n) {
        for (int i=1;i<=n;++i) {
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i=1;i<=k;++i) {
        arr[pos]=i;
        dfs(pos+1);
    }
}

int main() {
    scanf("%d %d",&n,&k);
    dfs(1);
    return 0;
}