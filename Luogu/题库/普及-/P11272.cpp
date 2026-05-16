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

const int N=1000005;

int n,q;
int arr[N];
int pre[N];

int main() {
    scanf("%d %d",&n,&q);
    _rep(i,1,n) scanf("%d",&arr[i]),pre[i]=pre[i-1]+arr[i];
    while (q--) {
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        int cnt=pre[r]-pre[l-1];
        if (k>=r-l+1) puts("-1");
        else if (k==r-l) printf("%d\n",min(abs(k-cnt),abs(k+1-cnt)));
        else printf("%d\n",abs(k-cnt));
    }
    return 0;
}