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
typedef pair<int,int> pii;

const int N=20005;

int n,m,a,b;
int l[N],r[N];
int L,R;

signed main() {
    scanf("%lld %lld %lld %lld",&n,&m,&a,&b);
    _rep(i,1,m) scanf("%lld %lld",&l[i],&r[i]);
    L=1,R=1;
    bool ok=true;
    _rep(i,1,m) {
        int k=(l[i]-1-R)/b;
        if (k>0) {
            R+=k*b;
            L+=k*a;
        }
        int LL=L,RR=R;
        L=r[i]+1;
        bool qt=false;
        while (true) {
            // cout<<"test: "<<LL<<" "<<RR<<" "<<l[i]<<" "<<r[i]<<endl;
            if (RR>=l[i]) {
                if (LL<l[i] && RR<=r[i]) {
                    RR=l[i]-1;
                } else if (LL<l[i] && r[i]<RR) {
                    R=max(R,RR);
                    RR=l[i]-1;
                } else if (l[i]<=LL && r[i]<RR) {
                    R=max(R,RR);
                    RR=l[i]-1;
                } else break;
            }
            if (qt) break;
            if (RR==l[i]-1) qt=true;
            LL+=a,RR+=b;
        }
        if (R<=r[i]) {
            ok=false;
            break;
        }
    }
    if (R<n) {
        int k=(n-1-R)/b;
        ++k;
        R+=k*b;
        L+=k*a;
    }
    // if (n<L || n>R) ok=false;
    if (ok) puts("Yes");
    else puts("No");
    return 0;
}