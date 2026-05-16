#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string target;

char arr[105][105];

int r,c;

int ans=0;

int drt[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int turn_rule[8][2]={{2,5},{3,4},{0,7},{1,6},{1,6},{0,7},{3,4},{5,2}};

int nx,ny;

// angle:
// 0  1  2
// 3 now 4
// 5  6  7

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=r && y<=c) return true;
    else return false;
}

bool check(int x,int y,int i) {
    if (x>=1 && y>=1 && x<=r && y<=c && target[i]==arr[x][y]) return true;
    else return false;
}

void dfs(int x,int y,int finished,int angle,bool turned) {
    // test: cout<<x<<" "<<y<<" "<<finished<<" "<<angle<<" "<<turned<<" "<<target[finished-1]<<endl;
    if (finished==target.size()) {
        // test: cout<<angle<<" "<<turned<<endl;
        ans++;
        return;
    }
    if (finished==1) {
        for (int i=0;i<8;++i) {
            nx=x+drt[i][0]; ny=y+drt[i][1];
            if (check(nx,ny,finished)) dfs(nx,ny,finished+1,i,false);
        }
    } else {
        if (check(x+drt[angle][0],y+drt[angle][1],finished)) {
            dfs(x+drt[angle][0],y+drt[angle][1],finished+1,angle,turned);
        }
        if (!turned) {
            for (int j=0;j<2;++j) {
                if (check(x+drt[turn_rule[angle][j]][0],y+drt[turn_rule[angle][j]][1],finished)) {
                    dfs(x+drt[turn_rule[angle][j]][0],y+drt[turn_rule[angle][j]][1],finished+1,turn_rule[angle][j],true);
                }
            }
        }
    }
}

int main() {
    IOS
    cin>>target;
    cin>>r>>c;
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=c;++j) {
            cin>>arr[i][j];
        }
    }
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=c;++j) {
            if (arr[i][j]==target[0]) {
                dfs(i,j,1,-1,false);
            }
        }
    }
    cout<<ans;
    return 0;
}