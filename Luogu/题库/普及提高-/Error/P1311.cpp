#include <bits/stdc++.h>
using namespace std;

#define int long long

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
typedef pair<int,int> pii;

const int N=200005;
const int M=55;

int n,k,p;
int cnt[M];
int flag[M];
int f[N];

struct node {
    int a,b;
} arr[N];

signed main() {
    FRR("P1311_1.in");
    scanf("%lld %lld %lld",&n,&k,&p);
    _rep(i,1,n) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        arr[i]={a,b};
    }
    _rep(i,1,n) {
        ;
    }
    int ans=0;
    _rep(i,1,n) ans+=f[i],printf("f[%lld] = %lld\n",i,f[i]);
    printf("%lld",ans);
    return 0;
}