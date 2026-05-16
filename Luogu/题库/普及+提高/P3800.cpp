#include <bits/stdc++.h>
using namespace std;

const int N=4005;
const int M=8005;

int n,m,k,t;
int arr[N][N];
int g[M],f[M];
deque<int> q;

int main() {
    scanf("%d %d %d %d",&n,&m,&k,&t);
    while (k--) {
        int x,y,v;
        scanf("%d %d %d",&x,&y,&v);
        arr[x][y]=v;
    }
    for (int i=1;i<=n;++i) {
        q.clear();
        for (int j=1;j<=m+t;++j) {
            while (!q.empty() && q.front()<=j-(2*t+1)) q.pop_front();
            while (!q.empty() && f[q.back()]<=f[j]) q.pop_back();
            q.push_back(j);
            g[j]=f[q.front()];
        }
        for (int j=1;j<=m;++j) f[j]=g[j+t]+arr[i][j];
        // for (int j=1;j<=m;++j) printf("%d ",g[j]); putchar(10);
    }
    int ans=0;
    for (int i=1;i<=m;++i) ans=max(ans,f[i]);
    printf("%d",ans);
    return 0;
}