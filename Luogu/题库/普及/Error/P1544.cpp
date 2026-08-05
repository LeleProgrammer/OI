#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[6][6];
int rem[6][6][2];
int maximum=0;

bool check(int r,int c) {
    if (r<0 || c<0) {
        return false;
    }
    if (c>r) {
        return false;
    }
    return true;
}

void dfs(int exp,int ch_k,int r,int c) {
    exp+=arr[r][c];
    if (exp>rem[r][c][0] || (exp>=rem[r][c][0] && ch_k<rem[r][c][1])) {
        rem[r][c][0]=exp;
        rem[r][c][1]=ch_k;
        if (r==n-1) {
            if (exp>maximum) {
                maximum=exp;
            }
        } else {
            if (check(r+1,c)) {
                dfs(exp,ch_k,r+1,c);
            }
            if (check(r+1,c+1)) {
                dfs(exp,ch_k,r+1,c+1);
            }
        }
    }    
    exp-=arr[r][c];
    exp+=arr[r][c]*3;
    ++ch_k;
    if (ch_k>k) {
        return;
    }
    if (exp>rem[r][c][0] || (exp>=rem[r][c][0] && ch_k<rem[r][c][1])) {
        rem[r][c][0]=exp;
        rem[r][c][1]=ch_k;
        if (r==n-1) {
            if (exp>maximum) {
                maximum=exp;
            }
        } else {
            if (check(r+1,c)) {
                dfs(exp,ch_k,r+1,c);
            }
            if (check(r+1,c+1)) {
                dfs(exp,ch_k,r+1,c+1);
            }
        }
    }
}

int main() {
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;++i) {
        for (int j=0;j<=i;++j) {
            scanf("%d",&(arr[i][j]));
        }
    }
    for (int i=0;i<6;++i) {
        for (int j=0;j<6;++j) {
            rem[i][j][0]=0;
            rem[i][j][1]=0x7fffffff;
        }
    }
    dfs(0,0,0,0);
    printf("%d",maximum);
    return 0;
}