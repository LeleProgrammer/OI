#include <bits/stdc++.h>
using namespace std;

int n;
int mem[1000005];
queue< pair<int,int> > q;

bool check(int x) {
    if (x>=1 && x<=n) return true;
    else return false;
}

void bfs() {
    int gx,gstep;
    while (!q.empty()) {
        gx=q.front().first;
        gstep=q.front().second;
        q.pop();
        if (gstep>=mem[gx]) continue;
        mem[gx]=gstep;
        if (check(gx+1)) q.push(make_pair(gx+1,gstep+1));
        if (check(gx-1)) q.push(make_pair(gx-1,gstep+1));
        if (check(gx*2)) q.push(make_pair(gx*2,gstep+1));
    }
}

int main() {
    scanf("%d",&n);
    memset(mem,0x3f,sizeof(mem));
    q.push(make_pair(1,0));
    bfs();
    printf("%d",mem[n]);
    return 0;
}