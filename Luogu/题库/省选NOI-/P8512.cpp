#include <bits/stdc++.h>
using namespace std;

#define int long long

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

const int N=500005;

int n,m,q;
int l[N],r[N],v[N];
map<int,pii> s;
int ans[N];
int tr[N];

struct node {
	int l,r,i;
	friend bool operator < (const node& a,const node& b) {
		return a.r<b.r;
	}
} arr[N];

int lowbit(int x) {
	return x&-x;
}

void modify(int x,int k) {
	while (x<=N-1) tr[x]+=k,x+=lowbit(x);
}

int query(int x) {
	int ans=0;
	while (x) ans+=tr[x],x-=lowbit(x);
	return ans;
}

void split(int x) {
	auto it=prev(s.upper_bound(x));
	s[x]=it->second;
}

void assign(int l,int r,int i,int v) {
	r++;
	split(l),split(r);
	auto it=s.find(l);
	while (it->first!=r) {
		int k=next(it)->first;
		modify(it->second.first+1,-(k-it->first)*it->second.second);
		it=s.erase(it);
	}
	s[l]={i,v};
	modify(i+1,(r-l)*v);
}

void init() {
	s[1]={0,0},s[m+1]={0,0};
}

i32 main() {
	init();
	read(n),read(m),read(q);
	_rep(i,1,n) read(l[i]),read(r[i]),read(v[i]);
	_rep(i,1,q) read(arr[i].l),read(arr[i].r),arr[i].i=i;
	sort(arr+1,arr+1+q);
	int cur=1;
	_rep(i,1,q) {
		while (cur<=arr[i].r) assign(l[cur],r[cur],cur,v[cur]),cur++;
		ans[arr[i].i]=query(N-1)-query(arr[i].l);
	}
	_rep(i,1,q) writeln(ans[i]);
	return 0;
}