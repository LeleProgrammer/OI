#include <bits/stdc++.h>
using namespace std;

int t,n,x,y,s;
int arr[1005][1005];
bool vis[1005][1005];
queue<int> xq,yq,sq;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=n && y<=n) {
        return true;
    } else {
        return false;
    }
}

void bfs() {
    while (!xq.empty()) {
        x=xq.front();
        xq.pop();
        y=yq.front();
        yq.pop();
        s=sq.front();
        sq.pop();
        if (vis[x][y]) continue;
        vis[x][y]=true;
        for (int i=0;i<4;++i) {
            if (check(x+dx[i],y+dy[i]) && arr[x+dx[i]][y+dy[i]]>=s+1) {
                xq.push(x+dx[i]);
                yq.push(y+dy[i]);
                sq.push(s+1);
            }
        }
    }
}

int main() {
    scanf("%d",&t);
    while (t--) {
        memset(arr,0x7f,sizeof(arr));
        memset(vis,false,sizeof(vis));
        scanf("%d",&n);
        for (int i=1;i<=2*n-2;++i) {
            int a,b;
            scanf("%d %d",&a,&b);
            arr[a][b]=i;
        }
        xq.push(1);
        yq.push(1);
        sq.push(0);
        bfs();
        if (vis[n][n]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}