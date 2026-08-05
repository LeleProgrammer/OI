#include <bits/stdc++.h>
using namespace std;

int tree[1000005][2];
int maxx=0;

void dfs(int item,int level) {
    maxx=max(maxx,level);
    if (tree[item][0]!=0) {
        dfs(tree[item][0],level+1);
    }
    if (tree[item][1]!=0) {
        dfs(tree[item][1],level+1);
    }
    return ;
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&tree[i][0]);
        scanf("%d",&tree[i][1]);
    }
    dfs(1,1);
    printf("%d",maxx);
    return 0;
}

/*
7
2 7
3 6
4 5
0 0
0 0
0 0
0 0

                    1
                2       7
            3       6
          4   5
*/