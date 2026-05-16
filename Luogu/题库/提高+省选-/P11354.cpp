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

const int N=100005;

int n,root;
int sz[N];
bool flag[N];
vector<int> vec[N];

extern "C" bool ask(int k);

inline void dfs(int u) {
    if (flag[u]) {
        sz[u]=0;
        return;
    }
    sz[u]=1;
    _iter(it,vec[u]) {
        dfs(*it);
        sz[u]+=sz[*it];
    }
}

inline int find(int u) {
    if (sz[u]<=sz[root]/2) return u;
    assert(!vec[u].empty());
    if (vec[u].size()==2 && sz[vec[u][0]]<sz[vec[u][1]]) swap(vec[u][0],vec[u][1]);
    return find(vec[u][0]);
}

extern "C" int solve(int n,vector<int> p) {
    // assert(ask(1)==1);
    _rep(i,0,(int)p.size()-1) vec[p[i]].emplace_back(i+2);
    root=1;
    while (true) {
        dfs(root);
        if (sz[root]==1) return root;
        int t=find(root);
        int k=ask(t);
        if (k) root=t;
        else flag[t]=true;
    }
    return 114514;
}