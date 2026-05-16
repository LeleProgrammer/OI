#include <bits/stdc++.h>
using namespace std;

int n,m,mx,my,dx,dy,st;
char arr[2005][2005];
int step[2005][2005];
int drt[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
queue<pair<int,int> > q;

void init() {
    scanf("%d %d\n",&n,&m);
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            while (true) {
                scanf("%c",&(arr[i][j]));
                if (!isspace(arr[i][j])) {
                    break;
                }
            }
            if (arr[i][j]=='d') {
                dx=i;
                dy=j;
            } else if (arr[i][j]=='m') {
                mx=i;
                my=j;
            }
        }
    }
    for (int i=0;i<2005;++i) {
        for (int j=0;j<2005;++j) {
            step[i][j]=0x7fffffff;
        }
    }
    st=0;
    q.push(make_pair(mx,my));
}

bool check(int x,int y) {
    if (x>=0 && y>=0 && x<n && y<m) {
        if (arr[x][y]=='.' || arr[x][y]=='d') {
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
    if (step[dx][dy]==0x7fffffff) {
        printf("No Way!");
    } else {
        printf("%d",step[dx][dy]);
    }
}

int main() {
    init();
    bfs();
    output();
    return 0;
}