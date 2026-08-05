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

const int N=10005;
const int M=1000005;

int n;
int e[M],ne[M],h[N],tot;
int indeg[N];
int f[N],arr[N];
queue<int> q;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void topu() {
    _rep(i,1,n) if (!indeg[i]) q.push(i);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        _graph(i,u) {
            f[e[i]]=max(f[e[i]],f[u]+arr[u]);
            if (--indeg[e[i]]==0) q.emplace(e[i]);
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    _rep(i,1,n) {
        int j;
        scanf("%d",&j);
        scanf("%d",&arr[j]);
        int v;
        while (true) {
            scanf("%d",&v);
            if (v) add(v,j),indeg[j]++;
            else break;
        }
    }
    topu();
    int ans=0;
    _rep(i,1,n) ans=max(ans,f[i]+arr[i]);
    printf("%d",ans);
    return 0;
}