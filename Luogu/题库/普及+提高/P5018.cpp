#include <bits/stdc++.h>
using namespace std;

int n;

int l[1000005];
int r[1000005];
int w[1000005];

int sizes[1000005];

int getsize(int root) {
    if (root==-1) return 0;
    else return sizes[root]=getsize(l[root])+getsize(r[root])+1;
}

bool is_duichen(int left,int right) {
    if (left==-1 && right==-1) return true;
    if (w[left]!=w[right]) return false;
    if (sizes[left]!=sizes[right]) return false;
    return is_duichen(l[left],r[right]) && is_duichen(l[right],r[left]);
}

int dfs(int root) {
    if (root==-1) return 0;
    int res=0;
    if (is_duichen(l[root],r[root])) res=sizes[root];
    else res=max(dfs(l[root]),dfs(r[root]));
    return res;
}

int main() {
    scanf("%d",&n);
    memset(l,-1,sizeof l);
    memset(r,-1,sizeof r);
    memset(w,-1,sizeof w);
    memset(sizes,0,sizeof sizes);
    for (int i=1;i<=n;++i) {
        scanf("%d",&w[i]);
    }
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&l[i],&r[i]);
    }
    getsize(1);
    printf("%d",dfs(1));
    return 0;
}

/*
7
1 4 2 2 3 4 2
3 5
-1 -1
6 2
-1 -1
4 7
-1 -1
-1 -1

7
3 4 4 5 2 2 5
2 3
4 5
6 7
-1 -1
-1 -1
-1 -1
-1 -1
*/