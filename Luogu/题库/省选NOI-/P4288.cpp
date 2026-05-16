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

const int N=50005;
const double eps=1e-12;
const double pi=acos(-1);

int n;

struct Point {
    double x,y;
    friend Point operator + (Point a,Point b) {
        return {a.x+b.x,a.y+b.y};
    }
    friend Point operator - (Point a,Point b) {
        return {a.x-b.x,a.y-b.y};
    }
    friend Point operator * (Point a,double b) {
        return {a.x*b,a.y*b};
    }
    friend Point operator / (Point a,double b) {
        return {a.x/b,a.y/b};
    }
} arr[N];

struct Line {
    Point a,b;
};

struct Circle {
    Point o;
    double r;
};

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

Point rotate(Point a,double k) {
    return {a.x*cos(k)+a.y*sin(k),-a.x*sin(k)+a.y*cos(k)};
}

Point get_intersection(Point p,Point v,Point q,Point w) {
    auto u=p-q;
    auto t=cross(w,u)/cross(v,w);
    return p+v*t;
}

Line get_line(Point a,Point b) {
    return {(a+b)/2,rotate(b-a,pi/2)};
}

double get_dis(Point a,Point b) {
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

Circle get_circle(Point a,Point b,Point c) {
    auto p=get_line(a,b),q=get_line(a,c);
    auto o=get_intersection(p.a,p.b,q.a,q.b);
    auto r=get_dis(o,a);
    return {o,r};
}

int main() {
    scanf("%d",&n);
    _rep(i,1,n) {
        double x,y;
        scanf("%lf %lf",&x,&y);
        arr[i]={x,y};
    }
    double a,p;
    scanf("%lf %lf",&a,&p);
    _rep(i,1,n) {
        arr[i]=rotate(arr[i],a/180*pi);
        arr[i].x/=p;
    }
    random_shuffle(arr+1,arr+1+n);
    Circle c={arr[1],0};
    _rep(i,2,n) {
        if (cmp(c.r,get_dis(c.o,arr[i]))>=0) continue;
        c={arr[i],0};
        _rep(j,1,i-1) {
            if (cmp(c.r,get_dis(c.o,arr[j]))>=0) continue;
            c={(arr[i]+arr[j])/2,get_dis(arr[i],arr[j])/2};
            _rep(k,1,j-1) {
                if (cmp(c.r,get_dis(c.o,arr[k]))>=0) continue;
                c=get_circle(arr[i],arr[j],arr[k]);
            }
        }
    }
    printf("%.3lf",c.r);
    return 0;
}