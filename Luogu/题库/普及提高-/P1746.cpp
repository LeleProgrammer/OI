#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int n,x1,y1,x2,y2,st;
int arr[1005][1005];
int step[1005][1005];
int drt[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
queue<pair<int,int> > q;

void init() {
    scanf("%d",&n);
    for (int i=0;i<1005;++i) {
        for (int j=0;j<1005;++j) {
            step[i][j]=0x7fffffff;
        }
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            scanf("%1d",&(arr[i][j]));
        }
    }
    scanf("%d %d",&x1,&y1);
    scanf("%d %d",&x2,&y2);
    --x1;
    --y1;
    --x2;
    --y2;
    st=0;
    q.push(make_pair(x1,y1));
}

bool check(int x,int y) {
    if (x>=0 && y>=0 && x<n && y<n) {
        if (arr[x][y]==0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void bfs() {
    int gx,gy,all,count;
    all=1;
    count=0;
    while (!q.empty()) {
        gx=q.front().first;
        gy=q.front().second;
        q.pop();
        if (st<step[gx][gy]) {
            step[gx][gy]=st;
            for (int i=0;i<4;++i) {
                if (check(gx+drt[i][0],gy+drt[i][1])) {
                    q.push(make_pair(gx+drt[i][0],gy+drt[i][1]));
                }
            }
        }
        ++count;
        if (count==all) {
            count=0;
            all=q.size();
            ++st;
        }
    }
}

void output() {
    printf("%d",step[x2][y2]);
}

int main() {
    init();
    bfs();
    output();
    return 0;
}