#include <bits/stdc++.h>
using namespace std;

const int N=1005;
const int M=10005;

int n,m,u,v,ww;
int e[M],h[N],ne[M],w[M],tot;
queue<int> q;

void add(int a,int b,int c) {
    e[++tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot;
}

int dis[N];
bool flag[N];
int cnt[N];

bool spfa(int root) {
    memset(dis,0x3f,sizeof(dis));
    memset(flag,0,sizeof(flag));
    memset(cnt,0,sizeof(cnt));
    while (!q.empty()) q.pop();
    flag[root]=true;
    q.push(root);
    dis[root]=0;
    while (!q.empty()) {
        int curr=q.front(); q.pop();
        flag[curr]=false;
        for (int i=h[curr];i;i=ne[i]) {
            if (dis[e[i]]>dis[curr]+w[i]) {
                dis[e[i]]=dis[curr]+w[i];
                cnt[e[i]]=cnt[curr]+1;
                if (cnt[e[i]]>=n) return true;
                if (!flag[e[i]]) {
                    q.push(e[i]);
                    flag[e[i]]=true;
                }
            }
        }
    }
    return false;
}

int main() {
    scanf("%d %d",&n,&m);
    while (m--) {
        scanf("%d %d %d",&u,&v,&ww);
        add(u,v,-ww);
    }
    if (spfa(1)) printf("Forever love");
    else {
        int ans=dis[n];
        if (spfa(n)) printf("Forever love");
        else printf("%d",min(ans,dis[1]));
    }
    return 0;
}