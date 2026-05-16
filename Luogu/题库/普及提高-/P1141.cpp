#include <bits/stdc++.h>
using namespace std;

int n,m,blocks;
int drt[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int result[100005];
bool arr[1005][1005];
bool arrived[1005][1005];
queue<pair<int,int> > q;

void init() {
    scanf("%d %d",&n,&m);
    memset(arr,false,sizeof(arr));
    memset(arrived,false,sizeof(arrived));
    memset(result,0,sizeof(result));
    int input;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            scanf("%1d",&input);
            if (input==1) {
                arr[i][j]=true;
            } else {
                arr[i][j]=false;
            }
        }
    }
}

bool check(int x,int y) {
    if (x>=0 && y>=0 && x<n && y<n) {
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
        ++blocks;
        for (int i=0;i<4;++i) {
            if (check(gx+drt[i][0],gy+drt[i][1])) {
                if (arr[gx][gy]!=arr[gx+drt[i][0]][gy+drt[i][1]]) {
                    if (!arrived[gx+drt[i][0]][gy+drt[i][1]]) {
                        q.push(make_pair(gx+drt[i][0],gy+drt[i][1]));
                        arrived[gx+drt[i][0]][gy+drt[i][1]]=true;
                    }
                }
            }
        }
    }
}

void get() {
    int x,y;
    for (int i=0;i<m;++i) {
        scanf("%d %d",&x,&y);
        --x;
        --y;
        blocks=0;
        q.push(make_pair(x,y));
        memset(arrived,false,sizeof(arrived));
        arrived[x][y]=true;
        bfs();
        result[i]=blocks;
    }
}

void output() {
    for (int i=0;i<m;++i) {
        printf("%d\n",result[i]);
    }
}

int main() {
    init();
    get();
    output();
    return 0;
}