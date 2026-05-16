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

int T,n;
int e[M],ne[M],h[N],tot;
int deg[N],d[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

int main() {
    scanf("%d",&T);
    deg[0]=-1;
    while (T--) {
        scanf("%d",&n);
        _rep(i,1,n) deg[i]=0,h[i]=-1,d[i]=0;
        tot=0;
        _rep(i,1,n-1) {
            int x,y;
            scanf("%d %d",&x,&y);
            add(x,y); add(y,x);
            deg[x]++,deg[y]++;
        }
        _rep(u,1,n) _graph(i,u) d[u]+=deg[e[i]];
        int ans=1;
        _rep(tt,1,2) {
            int u=0;
            _rep(i,1,n) if (deg[i]>deg[u] || (deg[i]==deg[u] && d[i]<d[u])) u=i;
            _graph(i,u) deg[e[i]]--;
            ans+=deg[u];
            ans--;
            deg[u]=-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
1
8
1 2
1 5
1 6
2 3
2 4
6 7
6 8

ans: 5
*/