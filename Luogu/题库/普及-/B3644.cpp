#include <bits/stdc++.h>
using namespace std;

const int N=105;
const int M=10005;

int n;
int e[M],ne[M],h[N],tot;
int in[N];
vector<int> v;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void topo() {
    queue<int> q;
    for (int i=1;i<=n;++i) {
        if (!in[i]) q.push(i);
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        v.push_back(u);
        for (int i=h[u];~i;i=ne[i]) {
            in[e[i]]--;
            if (!in[e[i]]) q.push(e[i]);
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        while (true) {
            int k;
            scanf("%d",&k);
            if (!k) break;
            add(i,k);
            in[k]++;
        }
    }
    topo();
    for (int i=0;i<v.size();++i) {
        printf("%d ",v[i]);
    }
    return 0;
}