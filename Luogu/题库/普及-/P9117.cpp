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

int T,n,m,q;

struct node {
    int t,c;
} v[N],h[N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d %d",&n,&m,&q);
        memset(v,0,sizeof(v));
        memset(h,0,sizeof(h));
        int d=0;
        while (q--) {
            int op,x,c;
            scanf("%d %d %d",&op,&x,&c);
            d++;
            if (!op) h[x]={d,c};
            else v[x]={d,c};
        }
        _rep(i,1,n) {
            _rep(j,1,m) {
                if (h[i].t>v[j].t) printf("%d ",h[i].c);
                else printf("%d ",v[j].c);
            }
            putchar(10);
        }
    }
    return 0;
}