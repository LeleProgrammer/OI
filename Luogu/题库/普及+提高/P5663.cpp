#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

typedef pair<int,int> pii;

int n,m,Q;
int e[M],ne[M],h[N],tot;
bool flag[N][2];
int dis[N][2];
queue<pii> q;
queue<int> q2;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void bfs() {
    q.push({1,0});
    flag[1][0]=true;
    while (!q.empty()) {
        auto tp=q.front(); q.pop();
        int u=tp.first;
        int k=tp.second;
        for (int i=h[u];~i;i=ne[i]) {
            if (!flag[e[i]][k^1]) {
                flag[e[i]][k^1]=true;
                q.push({e[i],k^1});
            }
        }
    }
}

void bfs2() {
    memset(dis,0x3f,sizeof(dis));
    dis[1][0]=0;
    q2.push(1);
    while (!q2.empty()) {
        int u=q2.front(); q2.pop();
        for (int i=h[u];~i;i=ne[i]) {
            int ne_dis0,ne_dis1;
            ne_dis0=dis[u][1]+1;
            ne_dis1=dis[u][0]+1;
            bool ok=false;
            if (ne_dis0<dis[e[i]][0]) {
                ok=true;
                dis[e[i]][0]=ne_dis0;
            } else if (ne_dis1<dis[e[i]][1]) {
                ok=true;
                dis[e[i]][1]=ne_dis1;
            }
            if (ok) {
                q2.push(e[i]);
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d",&n,&m,&Q);
    while (m--) {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    bfs();
    bfs2();
    while (Q--) {
        int a,L;
        scanf("%d %d",&a,&L);
        if (flag[a][L%2] && L>=dis[a][L%2]) puts("Yes");
        else puts("No");
    }
    return 0;
}