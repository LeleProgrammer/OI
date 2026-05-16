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

const int N=2000005;

int T,n,m;
int arr[N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&m);
        _rep(i,1,n) scanf("%1d",&arr[i]);
        if (n==1) {
            puts("-1");
            continue;
        }
        if (n==2 && (arr[1]^arr[2])) {
            puts("-1");
            continue;
        }
        if (n==m) {
            puts("-1");
            continue;
        }
        bool flag=true;
        _rep(i,1,n-1) {
            if (arr[i]) {
                flag=false;
                break;
            }
        }
        flag=flag && arr[n]==1;
        if (flag) {
            printf("%d",arr[1]);
            printf("%d",arr[1]^1);
            _rep(i,2,n) printf("%d",arr[i]);
            _rep(i,1,m-n-1) printf("%d",arr[n]);
            putchar(10);
            continue;
        }
        flag=true;
        _rep(i,1,n-1) {
            if (!arr[i]) {
                flag=false;
                break;
            }
        }
        flag=flag && !arr[n];
        if (flag) {
            printf("%d",arr[1]);
            printf("%d",arr[1]^1);
            _rep(i,2,n) printf("%d",arr[i]);
            _rep(i,1,m-n-1) printf("%d",arr[n]);
            putchar(10);
            continue;
        }
        _rep(i,1,n-1) printf("%d",arr[i]);
        _rep(i,1,m-n) printf("%d",arr[n]^1);
        printf("%d\n",arr[n]);
    }
    return 0;
}