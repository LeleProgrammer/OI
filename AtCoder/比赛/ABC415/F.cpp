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
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=500005;

int n,q;
char s[N];
int arr[N];

struct Seg {
    int l,r;
    int ln,mn,rn,lc,rc;
    void init(int l,int r) {
        ln=mn=rn=lc=rc=0;
        this->l=l,this->r=r;
    }
} tr[N<<2];

void pushup(Seg& u,Seg& l,Seg& r) {
    u.mn=max(l.mn,r.mn);
    if (l.rc==r.lc) u.mn=max(u.mn,l.rn+r.ln);
    u.lc=l.lc,u.rc=r.rc;
    if (l.ln==l.r-l.l+1 && r.lc==l.rc) u.ln=l.ln+r.ln;
    else u.ln=l.ln;
    if (r.rn==r.r-r.l+1 && r.lc==l.rc) u.rn=r.rn+l.rn;
    else u.rn=r.rn;
}

void pushup(int u) {
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
    // cout<<"test: "<<tr[u].l<<", "<<tr[u].r<<": ";
    // cout<<tr[u].ln<<" "<<tr[u].mn<<" "<<tr[u].rn<<" "<<tr[u].lc<<" "<<tr[u].rc<<endl;
}

void build(int u,int l,int r) {
    tr[u]={l,r,1,1,1,arr[l],arr[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
    // cout<<"test: "<<l<<", "<<r<<": ";
    // cout<<tr[u].ln<<" "<<tr[u].mn<<" "<<tr[u].rn<<" "<<tr[u].lc<<" "<<tr[u].rc<<endl;
}

void modify(int u,int p,int k) {
    if (tr[u].l==p && tr[u].r==p) {
        tr[u].ln=tr[u].rn=tr[u].mn=1;
        tr[u].lc=tr[u].rc=k;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (p<=mid) modify(u<<1,p,k);
        else modify(u<<1|1,p,k);
        pushup(u);
    }
}

Seg query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    Seg ans;
    ans.init(tr[u].l,tr[u].r);
    int mid=tr[u].l+tr[u].r>>1;
    Seg L,R;
    L.init(tr[u].l,mid);
    R.init(mid+1,tr[u].r);
    if (l<=mid) L=query(u<<1,l,r);
    if (r>mid) R=query(u<<1|1,l,r);
    pushup(ans,L,R);
    return ans;
}

int main() {
    read(n),read(q);
    readstr(s+1);
    _rep(i,1,n) arr[i]=s[i]-'a'+1;
    build(1,1,n);
    while (q--) {
        int op;
        read(op);
        if (op==1) {
            int i,x;
            char c;
            read(i),scanf(" %c",&c);
            x=c-'a'+1;
            modify(1,i,x);
        } else {
            int l,r;
            read(l),read(r);
            auto ans=query(1,l,r);
            writeln(max(max(ans.ln,ans.rn),ans.mn));
        }
    }
    return 0;
}

/*
baaaacczcc
*/