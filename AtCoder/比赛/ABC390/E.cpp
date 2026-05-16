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

const int N=5005;
const int inf=1e9;

int n,x;
int f[4][N];

struct node {
    int a,c;
};

vector<node> arr[4];

bool check(int mid) {
    int sum=0;
    _rep(t,1,3) {
        int mn=inf;
        _rep(i,0,x) {
            if (f[t][i]>=mid) {
                mn=i;
                break;
            }
        }
        sum+=mn;
    }
    return sum<=x;
}

signed main() {
    scanf("%lld %lld",&n,&x);
    _rep(i,1,n) {
        int v,a,c;
        scanf("%lld %lld %lld",&v,&a,&c);
        arr[v].push_back({a,c});
    }
    _rep(t,1,3) _rep(i,0,N-1) f[t][i]=-inf;
    _rep(i,1,3) memset(f[i],0,sizeof(f[i]));
    _rep(t,1,3) {
        _rep(i,0,(int)arr[t].size()-1) {
            _rrep(j,x,arr[t][i].c) {
                f[t][j]=max(f[t][j],f[t][j-arr[t][i].c]+arr[t][i].a);
            }
        }
    }
    int l=0,r=1e9;
    while (l<r) {
        int mid=(l+r>>1)+1;
        if (check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%lld",l);
    return 0;
}