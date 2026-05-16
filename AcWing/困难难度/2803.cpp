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

const int N=505;
const double pi=acos(-1);
const double eps=1e-8;

int n,cnt;
int q[N],hh,tt;

int sign(double k) {
    if (fabs(k)<=eps) return 0;
    else if (k>0) return 1;
    else return -1;
}

int cmp(double a,double b) {
    if (fabs(a-b)<=eps) return 0;
    else if (a>b) return 1;
    else return -1;
}

struct Point {
    double x,y;
    friend Point operator + (const Point& a,const Point& b) {
        return {a.x+b.x,a.y+b.y};
    }
    friend Point operator - (const Point& a,const Point& b) {
        return {a.x-b.x,a.y-b.y};
    }
    friend bool operator == (const Point& a,const Point& b) {
        return !cmp(a.x,b.x) && !cmp(a.y,b.y);
    }
} poly[N];

double dot(Point a,Point b) {
    return a.x*b.x+a.y*b.y;
}

double cross(Point a,Point b) {
    return a.x*b.y-a.y*b.x;
}

double area(Point a,Point b,Point c) {
    return cross(b-a,c-a);
}

struct Line {
    Point a,b;
} arr[N];

double get_angle(Line a) {
    return atan2(a.b.y-a.a.y,a.b.x-a.a.x);
}

bool comp(const Line& a,const Line& b) {
    double theta_a,theta_b;
    theta_a=get_angle(a);
    theta_b=get_angle(b);
    if (!cmp(theta_a,theta_b)) return sign(area(a.a,a.b,b.b))<0;
    return theta_a<theta_b;
}

Point get_intersection(Point p,Point v,Point q,Point w) {
    Point u=p-q;
    double t=cross(w,u)/cross(v,w);
    return {p.x+v.x*t,p.y+v.y*t};
}

Point get_intersection(Line a,Line b) {
    return get_intersection(a.a,a.b-a.a,b.a,b.b-b.a);
}

bool check(Line a,Line b,Line c) { // ab 交点在 c 右边
    return sign(area(c.a,c.b,get_intersection(a,b)))<=0;
}

double half_plane_intersection() {
    hh=0,tt=-1;
    _rep(i,1,cnt) {
        if (i!=1 && !cmp(get_angle(arr[i]),get_angle(arr[i-1]))) continue;
        while (tt-hh+1>=2 && check(arr[q[tt]],arr[q[tt-1]],arr[i])) tt--;
        while (tt-hh+1>=2 && check(arr[q[hh]],arr[q[hh+1]],arr[i])) hh++;
        q[++tt]=i;
    }
    while (tt-hh+1>=2 && check(arr[q[tt]],arr[q[tt-1]],arr[q[hh]])) tt--;
    while (tt-hh+1>=2 && check(arr[q[hh]],arr[q[hh+1]],arr[q[tt]])) hh++;
    q[++tt]=q[hh];
    vector<Point> vec;
    _rep(i,hh,tt-1) vec.emplace_back(get_intersection(arr[q[i]],arr[q[i+1]]));
    double ans=0;
    _rep(i,0,(int)vec.size()-2) ans+=area(vec[0],vec[i],vec[i+1]);
    return ans/2; // 叉积求的是面积的两倍
}

int main() {
    scanf("%d",&n);
    _rep(i,1,n) {
        int m;
        scanf("%d",&m);
        _rep(j,1,m) {
            double x,y;
            scanf("%lf %lf",&x,&y);
            poly[j]={x,y};
        }
        poly[m+1]=poly[1];
        _rep(j,1,m) arr[++cnt]={poly[j],poly[j+1]};
    }
    sort(arr+1,arr+1+cnt,comp);
    double ans=half_plane_intersection();
    printf("%.3lf",ans);
    return 0;
}