#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=100005,M=100005,SS=255;

int n,m,k,S,T;
int e[M],ne[M],f[M],h[N],tot;
int p[SS];
int layer[N],cur[N];

struct SpaceShip {
    int h;
    int r;
    int arr[SS];
} sp[SS];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

int loc(int item,int day) { // 第 item 个太空站，第 day 天
    return day*(n+2)+item; // n 个太空站 + 地球 + 月球 = (n+2) 个点
}

int find(int x) {
    if (p[x]!=x) return p[x]=find(p[x]);
    return p[x];
}

bool bfs() {
    memset(layer,-1,sizeof(layer));
    queue<int> q;
    q.push(S); layer[S]=0; cur[S]=h[S];
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (layer[e[i]]==-1 && f[i]) {
                layer[e[i]]=layer[u]+1;
                cur[e[i]]=h[e[i]];
                if (e[i]==T) return true;
                q.push(e[i]);
            }
        }
    }
    return false;
}

int dfs(int u,int limit) {
    if (u==T) return limit;
    int k=0;
    for (int i=cur[u];~i && k<limit;i=ne[i]) {
        cur[u]=i;
        if (layer[e[i]]==layer[u]+1 && f[i]) {
            int ret=dfs(e[i],min(f[i],limit-k));
            if (!ret) layer[e[i]]=-1;
            k+=ret,f[i]-=ret,f[i^1]+=ret;
        }
    }
    return k;
}

int dinic() {
    int ans=0,k;
    while (bfs()) {
        while (k=dfs(S,inf)) {
            ans+=k;
        }
    }
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d",&n,&m,&k); S=N-1,T=N-2;
    for (int i=0;i<SS;++i) p[i]=i;
    for (int i=0;i<m;++i) {
        scanf("%d %d",&sp[i].h,&sp[i]r);
        for (int j=0;j<sp[i].r;++j) { // 这里从 0 开始，方便后面计算
            scanf("%d",&sp[i].arr[j]);
            if (sp[i].arr[j]==-1) sp[i].arr[j]=n+1; // 月球
            if (!j) continue;
            p[find(sp[i].arr[j-1])]=find(sp[i].arr[j]); // 合并
        }
    }
    if (find(0)!=find(n+1)) puts("0");
    else {
        int success=0;
        add(S,loc(0,0),k); // 第 0 天的第 0 个太空站（地球）
        add(loc(n+1,0),T,inf); // 第 0 天的第 (n+1) 个太空站（月球）
        int day;
        for (day=1;;++day) {
            add(loc(n+1,day),T,inf); // 第 day 天的月球
            for (int i=0;i<=n+1;++i) { // 可在同一个太空站里等待
                add(loc(i,day-1),loc(i,day),inf); // 容量无限
            }
            for (int i=0;i<m;++i) { // 线路连接
                add(loc(sp[i].arr[(day-1)%sp[i].r],day-1),loc(sp[i].arr[day%sp[i].r],day),sp[i].h);
            }
            success+=dinic();
            if (success>=k) break;
        }
        printf("%d",day);
    }
    return 0;
}