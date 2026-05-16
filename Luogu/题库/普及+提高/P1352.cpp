#include <bits/stdc++.h>
using namespace std;

int n;
int r[6005];
vector<int> emps[6005];
int f[6005][2]; // 0:ignore 1:go
bool king[6005];
int getking;

void dfs(int i) { // f[i][...]
    f[i][1]=r[i];
    for (int j:emps[i]) {
        dfs(j);
        f[i][0]=f[i][0]+max(f[j][0],f[j][1]);
        f[i][1]+=f[j][0];
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&r[i]);
    }
    int k,l;
    memset(king,true,sizeof(king));
    for (int i=1;i<=n-1;++i) {
        scanf("%d %d",&l,&k);
        emps[k].push_back(l);
        king[l]=false;
    }
    for (getking=1;!king[getking];++getking);
    memset(f,0,sizeof(f));
    dfs(getking);
    printf("%d",max(f[getking][0],f[getking][1]));
    return 0;
}