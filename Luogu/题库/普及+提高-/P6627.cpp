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

const int N=400005;
const int inf=1e9;

int n;
vector<int> nums;
int cf[N];

struct node {
    int t;
    vector<int> p;
} arr[N];

void process(int& k) {
    k=lower_bound(nums.begin(),nums.end(),k)-nums.begin()+1;
}

int main() {
    read(n);
    _rep(i,1,n) {
        int t;
        read(t);
        arr[i].t=t;
        if (t==1) {
            int l,r,w;
            read(l),read(r),read(w);
            arr[i].p.emplace_back(l),arr[i].p.emplace_back(r),arr[i].p.emplace_back(w);
            nums.emplace_back(l),nums.emplace_back(r),nums.emplace_back(l-1),nums.emplace_back(r+1);
        } else if (t==2) {
            int a,w;
            read(a),read(w);
            arr[i].p.emplace_back(a),arr[i].p.emplace_back(w);
            nums.emplace_back(a),nums.emplace_back(a+1),nums.emplace_back(a-1);
        } else {
            int b,w;
            read(b),read(w);
            arr[i].p.emplace_back(b),arr[i].p.emplace_back(w);
            nums.emplace_back(b),nums.emplace_back(b+1),nums.emplace_back(b-1);
        }
    }
    nums.emplace_back(0);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    _rep(i,1,n) {
        int t=arr[i].t;
        if (t==1) process(arr[i].p[0]),process(arr[i].p[1]);
        else process(arr[i].p[0]);
    }
    _rep(i,1,n) {
        int t=arr[i].t;
        if (t==1) {
            int l=arr[i].p[0],r=arr[i].p[1],w=arr[i].p[2];
            cf[l]^=w,cf[r+1]^=w;
        } else if (t==2) {
            int a=arr[i].p[0],w=arr[i].p[1];
            cf[a]^=w,cf[a+1]^=w;
        } else {
            int b=arr[i].p[0],w=arr[i].p[1];
            cf[1]^=w,cf[b]^=w,cf[b+1]^=w;
        }
    }
    int cur=0,ans=0,num=-inf;
    _rep(i,1,(int)nums.size()) {
        cur^=cf[i];
        if (cur>ans) ans=cur,num=nums[i-1];
        else if (cur==ans && abs(nums[i-1])<abs(num)) num=nums[i-1];
    }
    writesp(ans),write(num);
    return 0;
}