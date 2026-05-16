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
#define _riter(i,a) for (auto i=a.rbegin();i!=a.rend();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _dinic(i,u) for (int i=cur[u];~i && k<limit;i=ne[i])
#define rint register int
#define LL long long
#define i32 signed
#define i64 long long
#define i128 __int128
#define u32 unsigned
#define u64 unsigned long long
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<double,double> pdd;

namespace IO {
    template<typename T> inline void read(T& x) {
        int s=1; char c=getchar(); x=0;
        while (!isdigit(c)) { if (c=='-') s=-1; c=getchar(); }
        while (isdigit(c) && c!=EOF) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x[idx++]=c,c=getchar();
        x[idx]='\0';
    }
    template<typename T> inline void write(T x) {
        if (x<0) putchar('-'),x=-x;
        if (x/10) write(x/10);
        putchar('0'+(x%10));
    }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
    inline void writestr(string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=1005;
const double pi=acos(-1);
const double eps=1e-9;

int n,l;
int stk[N],hh;
bool flag[N];

int sign(double k) {
	if (fabs(k)<eps) return 0;
	else if (k>0) return 1;
	else return -1;
}

int cmp(double a,double b) {
	if (fabs(a-b)<eps) return 0;
	else if (a<b) return -1;
	else return 1;
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
	friend bool operator < (const Point& a,const Point& b) {
		if (cmp(a.x,b.x)) return cmp(a.x,b.x)<0;
		else return cmp(a.y,b.y)<0;
	}
} arr[N];

double dot(Point a,Point b) {
	return a.x*b.x+a.y*b.y;
}

double cross(Point a,Point b) {
	return a.x*b.y-a.y*b.x;
}

double area(Point a,Point b,Point c) {
	return cross(b-a,c-a);
}

double dis(Point a,Point b) {
	double x=a.x-b.x;
	double y=a.y-b.y;
	return sqrt(x*x+y*y);
}

double solve() {
	_rep(i,1,n) {
		if (i!=1 && arr[i]==arr[i-1]) {
			flag[i]=true;
			continue;
		}
		while (hh>=2 && sign(area(arr[stk[hh-1]],arr[stk[hh]],arr[i]))>0) flag[stk[hh--]]=false;
		stk[++hh]=i;
		flag[i]=true;
	}
	flag[1]=false;
	_rrep(i,n,1) {
		if (flag[i]) continue;
		if (i!=n && arr[i]==arr[i+1]) {
			flag[i]=true;
			continue;
		}
		while (hh>=2 && sign(area(arr[stk[hh-1]],arr[stk[hh]],arr[i]))>0) flag[stk[hh--]]=false;
		stk[++hh]=i;
		flag[i]=true;
	}
	double ans=0.0;
	_rep(i,1,hh-1) ans+=dis(arr[stk[i]],arr[stk[i+1]]);
	ans+=pi*l*2.0;
	return ans;
}

int main() {
	read(n),read(l);
	_rep(i,1,n) read(arr[i].x),read(arr[i].y);
	sort(arr+1,arr+1+n);
	printf("%.0lf",solve());
	return 0;
}