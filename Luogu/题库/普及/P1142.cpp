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

const int N=705;
const double pi=acos(-1);
const double eps=1e-9;

int n;

struct Point {
    double x,y;
    friend Point operator + (const Point& a,const Point& b) {
        return {a.x+b.x,a.y+b.y};
    }
    friend Point operator - (const Point& a,const Point& b) {
        return {a.x-b.x,a.y-b.y};
    }
} arr[N];

int sign(double k) {
    if (fabs(k)<eps) return 0;
    else if (k>0) return 1;
    else return -1;
}

int cmp(double a,double b) {
    if (fabs(a-b)<eps) return 0;
    else if (a>b) return 1;
    else return -1;
}

double dot(Point a,Point b) {
    return a.x*b.x+a.y*b.y;
}

double cross(Point a,Point b) {
    return a.x*b.y-a.y*b.x;
}

double area(Point a,Point b,Point c) {
    return cross(b-a,c-a);
}

int main() {
    scanf("%d",&n);
    _rep(i,1,n) {
        double x,y;
        scanf("%lf %lf",&x,&y);
        arr[i]={x,y};
    }
    int ans=0;
    _rep(i,1,n) {
        _rep(j,i+1,n) {
            int cnt=2;
            _rep(k,1,n) {
                if (k==i || k==j) continue;
                if (!sign(area(arr[i],arr[j],arr[k]))) cnt++;
            }
            ans=max(ans,cnt);
        }
    }
    printf("%d",ans);
    return 0;
}