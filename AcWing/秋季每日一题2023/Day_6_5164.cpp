#include <bits/stdc++.h>
using namespace std;

const int C=200005;

int c;

bool arr[2][C];

int ans=0;

queue< pair<int,int> > q;

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

bool check(int x,int y) {
    if (x!=0 && x!=1) return false;
    if (y>=1 && y<=c && arr[x][y]) return true;
    else return false;
}

void bfs() {
    int gx,gy;
    while (!q.empty()) {
        gx=q.front().first;
        gy=q.front().second;
        q.pop();
        if (!arr[gx][gy]) continue;
        arr[gx][gy]=false;
        for (int i=0;i<4;++i) {
            if (gy%2==0 && (i==0 || i==2)) continue;
            if (check(gx+dx[i],gy+dy[i])) {
                ans-=2;
                q.push(make_pair(gx+dx[i],gy+dy[i]));
            }
        }
    }
}

int main() {
    scanf("%d",&c);
    int tmp;
    for (int i=0;i<=1;++i) {
        for (int j=1;j<=c;++j) {
            scanf("%d",&tmp);
            arr[i][j]=(tmp==1?true:false);
            if (tmp==1) ans+=3;
        }
    }
    for (int i=0;i<=1;++i) {
        for (int j=1;j<=c;++j) {
            if (arr[i][j]) {
                q.push(make_pair(i,j));
                bfs();
            }
        }
    }
    printf("%d",ans);
    return 0;
}