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

const double pi=acos(-1);
const double eps=1e-9;

int sign(double k) {
    if (fabs(k)<eps) return 0;
    else if (k>0) return 1;
    else return -1;
}

double cmp(double a,double b) {
    if (fabs(a-b)<eps) return 0;
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
} a,b,c,d;

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
    scanf(" (%lf,%lf)",&a.x,&a.y);
    scanf(" (%lf,%lf)",&b.x,&b.y);
    scanf(" (%lf,%lf)",&c.x,&c.y);
    scanf(" (%lf,%lf)",&d.x,&d.y);
    if (a==d || b==d || c==d) puts("4");
    else if (abs(sign(area(d,a,b))+sign(area(d,b,c))+sign(area(d,c,a)))==3) puts("1");
    else if (abs(sign(area(d,a,b))+sign(area(d,b,c))+sign(area(d,c,a)))==0) puts("2");
    else if (!area(a,b,d) || !area(b,c,d) || !area(c,a,d)) puts("3");
    else puts("2");
    return 0;
}