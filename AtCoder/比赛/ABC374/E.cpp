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

const int N=105;
const int inf=2e9;

int n,x;

struct Machine {
    int a,p,b,q;
} arr[N];

bool check(int mid) {
    int now=0;
    _rep(i,1,n) {
        // cout<<"now: "<<i<<" "<<now<<endl;
        if (now>x) return false;
        int k=mid/arr[i].a;
        int rem=mid%arr[i].a;
        int cost=arr[i].p*k;
        if (!rem) {
            now+=cost;
            continue;
        }
        int ret=inf;
        _rep(j,1,100) {
            int k2=rem/arr[i].b;
            int cost2=arr[i].q*k2;
            if (rem%arr[i].b) cost2+=arr[i].q;
            int k3=rem/arr[i].a;
            int cost3=arr[i].p*k3;
            if (rem%arr[i].a) cost3+=arr[i].p;
            ret=min(ret,min(cost+cost3,cost+cost2));
            k--;
            rem+=arr[i].a;
            cost-=arr[i].p;
            if (k<0) break;
        }
        now+=ret;
    }
    return now<=x;
}

signed main() {
    scanf("%lld %lld",&n,&x);
    _rep(i,1,n) {
        int a,p,b,q;
        scanf("%lld %lld %lld %lld",&a,&p,&b,&q);
        if (p*b>q*a) swap(a,b),swap(p,q);
        arr[i]={a,p,b,q};
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