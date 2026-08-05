#include <bits/stdc++.h>
using namespace std;

int r,c;
char arr[150][150];
bool vis[150][150];
vector< pair<int,int> > path;
bool ok=false;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=r && y<=c && arr[x][y]=='.') {
        return true;
    } else {
        return false;
    }
}

void print() {
    for (int i=0;i<path.size();++i) {
        printf("%d %d\n",path[i].first,path[i].second);
    }
}

void dfs(int x,int y) {
    if (ok) return;
    if (x==r && y==c) {
        print();
        ok=true;
        return;
    }
    for (int i=0;i<4;++i) {
        if (check(x+dx[i],y+dy[i]) && !vis[x+dx[i]][y+dy[i]]) {
            path.push_back(make_pair(x+dx[i],y+dy[i]));
            vis[x+dx[i]][y+dy[i]]=true;
            dfs(x+dx[i],y+dy[i]);
            if (ok) return;
            path.pop_back();
        }
    }
}

int main() {
    scanf("%d %d",&r,&c);
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=c;++j) {
            scanf(" %c",&arr[i][j]);
        }
    }
    memset(vis,false,sizeof(vis));
    vis[1][1]=true;
    path.push_back(make_pair(1,1));
    dfs(1,1);
    return 0;
}