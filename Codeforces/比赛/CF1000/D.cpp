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

const int N=200005;
const int inf=1e18;

int T,n,m;
int a[N],b[N];
int ans1[N],ans2[N];
int ans[N];

int solve_cnt(int n,int m) {
    int ans=0;
    while (n && m && n+m>=3) {
        if (n<m) swap(n,m);
        n-=2,m--,ans++;
    }
    return ans;
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld",&n,&m);
        _rep(i,1,n) ans1[i]=-inf;
        _rep(i,1,m) ans2[i]=-inf;
        _rep(i,1,n) scanf("%lld",&a[i]);
        _rep(i,1,m) scanf("%lld",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        int mxcnt=solve_cnt(n,m);
        printf("%lld\n",mxcnt);
        _rep(i,0,mxcnt) ans[i]=-inf;
        int i=1,j=n,idx=0;
        while (i<j) ans1[++idx]=a[j]-a[i],i++,j--;
        // printf("ans1: "); _rep(i,1,idx) printf("%lld ",ans1[i]); putchar(10);
        i=1,j=m,idx=0;
        while (i<j) ans2[++idx]=b[j]-b[i],i++,j--;
        // printf("ans2: "); _rep(i,1,idx) printf("%lld ",ans2[i]); putchar(10);
        i=1,j=1;
        int cur=0;
        while (i-1+j-1<mxcnt) {
            int ansL=-inf,ansR=-inf,minusL=inf,minusR=inf;
            if (ans1[i]!=-inf) {
                minusL=0;
                ansL=ans1[i];
                while (i*2+j-minusL-1>n || (j-1-minusL)*2+i>m) minusL++;
                _rep(g,1,minusL) ansL-=ans2[j-g];
            }
            if (ans2[j]!=-inf) {
                minusR=0;
                ansR=ans2[j];
                while (j*2+i-minusR-1>m || (i-1-minusR)*2+j>n) minusR++;
                _rep(g,1,minusR) ansR-=ans1[i-g];
            }
            if (minusL<minusR || (minusL==minusR && ansL>ansR)) {
                ++i;
                j-=minusL;
                cur+=ansL;
            } else {
                ++j;
                i-=minusR;
                cur+=ansR;
            }
            ans[i+j-2]=max(ans[i+j-2],cur);
            // cout<<"TEST: "<<i<<" "<<j<<" "<<cur<<endl;
            // string stop;
            // cin>>stop;
        }
        _rep(i,1,mxcnt) printf("%lld ",ans[i]);
        putchar(10);
    }
    return 0;
}

/*
1
2 4
0 1000
-100 -50 0 50

ans:
2
1000 200
*/