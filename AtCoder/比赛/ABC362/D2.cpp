#include <bits/stdc++.h>

#define int long long

using namespace std;

namespace IO {
    inline void read(int &a) {
        int sym=1,num=0;
        char c=getchar();
        while (c<'0' || c>'9') {
            if (c=='-') {
                sym=-1;
        }
        c=getchar();
        }
        while (c>='0' && c<='9') {
            num=num*10+c-'0';
            c=getchar();
        }
        a=sym*num;
    }
    inline void write(int a) {
        if (a<0) {
            putchar('-');
            a*=-1;
        }
        if (a>=10) {
            write(a/10);
        }
        putchar(a%10+'0');
    }
}

using namespace IO;

const int N=200005;
const int M=400005;
const int inf=9e18;

typedef pair<int,int> pii;

int n,m;
int arr[N];
int e[M],ne[M],w[M],h[N],tot;
int dis[N];
bool flag[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

inline void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra() {
    for (int i=0;i<N;++i) dis[i]=inf;
    q.push({dis[1]=arr[1],1});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (flag[u]) continue;
        flag[u]=true;
        for (int i=h[u];~i;i=ne[i]) {
            if (dis[e[i]]>dis[u]+w[i]) {
                dis[e[i]]=dis[u]+w[i];
                q.push({dis[e[i]],e[i]});
            }
        }
    }
}

signed main() {
    read(n);
    read(m);
    for (int i=1;i<=n;++i) h[i]=-1;
    for (int i=1;i<=n;++i) read(arr[i]);
    while (m--) {
        int a,b,c;
        read(a);
        read(b);
        read(c);
        add(a,b,c+arr[b]);
        add(b,a,c+arr[a]);
    }
    dijkstra();
    for (int i=2;i<=n;++i) {
        printf("%lld ",dis[i]);
    }
    return 0;
}