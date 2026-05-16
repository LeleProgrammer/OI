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
        while (isdigit(c)) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x[idx++]=c,c=getchar();
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
    inline void writestr(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=1594327; // 3^13 + 5
const int M=15;

int n;
int p[M];
int a[N];
unordered_map<int,int> sta,f;

void init() {
    p[0]=1;
    _rep(i,1,M-1) p[i]=p[i-1]*3;
}

int min3(int a,int b,int c) {
    return min(min(a,b),c);
}

void dfs(int u,int l,int r) {
    if (l==r) {
        sta[u]=a[l];
        f[u]=1;
        return;
    }
    int len=(r-l+1)/3;
    dfs(u*3-1,l,l+len-1);
    dfs(u*3,l+len,l+len+len-1);
    dfs(u*3+1,l+len+len,r);
    vector<int> cnt[2];
    cnt[sta[u*3-1]].emplace_back(u*3-1);
    cnt[sta[u*3]].emplace_back(u*3);
    cnt[sta[u*3+1]].emplace_back(u*3+1);
    if (cnt[0].size()>cnt[1].size()) sta[u]=0;
    else sta[u]=1;
    if ((int)cnt[0].size()==3) f[u]=min3(f[cnt[0][0]]+f[cnt[0][1]],f[cnt[0][0]]+f[cnt[0][2]],f[cnt[0][1]]+f[cnt[0][2]]);
    else if ((int)cnt[1].size()==3) f[u]=min3(f[cnt[1][0]]+f[cnt[1][1]],f[cnt[1][0]]+f[cnt[1][2]],f[cnt[1][1]]+f[cnt[1][2]]);
    else if ((int)cnt[0].size()==2) f[u]=min(f[cnt[0][0]],f[cnt[0][1]]);
    else if ((int)cnt[1].size()==2) f[u]=min(f[cnt[1][0]],f[cnt[1][1]]);
    else assert(false);
}

int main() {
    init();
    read(n);
    _rep(i,1,p[n]) scanf("%1d",&a[i]);
    dfs(1,1,p[n]);
    write(f[1]);
    return 0;
}