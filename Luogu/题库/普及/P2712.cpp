#include <bits/stdc++.h>
using namespace std;

const int N=505;
const int M=50005;

int n;
int arr[N],a[N];
int e[M],ne[M],h[N],tot;
int in[N];
queue<int> q;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void topu() {
    for (int i=1;i<=n;++i) {
        if (!in[arr[i]]) q.push(arr[i]);
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        n-=a[u];
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
        int pos;
        scanf("%d",&pos);
        arr[i]=pos;
        a[pos]++;
        int k;
        scanf("%d",&k);
        for (int j=1;j<=k;++j) {
            int v;
            scanf("%d",&v);
            add(pos,v);
            in[v]++;
        }
    }
    topu();
    if (!n) puts("YES");
    else printf("%d",n);
    return 0;
}