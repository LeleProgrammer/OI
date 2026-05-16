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

const int N=4000005;

int n,q;
int c[N];

struct Seg {
    int l,r,L,R,self;
    int cnt[2];
    int fau[2];
    int ava[2];
    int ans[2];
    int rev;
    void init() {
        l=r=L=R=self=cnt[0]=cnt[1]=fau[0]=fau[1]=ava[0]=ava[1]=ans[0]=ans[1]=rev=0;
    }
    void init(int l,int r,int L,int R,int self) {
        this->l=l;
        this->r=r;
        this->L=L;
        this->R=R;
        this->self=self;
        cnt[0]=cnt[1]=fau[0]=fau[1]=ava[0]=ava[1]=ans[0]=ans[1]=rev=0;
    }
} tr[N<<2];

void pushup(Seg& u,Seg& l,Seg& r) {
    _rep(i,0,1) {
        u.cnt[i]=l.cnt[i]+r.cnt[i];
        u.fau[i]=l.fau[i]+max(r.fau[i]-l.ava[i],0);
        u.ava[i]=r.ava[i]+max(l.ava[i]-r.fau[i],0);
        if (l.ava[i]<=r.fau[i]) {
            int v=l.self,k=l.fau[i],posL=-1;
            while (v) {
                if (tr[v].l==tr[v].r) {
                    posL=tr[v].l;
                    break;
                }
                if (tr[tr[v].L].fau[i]>=k) v=tr[v].L;
                else k-=tr[tr[v].L].fau[i],v=tr[v].R;
            }
            int posR=-1;
            if (l.ava[i]==r.fau[i]) posR=r.r+1;
            else {
                v=r.self,k=l.ava[i]+1;
                while (v) {
                    if (tr[v].l==tr[v].r) {
                        posR=tr[v].l;
                        break;
                    }
                    if (tr[tr[v].L].fau[i]>=k) v=tr[v].L;
                    else k-=tr[tr[v].L].fau[i],v=tr[v].R;
                }
            }
            u.ans[i]=R-L-1;
        } else {
            int v=l.self,k=(l.r-l.l+1)-r.fau[i]+1-1,posL=-1,posR=r.r+1;
            while (v) {
                if (tr[v].l==tr[v].r) {
                    posL=tr[v].l;
                    break;
                }
                if (tr[tr[v].L].ava[i]>=k) v=tr[v].L;
                else k-=tr[tr[v].L].ava[i],v=tr[v].R;
            }
            u.ans[i]=R-L-1;
        }
        u.ans[i]=max(max(u.ans[i],l.ans[i]),r.ans[i]);
    }
}

void pushup(int u) {
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}

void pushrev(int u) {
    tr[u].rev^=1;
    swap(tr[u].cnt[0],tr[u].cnt[1]);
    swap(tr[u].fau[0],tr[u].fau[1]);
    swap(tr[u].ava[0],tr[u].ava[1]);
    swap(tr[u].ans[0],tr[u].ans[1]);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.rev) {
        pushrev(left);
        pushrev(right);
        root.rev^=1;
    }
}

void build(int u,int l,int r) {
    tr[u].init(l,r,u<<1,u<<1|1,u);
    if (l==r) {
        cnt[c[l]]=1;
        fau[c[l]^1]=1;
        ava[c[l]]=1;
        return;
    }
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) pushrev(u);
    else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r);
        if (r>mid) modify(u<<1|1,l,r);
        pushup(u);
    }
}

Seg query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if (l<=mid && r>mid) {
        Seg ans,L,R;
        ans.init();
        L=query(u<<1,l,r);
    }
}

int main() {
    read(n),read(q);
    _rep(i,1,n) read(c[i]);
    while (q--) {
        ;
    }
}