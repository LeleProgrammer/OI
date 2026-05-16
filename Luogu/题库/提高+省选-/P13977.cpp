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

int n,len,nn;
int a[N];
int b[N];
int tag[N];
int L[N],R[N],B[N],BL[N],BR[N];
int p[N],q[N],pp,qq;

void pushdown(int x) {
    _rep(i,BL[x],BR[x]) a[i]+=tag[x];
    tag[x]=0;
}

void modify_block(int l,int r,int c) {
    assert(B[l]==B[r]);
    pushdown(B[l]);
    pp=0,qq=0;
    _rep(i,l,r) a[i]+=c;
    _rep(i,L[l],R[l]) if (b[i]>=l && b[i]<=r) p[++pp]=b[i]; else q[++qq]=b[i];
    int i=1,j=1,cur=L[l];
    while (i<=pp && j<=qq) {
        if (a[p[i]]<a[q[j]]) b[cur++]=p[i++];
        else b[cur++]=q[j++];
    }
    while (i<=pp) b[cur++]=p[i++];
    while (j<=qq) b[cur++]=q[j++];
}

void modify(int l,int r,int c) {
    if (B[l]==B[r]) modify_block(l,r,c);
    else {
        modify_block(l,R[l],c),modify_block(L[r],r,c);
        _rep(i,B[l]+1,B[r]-1) tag[i]+=c;
    }
}

int query(int l,int r,int c) {
    if (B[l]==B[r]) {
        pushdown(B[l]);
        int ans=0;
        _rep(i,l,r) if (a[i]<c) ans++;
        return ans;
    } else {
        pushdown(B[l]),pushdown(B[r]);
        int ans=0;
        _rep(i,l,R[l]) if (a[i]<c) ans++;
        _rep(i,L[r],r) if (a[i]<c) ans++;
        _rep(i,B[l]+1,B[r]-1) {
            int pos=lower_bound(b+BL[i],b+BR[i]+1,c-tag[i],[&](int x,int y) {
                return a[x]<y;
            })-b-1; // 这里不要拿值直接去和 b 数组里面的下标比较
            ans+=(pos-BL[i]+1);
        }
        return ans;
    }
}

bool cmp(const int& p,const int& q) {
    return a[p]<a[q];
}

i32 main() {
    read(n),len=sqrt(n);
    _rep(i,1,n) read(a[i]),b[i]=i;
    _rep(i,1,n) B[i]=i/len+1; nn=B[n];
    _rep(i,1,n) if (B[i]==B[i-1]) L[i]=L[i-1]; else L[i]=i;
    _rrep(i,n,1) if (B[i]==B[i+1]) R[i]=R[i+1]; else R[i]=i;
    _rep(i,1,n) BL[B[i]]=L[i],BR[B[i]]=R[i];
    _rep(i,1,nn) sort(b+BL[i],b+BR[i]+1,cmp);
    _rep(i,1,n) {
        int op,l,r,c;
        read(op),read(l),read(r),read(c);
        if (!op) modify(l,r,c);
        else writeln(query(l,r,c*c));
    }
    return 0;
}