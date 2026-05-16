#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;

const int N=10005;
const int M=40005;

typedef pair<int,int> pii;

int n,m,s,t;
int e[M],w[M],ne[M],h[N],tot;
bool flag[N];
bool inq[N];
queue<int> q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void bfs(int mid) {
    while (!q.empty()) q.pop();
    for (int i=1;i<=n;++i) flag[i]=inq[i]=false;
    flag[s]=true;
    inq[s]=true;
    q.push(s);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        inq[u]=false;
        for (int i=h[u];~i;i=ne[i]) {
            if (flag[e[i]] || w[i]>mid) continue;
            flag[e[i]]=true;
            if (!inq[e[i]]) {
                inq[e[i]]=true;
                q.push(e[i]);
            }
        }
    }
}

bool check(int mid) {
    bfs(mid);
    return flag[t];
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d %d",&n,&m,&s,&t);
    while (m--) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    int l=0,r=10000;
    while (l<r) {
        int mid=l+r>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d",l);
    return 0;
}