#include <bits/stdc++.h>
using namespace std;

#define int i128

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

const int N=100005;
const int M=35;

int n,m,idx=1;
int root=1;

struct Seg {
	int l,r,sum,add;
} tr[N*M<<2];

void pushup(int u) {
	tr[u].sum=tr[tr[u].l].sum+tr[tr[u].r].sum;
}

void pushdown(int u,int l,int r) {
	if (tr[u].add) {
		if (!tr[u].l) tr[u].l=++idx;
		if (!tr[u].r) tr[u].r=++idx;
		auto &root=tr[u],&left=tr[tr[u].l],&right=tr[tr[u].r];
		left.add+=root.add;
		right.add+=root.add;
		int mid=l+r>>1;
		left.sum+=(mid-l+1)*root.add;
		right.sum+=(r-mid)*root.add;
		root.add=0;
	}
}

void modify(int u,int l,int r,int L,int R,int k) {
	if (l>=L && r<=R) {
		tr[u].add+=k;
		tr[u].sum+=(r-l+1)*k;
	} else {
		if (!tr[u].l) tr[u].l=++idx;
		if (!tr[u].r) tr[u].r=++idx;
		pushdown(u,l,r);
		int mid=l+r>>1;
		if (L<=mid) modify(tr[u].l,l,mid,L,R,k);
		if (R>mid) modify(tr[u].r,mid+1,r,L,R,k);
		pushup(u);
	}
}

int query(int u,int l,int r,int L,int R) {
	if (!u) return 0;
	if (l>=L && r<=R) return tr[u].sum;
	if (!tr[u].l) tr[u].l=++idx;
	if (!tr[u].r) tr[u].r=++idx;
	pushdown(u,l,r);
	int mid=l+r>>1;
	int ans=0;
	if (L<=mid) ans+=query(tr[u].l,l,mid,L,R);
	if (R>mid) ans+=query(tr[u].r,mid+1,r,L,R);
	return ans;
}

i32 main() {
	read(n),read(m);
	while (m--) {
		int op,l,r;
		read(op),read(l),read(r);
		if (op==1) {
			int k;
			read(k);
			modify(root,1,1e9,l,r,k);
		} else {
			writeln(query(root,1,1e9,l,r)+(l+r)*(r-l+1)/2);
		}
	}
	return 0;
}
