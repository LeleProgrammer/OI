#include <bits/stdc++.h>
using namespace std;

const int N=1005;

int t;
map<int,int> arr;
int tt;
queue<int> q[N];
queue<int> Q;

int main() {
    while (true) {
        scanf("%d",&t);
        if (!t) break;
        ++tt;
        printf("Scenario #%d\n",tt);
        arr.clear();
        for (int i=1;i<=t;++i) {
            while (!q[i].empty()) {
                q[i].pop();
            }
        }
        while (!Q.empty()) {
            Q.pop();
        }
        for (int i=1;i<=t;++i) {
            int k;
            scanf("%d",&k);
            for (int j=1;j<=k;++j) {
                int v;
                scanf("%d",&v);
                arr[v]=i;
            }
        }
        while (true) {
            char op[15];
            scanf("%s",op);
            if (*op=='S') break;
            else if (*op=='E') {
                int v;
                scanf("%d",&v);
                int g=arr[v];
                q[g].push(v);
                if (q[g].size()==1) {
                    Q.push(g);
                }
            } else {
                int g=Q.front();
                printf("%d\n",q[g].front());
                q[g].pop();
                if (q[g].size()==0) Q.pop();
            }
        }
        putchar(10);
    }
    return 0;
}