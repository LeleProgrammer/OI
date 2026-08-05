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
    inline void writestr(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); }
    inline void writestrsp(string x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(' '); }
    inline void writestrln(string x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=100005;
const int inf=2e9;

int T,n,m;
int l[N],r[N];
vector<pii> vec[N];

int calc(int n) {
    return n*(n+1)/2;
}

bool cmp(const pii& a,const pii& b) {
    return a.first<b.first;
}

i32 main() {
    read(T);
    while (T--) {
        read(n),read(m);
        _rep(i,1,n) l[i]=0,r[i]=inf,vec[i].clear();
        bool ok=true;
        while (m--) {
            int x,y,k,p;
            read(x),read(y),read(k),read(p);
            assert(p!=0);
            if (k==calc(n)) l[x]=max(l[x],y-p),r[x]=min(r[x],y+p);
            else if (k==calc(x-1)+calc(n-x)) vec[x].emplace_back(pii{y-p,y+p});
            else ok=false;
        }
        _rep(i,1,n) sort(vec[i].begin(),vec[i].end());
        _rep(i,1,n) {
            _iter(it,vec[i]) {
                int L=it->first,R=it->second;
                if (R<l[i]) continue;
                else if (L>l[i]) break;
                l[i]=R+1;
            }
            if (l[i]>r[i]) {
                ok=false;
                break;
            }
        }
        if (!ok) {
            puts("-1");
            continue;
        }
        _rep(i,1,n) writesp(l[i]);
        putchar(10);
    }
    return 0;
}