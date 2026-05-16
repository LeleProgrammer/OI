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

const int N=25;
const int inf=2e9;

int n;
int arr[N],sum;
int ans=inf;

int main() {
    scanf("%d",&n);
    _rep(i,1,n) scanf("%d",&arr[i]),sum+=arr[i];
    _rep(i,0,(1<<n)-1) {
        int k=0;
        _rep(j,0,n-1) if ((i>>j)&1) k+=arr[j];
        ans=min(ans,max(k,sum-k));
    }
    printf("%d",ans);
    return 0;
}