#include <bits/stdc++.h>
using namespace std;

const int N=5005,M=15005;

int n,m,a,b,c,op;
int e[M],ne[M],w[M],h[N],tot;

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
    flag[0]=true;
    dis[0]=true;
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
        scanf("%d",&op);
        if (op==1) {
            scanf("%d %d %d",&a,&b,&c);
            add(a,b,-c);
        } else if (op==2) {
            scanf("%d %d %d",&a,&b,&c);
            add(b,a,c);
        } else {
            scanf("%d %d",&a,&b);
            add(b,a,0); add(a,b,0);
        }
    }
    for (int i=1;i<=n;++i) add(0,i,0);
    if (spfa()) printf("No");
    else printf("Yes");
    return 0;
}

/*
1. a>=b+c -> b<=a+(-c)
2. a<=b+c -> a<=b+c
3. a==b -> a<=b+0 && b<=a+0
*/