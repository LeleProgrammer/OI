#include <bits/stdc++.h>
using namespace std;

const int N=505;
const int M=5205;

int T,n,m,k,u,v,p;;
int e[M],h[N],ne[M],w[M],tot;

void add(int a,int b,int c) {
    e[++tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot;
}

int dis[N];
int cnt[N];
bool flag[N];
queue<int> q;

bool spfa() {
    memset(cnt,0,sizeof(cnt));
    while (!q.empty()) q.pop();
    for (int i=1;i<=n;++i) {
        flag[i]=true;
        q.push(i);
    }
    while (!q.empty()) {
        int curr=q.front(); q.pop();
        flag[curr]=false;
        for (int i=h[curr];i;i=ne[i]) {
            if (dis[e[i]]>dis[curr]+w[i]) {
                dis[e[i]]=dis[curr]+w[i];
                cnt[e[i]]=cnt[curr]+1;
                if (cnt[e[i]]>=n) return true;
                if (!flag[e[i]]) {
                    flag[e[i]]=true;
                    q.push(e[i]);
                }
            }
        }
    }
    return false;
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d %d",&n,&m,&k);
        tot=0; memset(h,0,sizeof(h));
        while (m--) {
            scanf("%d %d %d",&u,&v,&p);
            add(u,v,p); add(v,u,p);
        }
        while (k--) {
            scanf("%d %d %d",&u,&v,&p);
            add(u,v,-p);
        }
        if (spfa()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}