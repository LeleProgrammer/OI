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

const int N=100005;
const int inf=9e18;

int T,n,l,r;
int arr[N];

bool cmp(const int& a,const int& b) {
    return a>b;
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&n,&l,&r);
        _rep(i,1,n) scanf("%lld",&arr[i]);
        int sum=0;
        vector<int> L,R,M;
        _rep(i,1,l-1) L.emplace_back(arr[i]);
        _rep(i,l,r) M.emplace_back(arr[i]),sum+=arr[i];
        _rep(i,r+1,n) R.emplace_back(arr[i]);
        sort(M.begin(),M.end(),cmp);
        sort(L.begin(),L.end());
        sort(R.begin(),R.end());
        int k,ans1,ans2;
        k=sum,ans1=inf;
        _rep(i,0,(int)min(L.size(),M.size())) {
            if (i) k=k-M[i-1]+L[i-1];
            ans1=min(ans1,k);
        }
        k=sum,ans2=inf;
        _rep(i,0,(int)min(R.size(),M.size())) {
            if (i) k=k-M[i-1]+R[i-1];
            ans2=min(ans2,k);
        }
        printf("%lld\n",min(ans1,ans2));
    }
    return 0;
}