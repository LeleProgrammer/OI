#pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;

int n,m;
int drt[4][2]={{-2,1},{-1,2},{1,2},{2,1}};
int arr[20][20];
queue<pair<int,int> > q;

bool check(int x,int y) {
    if (x>=0 && y>=0 && x<=n && y<=m) {
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
        for (int i=0;i<4;++i) {
            if (check(gx+drt[i][0],gy+drt[i][1])) {
                q.push(make_pair(gx+drt[i][0],gy+drt[i][1]));
                ++arr[gx+drt[i][0]][gy+drt[i][1]];
            }
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    q.push(make_pair(0,0));
    memset(arr,0,sizeof(0));
    arr[0][0]=1;
    bfs();
    printf("%d",arr[n][m]);
    return 0;
}