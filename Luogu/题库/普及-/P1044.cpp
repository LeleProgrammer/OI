#include <bits/stdc++.h>
using namespace std;

int n;

int mem[18][18];

int dfs(int in,int mid) {
    if (in==0 && mid==0 && !mem[in][mid]) {
        mem[in][mid]=1;
    } else if (in && mid && !mem[in][mid]) {
        mem[in][mid]=dfs(in-1,mid+1)+dfs(in,mid-1);
    } else if (mid && !in && !mem[in][mid]) {
        mem[in][mid]=dfs(in,mid-1);
    } else if (in && !mid && !mem[in][mid]) {
        mem[in][mid]=dfs(in-1,mid+1);
    }
    return mem[in][mid];
}

int main() {
    int n;
    scanf("%d",&n);
    memset(mem,0,sizeof(mem));
    int ans=dfs(n,0);
    printf("%d",ans);
    return 0;
}