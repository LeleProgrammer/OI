#include <bits/stdc++.h>
using namespace std;

const int N=105;

int n,m;
int a[N];
bool vis[N];

void print() {
    for (int i=1;i<=m;++i) {
        printf("%d ",a[i]);
    }
    putchar(10);
}

void dfs(int pos,int last) {
    if (pos==m+1) {
        print();
        return;
    }
    for (int i=last+1;i<=n;++i) {
        if (!vis[i]) {
            vis[i]=true;
            a[pos]=i;
            dfs(pos+1,i);
            vis[i]=false;
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    dfs(1,0);
    return 0;
}