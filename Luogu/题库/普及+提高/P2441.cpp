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

int n,k;
int arr[N],fa[N];

int gcd(int a,int b) {
    if (!b) return a;
    else return gcd(b,a%b);
}

int main() {
    scanf("%d %d",&n,&k);
    _rep(i,1,n) scanf("%d",&arr[i]);
    _rep(i,1,n-1) {
        int x,y;
        scanf("%d %d",&x,&y);
        fa[y]=x;
    }
    while (k--) {
        int op,u;
        scanf("%d %d",&op,&u);
        if (op==1) {
            int v=fa[u];
            int ans=-1;
            while (v) {
                if (gcd(arr[u],arr[v])>1) {
                    ans=v;
                    break;
                }
                v=fa[v];
            }
            printf("%d\n",ans);
        } else {
            int a;
            scanf("%d",&a);
            arr[u]=a;
        }
    }
    return 0;
}