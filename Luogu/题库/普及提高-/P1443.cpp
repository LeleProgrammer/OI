#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,step;
int arr[405][405];
int drt[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
queue<pair<int,int> > q;

bool check(int xx,int yy) {
    if (xx>=0 && yy>=0 && xx<n && yy<m) {
        return true;
    } else {
        return false;
    }
}

void bfs() {
    int gx,gy,nx,ny,all,count;
    all=q.size();
    count=0;
    while (!q.empty()) {
        gx=q.front().first;
        gy=q.front().second;
        q.pop();
        if (step<arr[gx][gy]) {
            arr[gx][gy]=step;
            for (int i=0;i<8;++i) {
                nx=drt[i][0]+gx;
                ny=drt[i][1]+gy;
                if (check(nx,ny)) {
                    q.push(make_pair(nx,ny));
                }
            }
        }
        ++count;
        if (count==all) {
            all=q.size();
            count=0;
            ++step;
        }
    }
}

void init() {
    scanf("%d %d %d %d",&n,&m,&x,&y);
    for (int i=0;i<405;++i) {
        for (int j=0;j<405;++j) {
            arr[i][j]=0x7fffffff;
        }
    }
    step=0;
    q.push(make_pair(x-1,y-1));
}

void output() {
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if (arr[i][j]==0x7fffffff) {
                arr[i][j]=-1;
            }
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    init();
    bfs();
    output();
    return 0;
}