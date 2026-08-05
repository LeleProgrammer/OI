#include <cstdio>
#include <queue>
using namespace std;

int x1,y1,x2,y2,step_black,step_white;
int drt[12][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-2,-2},{-2,2},{2,-2},{2,2}};
int arr_black[25][25],arr_white[25][25];
queue<pair<int,int> > q_black,q_white;

bool check(int xx,int yy) {
    if (xx>=0 && yy>=0 && xx<20 && yy<20) {
        return true;
    } else {
        return false;
    }
}

void bfs(queue<pair<int,int> > &q,int arr[25][25],int &step) {
    int gx,gy,nx,ny,all,count;
    all=q.size();
    count=0;
    while (!q.empty()) {
        gx=q.front().first;
        gy=q.front().second;
        q.pop();
        if (step<arr[gx][gy]) {
            arr[gx][gy]=step;
            for (int i=0;i<12;++i) {
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
    scanf("%d %d",&x1,&y1);
    scanf("%d %d",&x2,&y2);
    for (int i=0;i<25;++i) {
        for (int j=0;j<25;++j) {
            arr_black[i][j]=0x7fffffff;
        }
    }
    for (int i=0;i<25;++i) {
        for (int j=0;j<25;++j) {
            arr_white[i][j]=0x7fffffff;
        }
    }
    step_black=0;
    step_white=0;
    q_black.push(make_pair(x1,y1));
    q_white.push(make_pair(x2,y2));
}

void output() {
    printf("%d\n%d",arr_black[1][1],arr_white[1][1]);
}

int main() {
    init();
    bfs(q_black,arr_black,step_black);
    bfs(q_white,arr_white,step_white);
    output();
    return 0;
}