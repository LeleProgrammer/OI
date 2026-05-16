#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int M=2000005;
const int K=35;

int n;
int tr[N][K],tot;
int ne[N];
char S[M];
char str[N];
int st[N];
int to[N];
queue<int> q;
int in[N];
int f[N];
int ans[N];

void insert(char str[],int idx) {
    int u=0;
    for (int i=0;str[i];++i) {
        int c=str[i]-'a';
        if (!tr[u][c]) tr[u][c]=++tot;
        u=tr[u][c];
    }
    if (!st[u]) st[u]=idx;
    to[idx]=st[u];
}

void build() {
    while (!q.empty()) q.pop();
    for (int i=0;i<=25;++i) {
        if (tr[0][i]) q.push(tr[0][i]);
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=0;i<=25;++i) {
            if (!tr[u][i]) tr[u][i]=tr[ne[u]][i];
            else {
                ne[tr[u][i]]=tr[ne[u]][i];
                in[tr[ne[u]][i]]++;
                q.push(tr[u][i]);
            }
        }
    }
}

void topu() {
    while (!q.empty()) q.pop();
    for (int i=1;i<=tot;++i) {
        if (!in[i]) q.push(i);
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        ans[st[u]]=f[u];
        f[ne[u]]+=f[u];
        in[ne[u]]--;
        if (!in[ne[u]]) q.push(ne[u]);
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%s",str);
        insert(str,i);
    }
    scanf("%s",S);
    build();
    for (int i=0,j=0;S[i];++i) {
        int c=S[i]-'a';
        j=tr[j][c];
        f[j]++;
    }
    topu();
    for (int i=1;i<=n;++i) {
        printf("%d\n",ans[to[i]]);
    }
    return 0;
}