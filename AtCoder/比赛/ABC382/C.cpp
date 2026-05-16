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

const int N=200005;

int n,m;
int a[N];
int ans[N];

struct node {
    int b,i;
    friend bool operator < (const node& a,const node& b) {
        return a.b>b.b;
    }
} arr[N];

int main() {
    scanf("%d %d",&n,&m);
    _rep(i,1,n) scanf("%d",&a[i]);
    _rep(i,1,m) scanf("%d",&arr[i].b),arr[i].i=i;
    sort(arr+1,arr+1+m);
    int i=1;
    _rep(j,1,m) {
        while (i<=n && arr[j].b<a[i]) ++i;
        ans[arr[j].i]=i;
    }
    _rep(i,1,m) {
        if (ans[i]==n+1) puts("-1");
        else printf("%d\n",ans[i]);
    }
    return 0;
}