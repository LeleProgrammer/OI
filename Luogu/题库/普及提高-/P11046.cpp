#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=1005;
const int M=10005;
const int inf=1e9;

int n,m,Q;
int e[M],ne[M],h[N],tot;
bool flag[N];
int dis[N][N];
priority_queue<pii,vector<pii>,greater<pii>> q;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s) {
    _rep(i,1,n) dis[s][i]=inf,flag[i]=false;
    q.push({dis[s][s]=0,s});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (flag[u]) continue;
        _graph(i,u) if (dis[s][e[i]]>dis[s][u]+1) q.push({dis[s][e[i]]=dis[s][u]+1,e[i]});
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld %lld",&n,&m,&Q);
    while (m--) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        add(a,b); add(b,a);
    }
    _rep(i,1,n) dijkstra(i);
    int sum=0,cnt=0;
    while (Q--) {
        int x,y;
        scanf("%lld %lld",&x,&y);
        ++cnt;
        _rep(i,1,n) if (dis[x][i]<=y) ++sum;
    }
    printf("%.2lf",(double)sum/cnt);
    return 0;
}