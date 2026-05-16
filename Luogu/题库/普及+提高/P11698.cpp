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

int f[N];
int num[N];

i64 dfs(int pos,int cnt,bool zero,bool lmt) {
    if (cnt>=2) return 0;
    if (!pos) {
        if (cnt!=1 || zero) return 0;
        else return 1;
    }
    if (!zero && !lmt) {
        if (!cnt) return f[pos];
        else return 1;
    }
    i64 res=0,mx=lmt?num[pos]:9;
    _rep(i,0,mx) {
        int nex=cnt;
        if (i!=0 && i!=1 && i!=2 && i!=3 && i!=5 && i!=7) nex+=2;
        else if (i!=0 && i!=1) nex++;
        else if (i==0 && !zero) nex+=2;
        res+=dfs(pos-1,nex,i==0 && zero,lmt && i==num[pos]);
    }
    return res;
}

void init() {
    _rep(i,1,N-1) f[i]=f[i-1]+4;
}

i64 solve(string s,bool flag) {
    reverse(s.begin(),s.end());
    int idx=0;
    _rep(i,0,(int)s.size()-1) num[++idx]=s[i]-'0';
    if (flag) {
        int t=1,cur=1;
        while (t) {
            num[cur]--,t=0;
            if (num[cur]<0) num[cur]+=10,t=1;
            cur++;
        }
    }
    i64 ans=dfs(idx,0,true,true);
    return ans;
}

int main() {
    init();
    string l,r;
    readstr(l),readstr(r);
    i64 L=solve(l,true),R=solve(r,false);
    write(R-L);
    return 0;
}