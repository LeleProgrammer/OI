#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=505;
const int M=105;

int n,k,ans;
int f[N][M];

struct Point {
    int x,y;
    bool operator != (const Point& a) const {
        return x!=a.x || y!=a.y;
    }
    bool operator > (const Point& a) const {
        return x>=a.x && y>=a.y && (*this)!=a;
    }
    bool operator < (const Point& a) const {
        if (y!=a.y) return y<a.y;
        return x<a.x;
    }
} arr[N];

int main() {
    scanf("%d %d",&n,&k);
    _rep(i,1,n) {
        int x,y;
        scanf("%d %d",&x,&y);
        arr[i]={x,y};
    }
    sort(arr+1,arr+1+n);
    _rep(i,1,n) {
        _rep(j,0,k) f[i][j]=j+1;
        _rep(j,1,n) {
            if (arr[i]>arr[j]) {
                _rep(t,0,k) {
                    int p=arr[i].x-arr[j].x+arr[i].y-arr[j].y-1;
                    if (t-p>=0) f[i][t]=max(f[i][t],f[j][t-p]+p+1);
                }
            }
        }
    }
    _rep(i,1,n) _rep(j,0,k) ans=max(ans,f[i][j]);
    printf("%d",ans);
    return 0;
}