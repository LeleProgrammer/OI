#include <bits/stdc++.h>
using namespace std;

const int N=5005,M=10005;

int n,m;
int a,b,c;
int e[M],w[M],ne[M],h[N],tot;

void add(int a,int b,int c) {
    e[++tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot;
}

int dis[N];
int cnt[N];
bool flag[N];
queue<int> q;

bool spfa() {
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    memset(flag,0,sizeof(flag));
    dis[0]=0;
    flag[0]=true;
    q.push(0);
    while (!q.empty()) {
        int curr=q.front(); q.pop();
        flag[curr]=false;
        for (int i=h[curr];i;i=ne[i]) {
            if (dis[e[i]]>dis[curr]+w[i]) {
                dis[e[i]]=dis[curr]+w[i];
                cnt[e[i]]=cnt[curr]+1;
                if (cnt[e[i]]>=n+1) return true;
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
    scanf("%d %d",&n,&m);
    while (m--) {
        scanf("%d %d %d",&a,&b,&c);
        add(b,a,c);
    }
    for (int i=1;i<=n;++i) {
        add(0,i,0);
    }
    if (spfa()) printf("NO");
    else {
        for (int i=1;i<=n;++i) {
            printf("%d ",dis[i]);
        }
    }
    return 0;
}