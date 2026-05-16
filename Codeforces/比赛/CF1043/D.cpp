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

const int N=18;

int T,k;
int sum[N],len[N],cnt[N],pre[N];

int ksm(int a,int b) {
    if (!b) return 1;
    int k=ksm(a,b>>1);
    if (b&1) return k*k*a;
    else return k*k;
}

void init() {
    _rep(i,1,N-1) cnt[i]=(ksm(10,i)-ksm(10,i-1)); cnt[0]=1;
    _rep(i,1,N-1) len[i]=cnt[i]*i;
}

int calc(int p,int q) {
    vector<int> vec;
    while (p) vec.emplace_back(p%10),p/=10;
    int ans=0;
    while (q--) ans+=vec.back(),vec.pop_back();
    return ans;
}

vector<int> vec;
pii f[N][N];

pii dfs(int pos,bool lmt) {
    if (!pos) return pii{1,0};
    if (~f[pos][lmt].first) return f[pos][lmt];
    int cnt=0,sum=0;
    int mx=lmt?vec[pos]:9;
    _rep(i,0,mx) {
        auto ret=dfs(pos-1,lmt && i==mx);
        cnt+=ret.first;
        sum+=i*ret.first+ret.second;
    }
    return f[pos][lmt]=pii{cnt,sum};
}

int solve(int k) {
    // cout<<"solve: "<<k<<endl;
    vec.clear();
    vec.emplace_back(-1);
    while (k) vec.emplace_back(k%10),k/=10;
    return dfs((int)vec.size()-1,true).second;
}

i32 main() {
    init();
    read(T);
    while (T--) {
        memset(f,-1,sizeof(f));
        read(k);
        int ans=0;
        _rep(i,1,N-1) {
            if (k>=len[i]) {
                k-=len[i];
            } else {
                int p=k/i;
                int q=k%i;
                ans+=calc(ksm(10,i-1)+p,q);
                // cout<<"pq: "<<p<<" "<<q<<endl;
                // cout<<"now: "<<ans<<endl;
                ans+=solve(p-1+ksm(10,i-1));
                break;
            }
        }
        writeln(ans);
    }
    return 0;
}

/*
12345678910111213141516171819
*/