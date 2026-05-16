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
    inline void writestr(string x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=1000005;
const int M=2000005;

int n,L,R;
int e[M],ne[M],h[N],tot;
bool flag[N];
int d[N],arr[N],pre[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

int gsz(int u,int fa) {
    if (flag[u]) return 0;
    int sz=1;
    _graph(i,u) if (e[i]!=fa) sz+=gsz(e[i],u);
    return sz;
}

int gce(int u,int fa,int sz,int& ce) {
    if (flag[u]) return 0;
    int mx=0,s=1;
    _graph(i,u) if (e[i]!=fa) {
        int k=gce(e[i],u,sz,ce);
        s+=k;
        mx=max(mx,k);
    }
    mx=max(mx,sz-s);
    if (mx<=sz/2) ce=u;
    return s;
}

void gdis(int u,int fa,int dis,int& cnt) {
    if (flag[u]) return;
    d[++cnt]=dis;
    _graph(i,u) if (e[i]!=fa) gdis(e[i],u,dis+1,cnt);
}

int calc(int* arr,int n,int k) {
    int ans=0;
    sort(arr+1,arr+1+n);
    _rep(i,1,n) pre[i]=pre[i-1]+arr[i];
    int l=0,r=n;
    while (r>=1) {
        while (l+1<=r && arr[l+1]+arr[r]<=k) ++l;
        l=min(l,r-1);
        ans+=pre[l]+l*arr[r];
        r--;
    }
    return ans;
}

int solve(int u,int k) {
    if (flag[u]) return 0;
    gce(u,0,gsz(u,0),u);
    flag[u]=true;
    int ans=0,n=0;
    _graph(i,u) {
        int m=0; gdis(e[i],u,1,m);
        ans-=calc(d,m,k);
        _rep(j,1,m) {
            if (d[j]<=k) ans+=d[j];
            arr[++n]=d[j];
        }
    }
    ans+=calc(arr,n,k);
    _graph(i,u) ans+=solve(e[i],k);
    return ans;
}

i32 main() {
    memset(h,-1,sizeof(h));
    read(n),read(L),read(R);
    _rep(i,2,n) {
        int p;
        read(p);
        add(p,i),add(i,p);
    }
    int ansl=solve(1,L-1);
    memset(flag,0,sizeof(flag));
    int ansr=solve(1,R);
    write(ansr-ansl);
    return 0;
}