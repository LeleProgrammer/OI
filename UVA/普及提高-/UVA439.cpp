#include <bits/stdc++.h>

#define IOS_ON ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define IOS_OFF ios::sync_with_stdio(true);

using namespace std;

int sx,sy,ex,ey,n=8,m=8;
string a,b;
queue<int> x,y,step;

int res[9][9];

int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=n && y<=m) {
        return true;
    } else {
        return false;
    }
}

void bfs() {
    int gx,gy,gs;
    while (!x.empty()) {
        gx=x.front();
        gy=y.front();
        gs=step.front();
        x.pop();
        y.pop();
        step.pop();
        if (gs>=res[gx][gy]) continue;
        res[gx][gy]=gs;
        for (int i=0;i<=7;++i) {
            if (check(gx+dx[i],gy+dy[i])) {
                x.push(gx+dx[i]);
                y.push(gy+dy[i]);
                step.push(gs+1);
            }
        }
    }
}

bool input() {
    if (!(cin>>a>>b)) return false;
    sx=a[0]-'a'+1;
    sy=a[1]-'0';
    ex=b[0]-'a'+1;
    ey=b[1]-'0';
    while (!x.empty()) x.pop(),y.pop(),step.pop();
    x.push(sx);
    y.push(sy);
    step.push(0);
    memset(res,0x3f,sizeof(res));
    return true;
}

void output() {
    cout<<"To get from ";
    cout<<a;
    cout<<" to ";
    cout<<b;
    cout<<" takes ";
    cout<<res[ex][ey];
    cout<<" knight moves.";
    cout<<endl;
}

int main() {
    IOS_ON
    while (input()) {
        bfs();
        output();
    }
    IOS_OFF
    return 0;
}