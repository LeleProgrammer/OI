#include <bits/stdc++.h>
using namespace std;

int n,m;
char arr[105][105];
bool mem[105][105];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
queue< pair<int,int> > q;

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=n && y<=m && mem[x][y]==false && arr[x][y]=='.') {
        return true;
    } else {
        return false;
    }
}

void bfs() {
    int gx,gy;
    while (!q.empty()) {
        gx=q.front().first;
        gy=q.front().second;
        q.pop();
        if (mem[gx][gy]) continue; // ²»¼Ó1AC£¬9TLE
        mem[gx][gy]=true;
        for (int i=0;i<=3;++i) {
            if (check(gx+dx[i],gy+dy[i])) {
                q.push(make_pair(gx+dx[i],gy+dy[i]));
            }
        }
    }
}

int main() {
    cin>>n>>m;
    char c;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            cin>>c;
            arr[i][j]=c;
        }
    }
    memset(mem,false,sizeof(mem));
    q.push(make_pair(1,1));
    bfs();
    if (mem[n][m]) cout<<"Yes";
    else cout<<"No";
    return 0;
}