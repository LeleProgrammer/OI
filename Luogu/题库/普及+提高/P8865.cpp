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

const int N=1005;
const int mod=998244353;

int T,id;
int n,m,c,f;
char arr[N][N];
int s[N][N];

i32 main() {
    // FRR("P8865_2.in");
    // FRW("P8865_2.out");
    read(T),read(id);
    while (T--) {
        memset(s,0,sizeof(s));
        read(n),read(m),read(c),read(f);
        _rep(i,1,n) readstr(arr[i]+1);
        _rep(i,1,n) _rep(j,1,m) arr[i][j]=((arr[i][j]-'0')^1);
        _rep(i,1,n) {
            _rrep(j,m,1) {
                if (!arr[i][j]) continue;
                int k;
                _rrep(p,j-1,0) if (!arr[i][p] || !p) {
                    k=p+1;
                    break;
                }
                _rep(p,k,j) s[i][p]=j-p;
                j=k;
            }
        }
        // cout<<"test: "<<endl;
        // _rep(i,1,n) {
        //     _rep(j,1,m) writesp(s[i][j]);
        //     putchar(10);
        // }
        int ansc=0,ansf=0;
        _rep(j,1,m) {
            _rep(i,1,n) {
                if (!arr[i][j]) continue;
                int k;
                _rep(p,i+1,n+1) if (!arr[p][j] || p==n+1) {
                    k=p-1;
                    break;
                }
                int cur=0,las=0;
                _rep(p,i,k) {
                    if (s[p][j]) {
                        // cout<<"test: "<<p<<" "<<j<<": "<<cur<<" "<<las<<endl;
                        ansc=(ansc+s[p][j]*cur)%mod;
                        ansf=(ansf+(s[p][j]*cur%mod)*(k-p))%mod;
                        if (!cur && las) cur=las;
                        else cur=(cur+las)%mod;
                        las=s[p][j];
                        // cout<<"now: "<<ansc<<" "<<ansf<<endl;
                    } else if (cur) cur=(cur+las)%mod,las=0;
                    else if (las) cur=las,las=0;
                }
                i=k;
            }
        }
        ansc=ansc*c%mod;
        ansf=ansf*f%mod;
        writesp(ansc),writeln(ansf);
    }
    return 0;
}