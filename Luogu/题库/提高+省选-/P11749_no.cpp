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

const int N=24000055;
const int mod=998244353;

int T,m,n,k;
int p[N];
char in[N],s[N];

void init(int k) {
    readstr(in+1);
    s[++n]='$',s[++n]='#';
    _rep(j,1,k) _rep(i,1,m) s[++n]=in[i],s[++n]='#';
    s[++n]='^';
}

void manacher() {
    int mr=0,mid;
    _rep(i,1,n) {
        if (i<mr) p[i]=min(p[mid*2-i],mr-i);
        else p[i]=1;
        while (s[i-p[i]]==s[i+p[i]]) p[i]++;
        if (i+p[i]>mr) mr=i+p[i],mid=i;
    }
}

void restore() {
    _rep(i,1,n) p[i]=s[i]=in[i]=0;
}

i32 main() {
    read(T);
    while (T--) {
        read(m),read(k),n=0;
        init(min(k,4LL));
        manacher();
        int cnt1=0,cnt2=0,cnt3=0,cntmid=0;
        // _rep(i,2,2*m+2) cout<<p[i]<<" "; putchar(10);
        // _rep(i,2*m+3,4*m+2) cout<<p[i]<<" "; putchar(10);
        // _rep(i,4*m+3,n) cout<<p[i]<<" "; putchar(10);
        // _rep(i,2,2*m+2) cout<<i-p[i]+1<<" "; putchar(10);
        // _rep(i,2*m+3,4*m+2) cout<<i-p[i]+1<<" "; putchar(10);
        // _rep(i,4*m+3,n) cout<<i-p[i]+1<<" "; putchar(10);
        // cout<<"p: "; _rep(i,1,n) cout<<p[i]<<" "; putchar(10);
        _rep(i,2,2*m+2) cnt1+=p[i]/2;
        _rep(i,2*m+3,4*m+2) cnt2+=p[i]/2;
        _rep(i,4*m+3,6*m+2) cntmid+=p[i]/2;
        _rep(i,6*m+3,n) cnt3+=p[i]/2;
        cnt1%=mod,cnt2%=mod,cnt3%=mod;
        cout<<"TEST: "<<cnt1<<" "<<cnt2<<" "<<cntmid<<" "<<cnt3<<" "<<n<<endl;
        // _rep(i,2,2*m+2) cout<<p[i]/2<<" "; putchar(10);
        // _rep(i,3,n) cout<<p[i]/2<<" "; putchar(10);
        if (k<=4) {
            writeln((cnt1+cnt2+cntmid)%mod);
            restore();
            continue;
        }
        int ans=0;
        _rep(i,2*m+3,4*m+2) if (i-p[i]+1==2) {
            cout<<i<<": "<<ans<<" ";
            int x=k-5;
            ans=(ans+(x*(x+1)/2%mod)*m%mod)%mod;
            ans=(ans+min(m*(k-4),m*4-(i-2)))%mod;
            ans=(ans+min(m*(k-3),m*3-(i-2)))%mod;
            cout<<min(m*(k-3),m*4-(i-2))<<" ";
            cout<<min(m*(k-3),m*3-(i-2))<<" ";
            cout<<ans<<endl;
        }
        ans=(ans+cnt1)%mod;
        ans=(ans+cnt3)%mod;
        ans=(ans+cnt2*(k-2))%mod;
        writeln(ans);
        restore();
    }
    return 0;
}

/*
1
40 1
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

1
4 10
aaaa

ans: 820

1 1 2 2 3 3 4 4 = 20
5 5 6 6 7 7 8 8 = 52
9 9 10 10 11 11 12 12
13 13 14 14 15 15 16 16
17 17 18 18 19 19 20 20
20 19 19 18 18 17 17 16
16 15 15 14 14 13 13 12
12 11 11 10 10 9 9 8 ===
8 7 7 6 6 5 5 4 !!!
4 3 3 2 2 1 1 = 16

1
2 5
aa

1
10 1
aaaaaaaaaa

ans: 55

1 1 2 2 = 6
3 3 4 4 = 14
5 5 5 4 = 19
4 3 3 2 = 12
2 1 1 = 4

1
2 3
aa

1
6 1
aaaaaa

ans: 21

1 1 2 2 = 6
3 3 3 2 = 11
2 1 1 = 4

1
5 6
abaab

1
30 1
abaababaababaababaababaababaab

ans: 128

1 0 2 0 1 3 1 0 2 0 = 10
6 0 2 0 1 8 1 0 2 0 = 20
11 0 2 0 1 13 1 0 2 0 = 30
15 0 2 0 1 12 1 0 2 0 = 33
10 0 2 0 1 7 1 0 2 0 = 23
5 0 2 0 1 2 1 0 1 = 12
*/