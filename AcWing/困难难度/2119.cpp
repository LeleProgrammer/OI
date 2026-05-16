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

const int N=1005;
const double eps=1e-11;
const double pi=acos(-1);

int n;

double randd() {
    return ((double)rand()/RAND_MAX-0.5)*eps;
}

struct Point {
    double x,y,z;
    void shake() {
        x+=randd();
        y+=randd();
        z+=randd();
    }
    friend Point operator + (Point a,Point b) {
        return {a.x+b.x,a.y+b.y,a.z+b.z};
    }
    friend Point operator - (Point a,Point b) {
        return {a.x-b.x,a.y-b.y,a.z-b.z};
    }
    friend double operator & (Point a,Point b) {
        return a.x*b.x+a.y*b.y+a.z*b.z;
    }
    friend Point operator * (Point a,Point b) {
        return {a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};
    }
    double len() {
        return sqrt(x*x+y*y+z*z);
    }
} arr[N];

struct Plane {
    int v[3];
    Point norm() {
        return (arr[v[1]]-arr[v[0]])*(arr[v[2]]-arr[v[0]]);
    }
    double area() {
        return norm().len()/2;
    }
    bool above(Point a) {
        return ((a-arr[v[0]])&norm())>=0;
    }
} p[N],np[N];

int cnt;
bool chk[N][N];

void solve3D() {
    p[++cnt]={1,2,3};
    p[++cnt]={3,2,1};
    _rep(i,4,n) {
        int nex=0;
        _rep(j,1,cnt) {
            bool flag=p[j].above(arr[i]);
            if (!flag) np[++nex]=p[j];
            _rep(k,0,2) chk[p[j].v[k]][p[j].v[(k+1)%3]]=flag;
        }
        _rep(j,1,cnt) {
            _rep(k,0,2) {
                int a=p[j].v[k],b=p[j].v[(k+1)%3];
                if (chk[a][b] && !chk[b][a]) np[++nex]={a,b,i};
            }
        }
        cnt=nex;
        _rep(j,1,cnt) p[j]=np[j];
    }
}

int main() {
    scanf("%d",&n);
    _rep(i,1,n) {
        double x,y,z;
        scanf("%lf %lf %lf",&x,&y,&z);
        arr[i]={x,y,z};
        arr[i].shake();
    }
    solve3D();
    double res=0;
    _rep(i,1,cnt) res+=p[i].area();
    printf("%.6lf",res);
    return 0;
}