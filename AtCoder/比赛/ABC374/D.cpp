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

const int N=7;
const double inf=2e9;
const double eps=1e-6;

int n;
double T,S;
double ans=inf;
int p[N];

struct Point {
    double x,y;
};

struct Segment {
    Point a,b;
} arr[N];

double dist(Point a,Point b) {
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

int main() {
    scanf("%d %lf %lf",&n,&S,&T);
    _rep(i,1,n) {
        double a,b,c,d;
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        arr[i]={{a,b},{c,d}};
    }
    _rep(i,1,n) p[i]=i;
    do {
        _rep(i,0,(1<<n)-1) {
            _rep(j,1,n) if ((i>>(j-1))&1) swap(arr[p[j]].a,arr[p[j]].b);
            Point now={0,0};
            double cost=0;
            _rep(j,1,n) {
                double dis=dist(now,arr[p[j]].a);
                cost+=dis/S;
                dis=dist(arr[p[j]].a,arr[p[j]].b);
                cost+=dis/T;
                now=arr[p[j]].b;
            }
            ans=min(ans,cost);
            _rep(j,1,n) if ((i>>(j-1))&1) swap(arr[p[j]].a,arr[p[j]].b);
        }
    } while (next_permutation(p+1,p+1+n));
    printf("%.8lf",ans);
    return 0;
}