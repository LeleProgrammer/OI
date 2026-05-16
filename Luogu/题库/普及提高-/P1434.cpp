#include <bits/stdc++.h>
using namespace std;

int R,C,arr[100][100];
int mem_len[100][100];
int maximum=1;

void dfs(int len,int r,int c) {
    if (len>=mem_len[r][c]) {
        mem_len[r][c]=len;
    } else {
        return;
    }
    if (r-1>=0) { // up
        if (arr[r-1][c]<arr[r][c]) {
            if (mem_len[r-1][c]<len+1) {
                dfs(len+1,r-1,c);
            }
        }
    }
    if (r+1<R) { // down
        if (arr[r+1][c]<arr[r][c]) {
            if (mem_len[r+1][c]<len+1) {
                dfs(len+1,r+1,c);
            }
        }
    }
    if (c-1>=0) { // left
        if (arr[r][c-1]<arr[r][c]) {
            if (mem_len[r][c-1]<len+1) {
                dfs(len+1,r,c-1);
            }
        }
    }
    if (c+1<C) { // right
        if (arr[r][c+1]<arr[r][c]) {
            if (mem_len[r][c+1]<len+1) {
                dfs(len+1,r,c+1);
            }
        }
    }
    if (len>maximum) {
        maximum=len;
    }
}

void init() {
    scanf("%d %d",&R,&C);
    for (int i=0;i<R;++i) {
        for (int j=0;j<C;++j) {
            scanf("%d",&(arr[i][j]));
        }
    }
    memset(mem_len,0,sizeof(mem_len));
}

void output() {
    printf("%d",maximum);
}

int main() {
    init();
    for (int i=0;i<R;++i) {
        for (int j=0;j<C;++j) {
            dfs(1,i,j);
        }
    }
    output();
}