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

const int N=1300005;
const int M=1000005;
const int inf=1e9;

int n,m,cur=1;
int tr[M];
int ans[N],idx;

struct node {
	int t,x,y,i,op;
	friend bool operator < (const node& a,const node& b) {
		if (a.t!=b.t) return a.t<b.t;
		if (a.x!=b.x) return a.x<b.x;
		return a.y<b.y;
	}
} arr[N],st[N];

int lowbit(int x) {
	return x&-x;
}

void modify(int x,int k) {
	while (x<=M-1) tr[x]=max(tr[x],k),x+=lowbit(x);
}

void restore(int x) {
	while (x<=M-1) tr[x]=-inf,x+=lowbit(x);
}

int query(int x) {
	int ans=-inf;
	while (x) ans=max(ans,tr[x]),x-=lowbit(x);
	return ans;
}

void merge(int l,int r) {
	if (l==r) return;
	int mid=l+r>>1;
	merge(l,mid),merge(mid+1,r);
	int i=l,j=mid+1,g=l;
	while (i<=mid && j<=r) {
		if (arr[i].x<=arr[j].x) {
			if (arr[i].op==1) modify(arr[i].y,arr[i].y+arr[i].x);
			st[g++]=arr[i++];
		} else {
			if (arr[j].op==2) ans[arr[j].i]=min(ans[arr[j].i],arr[j].x+arr[j].y-query(arr[j].y));
			st[g++]=arr[j++];
		}
	}
	while (i<=mid) {
		if (arr[i].op==1) modify(arr[i].y,arr[i].y+arr[i].x);
		st[g++]=arr[i++];
	}
	while (j<=r) {
		if (arr[j].op==2) ans[arr[j].i]=min(ans[arr[j].i],arr[j].x+arr[j].y-query(arr[j].y));
		st[g++]=arr[j++];
	}
	_rep(i,l,mid) if (arr[i].op==1) restore(arr[i].y);
	_rep(i,l,r) arr[i]=st[i];
}

int main() {
	read(n),read(m);
	_rep(i,1,n) read(arr[i].x),read(arr[i].y),arr[i].x++,arr[i].y++,arr[i].t=cur,arr[i].op=1;
	_rep(i,1,M-1) tr[i]=-inf;
	_rep(i,1,m) {
		int t,x,y;
		read(t),read(x),read(y);
		x++,y++;
		arr[n+i]={cur,x,y,t==2?++idx:0,t};
		if (t==2) cur++;
	}
	_rep(i,1,m) ans[i]=inf;
	_rep(g,1,4) {
		sort(arr+1,arr+1+n+m);
		merge(1,n+m);
		_rep(i,1,n+m) arr[i]={arr[i].t,(int)1e6+1-arr[i].y+1,arr[i].x,arr[i].i,arr[i].op};
	}
	sort(arr+1,arr+1+n+m);
	_rep(i,1,idx) writeln(ans[i]);
	return 0;
}

/*
1,1 1,2 1,3 1,4 ... 1,m
2,1 2,2 2,3 2,4 ... 2,m
...
n,1 n,2 n,3 n,4 ... n,m

n,1 n-1,1 n-2,1 ... 1,1
n,2 n-1,2 n-2,2 ... 1,2
...
n,m n-1,m n-2,m ... 1,m
*/