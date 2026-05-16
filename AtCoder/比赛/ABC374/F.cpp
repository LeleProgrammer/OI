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
const int inf=1e13;

int n,K,x,ans;
int arr[N];
int p[N];

signed main() {
    scanf("%lld %lld %lld",&n,&K,&x);
    _rep(i,1,n) scanf("%lld",&arr[i]);
    p[0]=-inf;
    p[1]=arr[1];
    // _rep(i,2,n) p[i]=max(p[i-1]+x,arr[i]);
    _rep(i,2,n) p[i]=inf;
    // printf("p: "); _rep(i,1,n) printf("%lld ",p[i]); putchar(10);
    _rep(i,2,n) {
        int t=min(p[i]-p[i-1]-x,p[i]-arr[i]);
        if (t>0) p[i]-=t;
        // _rep(j,max(i-K+1,1LL),i-1) {
        _rrep(j,i-1,max(i-K+1,1LL)) {
            // cout<<"now: "<<i<<" "<<j<<endl;
            int len=i-j+1;
            int sum=0,avg;
            _rep(k,j,i) sum+=p[k];
            avg=sum/len;
            // cout<<sum<<" "<<len<<" "<<avg<<endl;
            if (avg<arr[i] || avg-p[j-1]<x) continue;
            // while (avg>arr[i] && !(j!=1 && avg-p[j-1]<=x)) avg--;
            int t=min(avg-arr[i],avg-p[j-1]-x);
            if (t>0) avg-=t;
            // cout<<"test: "<<avg<<" "<<p[j-1]<<endl;
            _rep(k,j,i) p[k]=avg;
            // cout<<"done: "<<i<<" "<<j<<endl;
            break;
        }
        printf("%d p: ",i); _rep(i,1,n) printf("%lld ",p[i]==inf?-1:p[i]); putchar(10);
    }
    // printf("p: "); _rep(i,1,n) printf("%lld ",p[i]==inf?-1:p[i]); putchar(10);
    _rep(i,1,n) {
        int j=i;
        while (p[j]==p[i]) ++j;
        --j;
        // while (p[j]>arr[j] && !(i!=1 && p[j]-p[i-1]<=x)) p[j]--;
        int t=min(p[j]-arr[j],p[j]-p[i-1]-x);
        if (t>0) p[j]-=t;
        _rep(k,i,j-1) p[k]=p[j];
        // printf("%d %d p: ",i,j); _rep(i,1,n) printf("%lld ",p[i]==inf?-1:p[i]); putchar(10);
        i=j;
    }
    _rep(i,1,n) ans+=p[i]-arr[i];
    printf("p: "); _rep(i,1,n) printf("%lld ",p[i]==inf?-1:p[i]); putchar(10);
    printf("%lld",ans);
    return 0;
}