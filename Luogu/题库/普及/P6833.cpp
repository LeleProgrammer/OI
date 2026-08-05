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
typedef pair<int,pii> piii;

const int N=1005;
const int inf=5e18;

int n,m,a,b,c;
int arr[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int dis[3][N][N];
bool flag[N][N];
int ans=inf;
priority_queue<piii,vector<piii>,greater<piii>> q;

bool check(int i,int j) {
    return i>=1 && i<=n && j>=1 && j<=m;
}

void dijkstra(pii s,int p) {
    memset(flag,0,sizeof(flag));
    _rep(i,1,n) _rep(j,1,m) dis[p][i][j]=inf;
    q.push({dis[p][s.first][s.second]=arr[s.first][s.second],{s.first,s.second}});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        auto u=tp.second;
        if (flag[u.first][u.second]) continue;
        flag[u.first][u.second]=true;
        _rep(i,0,3) {
            int nx=u.first+dx[i];
            int ny=u.second+dy[i];
            if (check(nx,ny) && dis[p][nx][ny]>dis[p][u.first][u.second]+arr[nx][ny] && !flag[nx][ny]) q.push({dis[p][nx][ny]=dis[p][u.first][u.second]+arr[nx][ny],{nx,ny}});
        }
    }
}

signed main() {
    scanf("%lld %lld %lld %lld %lld",&n,&m,&a,&b,&c);
    _rep(i,1,n) _rep(j,1,m) scanf("%lld",&arr[i][j]);
    dijkstra({1,a},0);
    dijkstra({n,b},1);
    dijkstra({n,c},2);
    _rep(i,1,n) {
        _rep(j,1,m) {
            ans=min(ans,dis[0][i][j]+dis[1][i][j]+dis[2][i][j]-(arr[i][j]<<1LL));
        }
    }
    printf("%lld",ans);
    return 0;
}