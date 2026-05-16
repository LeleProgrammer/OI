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

const int N=15;

int n,res;
int arr[N];
bool flag[N];
unordered_set<int> ans[N];

void dfs(int rem) {
    // _rep(i,1,n-rem) printf("  "); cout<<"TEST: "; _rep(i,1,n) printf("%d ",arr[i]); printf(", "); printf("%lld\n",res);
    if (ans[rem].count(res)) return;
    ans[rem].emplace(res);
    if (rem==1) return;
    _rep(i,1,n) {
        if (flag[i]) continue;
        _rep(j,1,n) {
            if (flag[j] || i==j) continue;
            flag[i]=true;
            res^=arr[i];
            res^=arr[j];
            res^=(arr[i]+arr[j]);
            int a=arr[i],b=arr[j];
            arr[j]=a+b,arr[i]=0;
            dfs(rem-1);
            arr[i]=a,arr[j]=b;
            flag[i]=false;
            res^=arr[i];
            res^=arr[j];
            res^=(arr[i]+arr[j]);
        }
    }
}

signed main() {
    scanf("%lld",&n);
    _rep(i,1,n) {
        scanf("%lld",&arr[i]);
        res^=arr[i];
    }
    dfs(n);
    unordered_set<int> k;
    _rep(i,1,n) _iter(it,ans[i]) k.emplace(*it);
    printf("%lld",(int)k.size());
    return 0;
}