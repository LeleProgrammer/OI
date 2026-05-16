#include <bits/stdc++.h>
using namespace std;

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

const int N=200005;
const int M=400005;
const int inf=2e9;

int n,m,S,T;
int e[M],ne[M],h[N],tot;
int dis[N],deg[N];
bool flag[N];
bool vis[N];
priority_queue<pii,vector<pii>,greater<pii>> q;
vector<int> vec,bk;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s) {
    _rep(i,0,N-1) dis[i]=inf,flag[i]=false;
    q.push({dis[s]=0,s});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (flag[u]) continue;
        _graph(i,u) if (dis[e[i]]>dis[u]+1) q.push({dis[e[i]]=dis[u]+1,e[i]});
    }
}

void dfs(int u,int dep,int& ans) {
    vis[u]=true;
    if (deg[u]>=3) ans=min(ans,dep);
    _graph(i,u) {
        if (vis[e[i]]) continue;
        dfs(e[i],dep+1,ans);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d %d",&n,&m,&S,&T);
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b); add(b,a);
        deg[a]++,deg[b]++;
    }
    dijkstra(S);
    int u=T;
    while (u!=S) {
        _graph(i,u) {
            if (dis[e[i]]==dis[u]-1) {
                u=e[i];
                vec.emplace_back(u);
                break;
            }
        }
    }
    reverse(vec.begin(),vec.end());
    // printf("vec: "); _iter(it,vec) printf("%d ",*it); putchar(10);
    int inc=inf,las=0;
    u=T;
    bk=vec;
    while (u!=S) {
        _graph(i,u) {
            if (dis[e[i]]==dis[u]-1 && e[i]!=vec.back()) {
                inc=0;
                break;
            } else if (dis[e[i]]==dis[u]) inc=min(inc,1);
            else if (dis[e[i]]>dis[u] && u!=T && e[i]!=las) inc=min(inc,dis[e[i]]-dis[u]+1);
        }
        las=u;
        u=vec.back();
        vec.pop_back();
    }
    // printf("inc: %d\n",inc);
    if (inc!=inf) {
        printf("%d",dis[T]*2+inc);
        return 0;
    }
    int ansT=inf;
    vis[bk.back()]=true;
    dfs(T,0,ansT);
    int ansS=inf;
    if ((int)bk.size()==1) bk.emplace_back(T);
    vis[bk[1]]=true;
    dfs(S,0,ansS);
    if (ansT==inf && ansS==inf) {
        puts("-1");
        return 0;
    }
    printf("%d",dis[T]*2+(min(ansS,ansT)+1)*4);
    return 0;
}