#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long

const int N=10005;
const int M=20005;
const int inf=2e9;

typedef pair<int,int> pii;

int n,k;
int e[M],ne[M],w[M],h[N],tot;
bool st[N],flag[N];
int dis[N];
priority_queue<pii,vector<pii>,greater<pii>> q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra() {
    _rep(i,1,n+1) dis[i]=inf;
    q.push({dis[1]=0,1});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (flag[u]) continue;
        flag[u]=true;
        _graph(i,u) if (dis[e[i]]>dis[u]+w[i] && !flag[e[i]]) q.push({dis[e[i]]=dis[u]+w[i],e[i]});
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&k);
    _rep(i,1,k) {
        int l,r;
        scanf("%d %d",&l,&r);
        r=l+r-1;
        add(l,r+1,r-l+1);
        st[l]=true;
    }
    _rep(i,1,n) if (!st[i]) add(i,i+1,0);
    dijkstra();
    printf("%d",n-dis[n+1]);
    return 0;
}