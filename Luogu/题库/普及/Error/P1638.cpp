#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
int arr[1000005];
int vis[2005];
int cnt=0;

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",arr+i);
    }
    memset(vis,0,sizeof(vis));
    a=1,b=0;
    while (cnt!=m) {
        b++;
        if (!vis[arr[b]]) cnt++;
        vis[arr[b]]++;
    }
    while (vis[arr[a]]>=2) a++,vis[arr[a]]--;
    printf("%d %d",a,b);
    return 0;
}