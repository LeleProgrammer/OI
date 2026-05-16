#include <bits/stdc++.h>
using namespace std;

const int N=105;
const int M=10005;

int n,m;
int e[M],ne[M],h[N],tot;
int in[N];
vector<int> arr;
queue<int> q;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void topu() {
    while (!q.empty()) q.pop();
    for (int i=1;i<=n;++i) {
        if (!in[i]) q.push(i);
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        arr.push_back(u);
        for (int i=h[u];~i;i=ne[i]) {
            in[e[i]]--;
            if (!in[e[i]]) q.push(e[i]);
        }
    }
}

int main() {
    while (true) {
        memset(h,-1,sizeof(h)); tot=0;
        memset(in,0,sizeof(in));
        arr.clear();
        scanf("%d %d",&n,&m);
        if (!n && !m) break;
        while (m--) {
            int a,b;
            scanf("%d %d",&a,&b);
            add(a,b);
            in[b]++;
        }
        topu();
        for (int i=0;i<arr.size();++i) printf("%d ",arr[i]);
        putchar(10);
    }
    return 0;
}