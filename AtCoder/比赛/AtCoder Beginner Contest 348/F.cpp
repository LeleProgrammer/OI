#include <bits/stdc++.h>
using namespace std;

const int N=2005;
const int M=1005;

int n,m;
int a[N][N];
vector<int> b[N][M];

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf("%d",&a[i][j]);
            b[j][a[i][j]].push_back(i);
        }
    }
    return 0;
}