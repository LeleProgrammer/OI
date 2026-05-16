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
typedef pair<int,pdd> pidd;
typedef pair<double,int> pdi;

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

const int N=405;
const int M=1000005;
const double inf=1e9;

int T,n,t,A,B;
int e[M],ne[M],h[N],tot;
vector<pidd> his;
double w[M];
double dis[N];
bool flag[N];
priority_queue<pdi,vector<pdi>,greater<pdi>> q;

struct node {
	double x1,y1,x2,y2,x3,y3,tt;
} arr[N];

void add(int a,int b,double c) {
	e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

double getDis(int x1,int y1,int x2,int y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void dijkstra() {
	_rep(i,1,N-1) dis[i]=inf,flag[i]=false;
	q.emplace(pdi{dis[A]=0,A});
	q.emplace(pdi{dis[A+n]=0,A+n});
	q.emplace(pdi{dis[A+n*2]=0,A+n*2});
	q.emplace(pdi{dis[A+n*3]=0,A+n*3});
	while (!q.empty()) {
		auto tp=q.top(); q.pop();
		int u=tp.second;
		if (flag[u]) continue;
		flag[u]=true;
		_graph(i,u) if (dis[e[i]]>dis[u]+w[i]) q.emplace(pdi{dis[e[i]]=dis[u]+w[i],e[i]});
	}
}

pdd calc(double x1,double y1,double x2,double y2,double x3,double y3) {
	double d1=getDis(x1,y1,x2,y2);
	double d2=getDis(x2,y2,x3,y3);
	double d3=getDis(x3,y3,x1,y1);
	double xm,ym;
	if (d1>d2 && d1>d3) {
		xm=(x1+x2)/2,ym=(y1+y2)/2;
		return {(xm*2-x3),(ym*2-y3)};
	} else if (d2>d1 && d2>d3) {
		xm=(x3+x2)/2,ym=(y3+y2)/2;
		return {(xm*2-x1),(ym*2-y1)};
	} else {
		xm=(x1+x3)/2,ym=(y1+y3)/2;
		return {(xm*2-x2),(ym*2-y2)};
	}
}

int main() {
	read(T);
	while (T--) {
		memset(h,-1,sizeof(h)),tot=0,his.clear();
		read(n),read(t),read(A),read(B);
		_rep(i,1,n) {
			double x1,y1,x2,y2,x3,y3,tt;
			read(x1),read(y1),read(x2),read(y2),read(x3),read(y3),read(tt);
			arr[i]={x1,y1,x2,y2,x3,y3,tt};
		}
		_rep(i,1,n) {
			int x1,y1,x2,y2,x3,y3,tt,x4,y4;
			x1=arr[i].x1,y1=arr[i].y1,x2=arr[i].x2,y2=arr[i].y2;
			x3=arr[i].x3,y3=arr[i].y3,tt=arr[i].tt;
			auto g=calc(x1,y1,x2,y2,x3,y3);
			x4=g.first,y4=g.second;
			vector<pii> vec;
			vec.emplace_back(pii{x1,y1});
			vec.emplace_back(pii{x2,y2});
			vec.emplace_back(pii{x3,y3});
			vec.emplace_back(pii{x4,y4});
			_rep(j,0,3) _rep(k,0,3) {
				if (j==k) continue;
				add(i+j*n,i+k*n,getDis(vec[j].first,vec[j].second,vec[k].first,vec[k].second)*tt);
//				cout<<"test "<<i<<": "<<getDis(vec[j].first,vec[j].second,vec[k].first,vec[k].second)*tt<<endl;
			}
			_iter(it,his) {
				int u=it->first,x=it->second.first,y=it->second.second;
				_rep(j,0,3) {
					add(i+j*n,u,getDis(vec[j].first,vec[j].second,x,y)*t);
					add(u,i+j*n,getDis(vec[j].first,vec[j].second,x,y)*t);
				}
			}
			_rep(j,0,3) his.emplace_back(piii{i+j*n,vec[j]});
		}
		dijkstra();
		double ans=inf;
		_rep(i,0,3) ans=min(ans,dis[B+i*n]);
//		_rep(i,1,n*4) printf("dis[%d] = %lf\n",i,dis[i]);
		printf("%.1lf\n",ans);
	}
	return 0;
}

