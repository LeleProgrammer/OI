#include <bits/stdc++.h>
using namespace std;

const int N=2005;
const int M=6005;

int T,n,m,u,v,ww;
int e[M],h[N],w[M],ne[M],tot;
int dis[N],cnt[N];
bool flag[N];
queue<int> q;

void add(int a,int b,int c) {
    e[++tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot;
}

bool spfa() {
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    memset(flag,0,sizeof(flag));
    while (!q.empty()) q.pop();
    flag[1]=true;
    dis[1]=0;
    q.push(1);
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
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&m);
        memset(h,0,sizeof(h));
        tot=0;
        while (m--) {
            scanf("%d %d %d",&u,&v,&ww);
            if (ww>=0) add(u,v,ww),add(v,u,ww);
            else add(u,v,ww);
        }
        if (spfa()) puts("YES");
        else puts("NO");
    }
    return 0;
}