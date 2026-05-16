#include <bits/stdc++.h>
using namespace std;

int ln[4][4];
bool lnhv[4]; // 0:x 1:y

int main() {
    for (int i=0;i<4;++i) {
        scanf("%d %d %d %d",&ln[i][0],&ln[i][1],&ln[i][2],&ln[i][3]);
        if (ln[i][0]==ln[i][2]) lnhv[i]=1;
        else lnhv[i]=0;
    }
    int endx,endy,taskx,tasky;
    endx=ln[0][0],endy=ln[0][1];
    taskx=ln[0][2],tasky=ln[0][3];
    ln[0][0]=ln[0][1]=ln[0][2]=ln[0][3]=1000000005;
    bool nexttype=!lnhv[0];
    bool ok=false;
    for (int i=1;i<4;++i) {
        if (ln[i][0]==taskx && ln[i][1]==tasky && nexttype==lnhv[i]) {
            taskx=ln[i][2],tasky=ln[i][3],ok=true;
            ln[i][0]=ln[i][1]=ln[i][2]=ln[i][3]=1000000005;
            nexttype=!nexttype;
            break;
        } else if (ln[i][2]==taskx && ln[i][3]==tasky && nexttype==lnhv[i]) {
            taskx=ln[i][0],tasky=ln[i][1],ok=true;
            ln[i][0]=ln[i][1]=ln[i][2]=ln[i][3]=1000000005;
            nexttype=!nexttype;
            break;
        }
    }
    if (!ok) {printf("NO"); return 0;}
    ok=false;
    for (int i=1;i<4;++i) {
        if (ln[i][0]==taskx && ln[i][1]==tasky && nexttype==lnhv[i]) {
            taskx=ln[i][2],tasky=ln[i][3],ok=true;
            nexttype=!nexttype;
            break;
        } else if (ln[i][2]==taskx && ln[i][3]==tasky && nexttype==lnhv[i]) {
            taskx=ln[i][0],tasky=ln[i][1],ok=true;
            nexttype=!nexttype;
            break;
        }
    }
    if (!ok) {printf("NO"); return 0;}
    ok=false;
    for (int i=1;i<4;++i) {
        if (ln[i][0]==taskx && ln[i][1]==tasky && nexttype==lnhv[i]) {
            taskx=ln[i][2],tasky=ln[i][3],ok=true;
            nexttype=!nexttype;
            break;
        } else if (ln[i][2]==taskx && ln[i][3]==tasky && nexttype==lnhv[i]) {
            taskx=ln[i][0],tasky=ln[i][1],ok=true;
            nexttype=!nexttype;
            break;
        }
    }
    if (!ok) {printf("NO"); return 0;}
    if (taskx==endx && tasky==endy) printf("YES");
    else printf("NO");
    return 0;
}