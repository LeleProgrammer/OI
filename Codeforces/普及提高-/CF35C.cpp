#include <bits/stdc++.h>
using namespace std;

int n,m,k,x,y;
bool vis[2005][2005];
queue<int> xq,yq;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=n && y<=m) {
        return true;
    } else {
        return false;
    }
}

void bfs() {
    while (!xq.empty()) {
        x=xq.front();
        y=yq.front();
        xq.pop();
        yq.pop();
        for (int i=0;i<4;++i) {
            if (check(x+dx[i],y+dy[i]) && !vis[x+dx[i]][y+dy[i]]) {
                xq.push(x+dx[i]);
                yq.push(y+dy[i]);
                vis[x+dx[i]][y+dy[i]]=true;
            }
        }
    }
}

int main() {
    // 这题CF上要加freopen
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    scanf("%d %d",&n,&m);
    scanf("%d",&k);
    for (int i=1;i<=k;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        vis[a][b]=true;
        xq.push(a);
        yq.push(b);
    }
    bfs();
    printf("%d %d",x,y);
    return 0;
}