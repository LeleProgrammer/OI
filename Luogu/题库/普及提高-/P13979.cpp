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

const int N=300005;
const int inf=1e18;

int n,len,nn;
int a[N],sum[N];
int L[N],R[N],B[N],BL[N],BR[N];
int tag[N];

void pushdown(int x) {
    _rep(i,BL[x],BR[x]) a[i]+=tag[x];
    tag[x]=0;
}

void modify(int l,int r,int c) {
    if (B[l]==B[r]) {
        pushdown(B[l]);
        _rep(i,l,r) a[i]+=c,sum[B[l]]+=c;
    } else {
        pushdown(B[l]),pushdown(B[r]);
        _rep(i,l,R[l]) a[i]+=c,sum[B[l]]+=c;
        _rep(i,L[r],r) a[i]+=c,sum[B[r]]+=c;
        _rep(i,B[l]+1,B[r]-1) tag[i]+=c,sum[i]+=(BR[i]-BL[i]+1)*c;
    }
}

int query(int l,int r) {
    if (B[l]==B[r]) {
        pushdown(B[l]);
        int ans=0;
        _rep(i,l,r) ans+=a[i];
        return ans;
    } else {
        pushdown(B[l]),pushdown(B[r]);
        int ans=0;
        _rep(i,l,R[l]) ans+=a[i];
        _rep(i,L[r],r) ans+=a[i];
        _rep(i,B[l]+1,B[r]-1) ans+=sum[i];
        return ans;
    }
}

i32 main() {
    read(n),len=sqrt(n);
    _rep(i,1,n) read(a[i]);
    _rep(i,1,n) B[i]=i/len+1; nn=B[n];
    _rep(i,1,n) if (B[i]==B[i-1]) L[i]=L[i-1]; else L[i]=i;
    _rrep(i,n,1) if (B[i]==B[i+1]) R[i]=R[i+1]; else R[i]=i;
    _rep(i,1,n) BL[B[i]]=L[i],BR[B[i]]=R[i];
    _rep(i,1,n) sum[B[i]]+=a[i];
    _rep(i,1,n) {
        int op,l,r,c;
        read(op),read(l),read(r),read(c);
        if (!op) modify(l,r,c);
        else {
            int ans=query(l,r)%(c+1);
            ans=(ans+(c+1))%(c+1);
            writeln(ans);
        }
    }
    return 0;
}