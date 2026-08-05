#include <bits/stdc++.h>
using namespace std;

int n,a,b,k[200];
int minimum=2147483647;
int k_min[200];
bool cannot=false;

void dfs(int now,int times) {
    if (cannot) return;
    if (times>=1000000) {
        cannot=true;
        return;
    }
    if (now==b) {
        if (times<minimum) {
            minimum=times;
        }
        return;
    }
    if (k_min[now-1]>times) {
        k_min[now-1]=times;
    }
    if (times<minimum) {
        if (now+k[now-1]<=n) {
            if (k_min[now+k[now-1]-1]<times+1) {
                dfs(now+k[now-1],times+1);
            }
        }
        if (now-k[now-1]>=1) {
            if (k_min[now-k[now-1]-1]<times+1) {
                dfs(now-k[now-1],times+1);
            }
        }
    }
}

void init() {
    memset(k_min,2147483647,sizeof(k_min));
    scanf("%d %d %d",&n,&a,&b);
    for (int i=0;i<n;++i) {
        scanf("%d",&(k[i]));
    }
}

int main() {
    init();
    dfs(a,0);
    if (cannot) printf("-1");
    else printf("%d",minimum);
    return 0;
}