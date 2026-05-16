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

const int N=200005;

int n,q;

struct Seg {
	int l,r;
	int sum;
	int amx,bmx;
	int aadd,badd;
	int aset,bset;
} tr[N<<2];

void pushup(int u) {
	tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
	tr[u].amx=max(tr[u<<1].amx,tr[u<<1|1].amx);
	tr[u].bmx=max(tr[u<<1].bmx,tr[u<<1|1].bmx);
}

void pushdown(int u) {
	auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
	if (~root.aset) {
		left.aset=right.aset=root.aset;
		left.aadd=right.aadd=0;
		left.amx=right.amx=root.aset;
		root.aset=-1;
	}
	if (~root.bset) {
		left.bset=right.bset=root.bset;
		left.badd=right.badd=0;
		left.bmx=right.bmx=root.bset;
		root.bset=-1;
	}
	if (root.aadd) {
		left.amx+=root.aadd;
		right.amx+=root.aadd;
		left.aadd+=root.aadd;
		right.aadd+=root.aadd;
		root.aadd=0;
	}
	if (root.badd) {
		left.bmx+=root.badd;
		right.bmx+=root.badd;
		left.badd+=root.badd;
		right.badd+=root.badd;
		root.badd=0;
	}
}

void build(int u,int l,int r) {
	tr[u]={l,r,1,0,0,0,0,-1,-1};
	if (l==r) return;
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}

void adda(int u,int l,int r,int k) {
	if (tr[u].l>=l && tr[u].r<=r) {
		tr[u].aadd+=k;
		tr[u].amx+=k;
	} else {
		pushdown(u);
		int mid=tr[u].l+tr[u].r>>1;
		if (l<=mid) adda(u<<1,l,r,k);
		if (r>mid) adda(u<<1|1,l,r,k);
		pushup(u);
	}
}

void addb(int u,int l,int r,int k) {
	if (tr[u].l>=l && tr[u].r<=r) {
		tr[u].badd+=k;
		tr[u].bmx+=k;
	} else {
		pushdown(u);
		int mid=tr[u].l+tr[u].r>>1;
		if (l<=mid) addb(u<<1,l,r,k);
		if (r>mid) addb(u<<1|1,l,r,k);
		pushup(u);
	}
}

void seta(int u,int l,int r,int k) {
	if (tr[u].l>=l && tr[u].r<=r) {
		tr[u].aset=k;
		tr[u].aadd=0;
		tr[u].amx=k;
	} else {
		pushdown(u);
		int mid=tr[u].l+tr[u].r>>1;
		if (l<=mid) seta(u<<1,l,r,k);
		if (r>mid) seta(u<<1|1,l,r,k);
		pushup(u);
	}
}

void setb(int u,int l,int r,int k) {
	if (tr[u].l>=l && tr[u].r<=r) {
		tr[u].bset=k;
		tr[u].badd=0;
		tr[u].bmx=k;
	} else {
		pushdown(u);
		int mid=tr[u].l+tr[u].r>>1;
		if (l<=mid) setb(u<<1,l,r,k);
		if (r>mid) setb(u<<1|1,l,r,k);
		pushup(u);
	}
}

void destroy(int u,int l,int r,int k) {
	if (!tr[u].sum) return;
	if (tr[u].l==tr[u].r) {
		if (tr[u].amx>=k || tr[u].bmx>=k) tr[u].sum=0;
	} else {
		pushdown(u);
		int mid=tr[u].l+tr[u].r>>1;
		if (l<=mid && tr[u<<1].sum && (tr[u<<1].amx>=k || tr[u<<1].bmx>=k)) destroy(u<<1,l,r,k);
		if (r>mid && tr[u<<1|1].sum && (tr[u<<1|1].amx>=k || tr[u<<1|1].bmx>=k)) destroy(u<<1|1,l,r,k);
		pushup(u);
	}
}

i32 main() {
	read(n),read(q);
	build(1,1,n);
	while (q--) {
		int op;
		read(op);
		if (op==1) {
			int l,r,k;
			read(l),read(r),read(k);
			adda(1,l,r,k),setb(1,l,r,0);
			if (l>1) addb(1,1,l-1,k),seta(1,1,l-1,0);
			if (r<n) addb(1,r+1,n,k),seta(1,r+1,n,0);
		} else if (op==2) {
			int l,r,k;
			read(l),read(r),read(k);
			destroy(1,l,r,k);
		} else {
			writeln(tr[1].sum);
		}
	}
	return 0;
}