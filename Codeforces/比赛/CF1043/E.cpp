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

const int N=400005;

int T,n,m,q;
int a[N],b[N];
int pa[N],pb[N];
pii arr[N];
int idx,sum[N];

bool cmp(const int& a,const int& b) {
    return a>b;
}

i32 main() {
    read(T);
    while (T--) {
        read(n),read(m),read(q),idx=0;
        _rep(i,1,n) read(a[i]); sort(a+1,a+1+n,cmp);
        _rep(i,1,n) pa[i]=pa[i-1]+a[i];
        _rep(i,1,m) read(b[i]); sort(b+1,b+1+m,cmp);
        _rep(i,1,m) pb[i]=pb[i-1]+b[i];
        arr[++idx]=pii{0,0};
        int i=0,j=0,cur=0;
        while (i+1<=n && j+1<=m) {
            if (a[i+1]>b[j+1]) arr[idx+1]={i+1,j},sum[idx+1]=cur+a[i+1],cur+=a[i+1],i++,idx++;
            else arr[idx+1]={i,j+1},sum[idx+1]=cur+b[j+1],cur+=b[j+1],j++,idx++;
        }
        while (i+1<=n) arr[idx+1]={i+1,j},sum[idx+1]=cur+a[i+1],cur+=a[i+1],i++,idx++;
        while (j+1<=m) arr[idx+1]={i,j+1},sum[idx+1]=cur+b[j+1],cur+=b[j+1],j++,idx++;
        // _rep(i,1,idx) {
        //     cout<<"idx: ";
        //     printf("[%lld, %lld]: %lld\n",arr[i].first,arr[i].second,sum[i]);
        // }
        while (q--) {
            int x,y,z;
            read(x),read(y),read(z);
            int l=1,r=idx;
            while (l<r) {
                int mid=(l+r>>1)+1;
                if (arr[mid].first<=x && arr[mid].second<=y && arr[mid].first+arr[mid].second<=z) l=mid;
                else r=mid-1;
            }
            int rem=z-(arr[l].first+arr[l].second);
            int i=arr[l].first,j=arr[l].second;
            int ans=sum[l];
            // cout<<"test: "<<i<<" "<<j<<endl;
            // assert((i+1<=x)^(j+1<=y) || (i+j==z));
            // while (rem && i+1<=x) ans+=a[++i],rem--;
            // while (rem && j+1<=y) ans+=b[++j],rem--;
            // writeln(ans);
            // continue;
            // cout<<"cur: "<<ans<<endl;
            int g;
            g=min(x-i,rem);
            ans+=pa[i+g]-pa[i],rem-=g;
            g=min(y-j,rem);
            ans+=pb[j+g]-pb[j],rem-=g;
            writeln(ans);
        }
    }
    return 0;
}