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

const int N=10005;

struct Point {
    double x,y;
} arr[N];

int n;
double ans=1.5e9;

double get_dis(Point& a,Point& b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main() {
    scanf("%d",&n);
    _rep(i,1,n) {
        double x,y;
        scanf("%lf %lf",&x,&y);
        arr[i]={x,y};
    }
    _rep(i,1,n) _rep(j,i+1,n) ans=min(ans,get_dis(arr[i],arr[j]));
    printf("%.4lf",ans);
    return 0;
}