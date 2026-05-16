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

const int N=500005;

int n;
int a[N];
int arr[N];

struct Seg {
    int l,r;
    int sum;
} tr[N<<2];

signed main() {
    scanf("%lld",&n);
    _rep(i,1,n) scanf("%lld",&a[i]);
    int cur=0;
    _rep(i,1,n) {
        cur+=arr[i];
        a[i]+=cur;
        if (i==n) continue;
        int len=n-(i+1)+1;
        arr[i+1]++;
        if (a[i]<len) arr[i+a[i]+1]--;
        a[i]=max(a[i]-len,0LL);
    }
    _rep(i,1,n) printf("%lld ",a[i]);
    return 0;
}