#include <bits/stdc++.h>
using namespace std;

const int N=1005;

int n,m,k;
unordered_set<int> vec[N];

int main() {
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            int t;
            scanf("%d",&t);
            vec[t].insert(j);
        }
    }
    for (int i=1;i<=k;++i) {
        printf("%d ",vec[i].size());
    }
    return 0;
}