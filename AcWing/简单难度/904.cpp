#include <bits/stdc++.h>
using namespace std;

const int N=505;
const int M=5205;

int T,n,m,g,u,v,k;
int e[M],h[N],w[M],ne[M];
int tot;
int dis[N];
int q[M];
bool flag[N];
int cnt[N];

void add(int a,int b,int c) {
    tot++;
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot;
}

bool spfa() {
    memset(dis,0,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    memset(flag,0,sizeof(flag));
    int hh=0,tt=0;
    for (int i=1;i<=n;++i) {
        q[tt++]=i;
        flag[i]=true;
    }
    while (hh!=tt) {
        int curr=q[hh++];
        if (hh==M) hh=0;
        flag[curr]=false;
        for (int i=h[curr];i;i=ne[i]) {
            if (dis[e[i]]>dis[curr]+w[i]) {
                dis[e[i]]=dis[curr]+w[i];
                cnt[e[i]]=cnt[curr]+1;
                if (cnt[e[i]]>=n) return true;
                if (!flag[e[i]]) {
                    q[tt++]=e[i];
                    if (tt==M) tt=0;
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
        scanf("%d %d %d",&n,&m,&g);
        tot=0; memset(h,0,sizeof(h));
        while (m--) {
            scanf("%d %d %d",&u,&v,&k);
            add(u,v,k),add(v,u,k);
        }
        while (g--) {
            scanf("%d %d %d",&u,&v,&k);
            add(u,v,-k);
        }
        if (spfa()) {
            printf("YES");
        } else {
            printf("NO");
        }
        putchar(10);
    }
    return 0;
}