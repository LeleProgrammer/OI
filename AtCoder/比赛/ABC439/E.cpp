#include <bits/stdc++.h>
using namespace std;

const int MOD=998244353;
const int INF=2e9;

#define endl '\n'

#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define FRE(file) freopen(file,"w",stderr)

#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;

#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _riter(i,a) for (auto i=a.rbegin();i!=a.rend();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _dinic(i,u) for (int i=cur[u];~i && k<limit;i=ne[i])
#define _for(i,a) for (auto& i:a)

#define rint register int
#define LL long long
#define i32 signed
#define i64 long long
#define i128 __int128
#define u32 unsigned
#define u64 unsigned long long

#define _tostr(x) #x
#define _concat(a,b) a##b
#define _suf0(x) __builtin_ctzll(x)
#define _pre0(x) __builtin_clzll(x)
#define _popc(x) __builtin_popcountll(x)
#define _las1(x) __builtin_ffsll(x)
#define _sqrt(x) __builtin_sqrt(x)

#define _debug(x) cout<<#x<<": "<<x<<endl
#define __assert(c) \
    do { \
        if (!(c)) { \
            cerr<<"Assertion failed: " #c<<" at "<<__FILE__<<":"<<__LINE__<<endl; \
            abort(); \
        } \
    } while (0)

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<double,double> pdd;

class NullStream {
public:
    template<typename T> NullStream& operator << (const T&) { return *this; }
    inline NullStream& operator << (ostream& (*)(ostream&)) { return *this; }
    inline NullStream& operator << (ios_base& (*)(ios_base&)) { return *this; }
};

static NullStream null_stream;

#ifndef DEBUG
#define cerr null_stream
#endif

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

i64 randint(i64 a,i64 b) {
    uniform_int_distribution<i64> dist(a,b);
    return dist(rnd);
}

namespace IO {
    template<typename T> inline void read(T& x) { int s=1; char c=getchar(); x=0; while (!isdigit(c)) { if (c=='-') s=-1; c=getchar(); } while (isdigit(c) && c!=EOF) x=x*10+(c-'0'),c=getchar(); x*=s; }
    inline void readstr(string& x) { x.clear(); char c=getchar(); while (isspace(c)) c=getchar(); while (!isspace(c) && c!=EOF) x.push_back(c),c=getchar(); }
    inline void readstr(char* x) { int idx=0; char c=getchar(); while (isspace(c)) c=getchar(); while (!isspace(c) && c!=EOF) x[idx++]=c,c=getchar(); x[idx]='\0'; }
    template<typename T> inline void write(T x) { if (x<0) putchar('-'),x=-x; if (x/10) write(x/10); putchar('0'+(x%10)); }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
    inline void writestr(const string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(const string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(const string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
    template<typename T,typename... Args> inline void read(T& arg,Args&... args) { read(arg),read(args...); }
    template<typename T,typename... Args> inline void writesp(T& arg,Args&... args) { writesp(arg),writesp(args...); }
    template<typename T,typename... Args> inline void writeln(T& arg,Args&... args) { writeln(arg),writeln(args...); }
    template<typename T,typename... Args> inline void writespln(T& arg,Args&... args) { writesp(arg),writesp(args...),putchar(10); }
}

using namespace IO;

namespace Geometry {
    const double pi=acos(-1);
    const double eps=1e-9;

    struct Point {
        double x,y;
        friend Point operator + (Point a,Point b) {
            return {a.x+b.x,a.y+b.y};
        }
        friend Point operator - (Point a,Point b) {
            return {a.x-b.x,a.y-b.y};
        }
        friend Point operator * (Point a,double b) {
            return {a.x*b,a.y*b};
        }
        friend Point operator / (Point a,double b) {
            return {a.x/b,a.y/b};
        }
    };

    struct Line {
        Point a,b;
    };

    struct Circle {
        Point o;
        double r;
    };

    int sign(double k) {
        if (fabs(k)<eps) return 0;
        else if (k>0) return 1;
        else return -1;
    }

    int cmp(double a,double b) {
        if (fabs(a-b)<eps) return 0;
        else if (a>b) return 1;
        else return -1;
    }

    double dot(Point a,Point b) {
        return a.x*b.x+a.y*b.y;
    }

    double cross(Point a,Point b) {
        return a.x*b.y-a.y*b.x;
    }

    double area(Point a,Point b,Point c) {
        return cross(b-a,c-a);
    }

    double get_dis(Point a,Point b) {
        double dx=a.x-b.x,dy=a.y-b.y;
        return sqrt(dx*dx+dy*dy);
    }

    Point get_intersection(Point p,Point v,Point q,Point w) {
        auto u=p-q;
        double t=cross(w,u)/cross(v,w);
        return p+v*t;
    }

    Point rotate(Point a,double t) {
        return {a.x*cos(t)+a.y*sin(t),-a.x*sin(t)+a.y*cos(t)};
    }

    Line get_line(Point a,Point b) {
        return {(a+b)/2,rotate((b-a),pi/2)};
    }

    Circle get_circle(Point a,Point b,Point c) {
        auto p=get_line(a,b),q=get_line(a,c);
        auto o=get_intersection(p.a,p.b,q.a,q.b);
        return {o,get_dis(o,a)};
    }
}

namespace Math {
    const int N=1;
    const int mod=MOD;

    int gcd(int a,int b) {
        return (!b)?a:gcd(b,a%b);
    }

    int lcm(int a,int b) {
        return a/gcd(a,b)*b;
    }

    int exgcd(int a,int b,int& x,int& y) {
        if (!b) {
            x=1,y=0;
            return a;
        }
        int d=exgcd(b,a%b,y,x);
        y-=a/b*x;
        return d;
    }

    int inverse(int a) {
        int x,y;
        exgcd(a,mod,x,y);
        x=(x%mod+mod)%mod;
        return x;
    }

    int inverse(int a,int p) {
        int x,y;
        exgcd(a,p,x,y);
        x=(x%p+p)%p;
        return x;
    }

    int ksm(int a,int b) {
        if (!b) return 1;
        int k=ksm(a,b>>1);
        if (b&1) return (k*k%mod)*a%mod;
        else return k*k%mod;
    }

    int pri[N],idx;
    bool flag[N];
    int mu[N],phi[N];

    void init() {
        mu[1]=1,phi[1]=1;
        _rep(i,2,N-1) {
            if (!flag[i]) pri[++idx]=i,mu[i]=-1,phi[i]=i-1;
            _rep(j,1,idx) {
                if (i*pri[j]>=N) break;
                flag[i*pri[j]]=true;
                if (i%pri[j]==0) {
                    phi[i*pri[j]]=phi[i]*pri[j];
                    break;
                }
                phi[i*pri[j]]=phi[i]*phi[pri[j]];
                mu[i*pri[j]]=-mu[i];
            }
        }
    }

    int f[N],g[N];

    void init_fact() {
        f[0]=g[0]=1;
        _rep(i,1,N-1) f[i]=f[i-1]*i%mod,g[i]=inverse(f[i]);
    }

    int C(int n,int m) {
        return (f[n]*g[m]%mod)*g[n-m]%mod;
    }

    int A(int n,int m) {
        return f[n]*g[n-m]%mod;
    }
}

namespace Tree {
    const int N=1;
    const int M=2;
    const int K=1;
    const int mod=MOD;

    int n,m;
    int e[M],ne[M],w[M],h[N],tot;

    void add(int a,int b) {
        e[tot]=b,ne[tot]=h[a],h[a]=tot++;
    }

    void add(int a,int b,int c) {
        e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
    }

    namespace LCA {
        int dep[N];
        int f[N][K];

        void dfs_lca(int u,int p,int d) {
            dep[u]=d;
            _graph(i,u) {
                if (e[i]==p) continue;
                f[e[i]][0]=u;
                _rep(j,1,K-1) f[e[i]][j]=f[f[e[i]][j-1]][j-1];
                dfs_lca(e[i],u,d+1);
            }
        }

        int lca(int a,int b) {
            if (a==b) return a;
            if (dep[a]<dep[b]) swap(a,b);
            _rrep(i,K-1,0) if (dep[f[a][i]]>=dep[b]) a=f[a][i];
            if (a==b) return a;
            _rrep(i,K-1,0) if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
            return f[a][0];
        }
    }

    namespace HLD {
        int dep[N],sz[N],top[N],fa[N],son[N],w[N],id[N],cnt;

        void dfs1(int u,int p,int d) {
            dep[u]=d,sz[u]=1,fa[u]=p;
            _graph(i,u) {
                if (e[i]==fa[u]) continue;
                dfs1(e[i],u,d+1);
                sz[u]+=sz[e[i]];
                if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
            }
        }

        void dfs2(int u,int p,int* arr) {
            top[u]=p,id[u]=++cnt,w[id[u]]=arr[u];
            if (!son[u]) return;
            dfs2(son[u],p,arr);
            _graph(i,u) {
                if (e[i]==fa[u] || e[i]==son[u]) continue;
                dfs2(e[i],e[i],arr);
            }
        }

        void dfs2(int u,int p) {
            top[u]=p,id[u]=++cnt;
            if (!son[u]) return;
            dfs2(son[u],p);
            _graph(i,u) {
                if (e[i]==fa[u] || e[i]==son[u]) continue;
                dfs2(e[i],e[i]);
            }
        }

        template<
            class ModifyType
        >
        void modify_path(int u,int v,ModifyType& k,bool edge,function<void(int,int,int,ModifyType&)> modify) {
            while (top[u]!=top[v]) {
                if (dep[top[u]]<dep[top[v]]) swap(u,v);
                modify(1,id[top[u]],id[u],k);
                u=fa[top[u]];
            }
            if (dep[u]<dep[v]) swap(u,v);
            if (!edge) modify(1,id[v],id[u],k);
            if (edge && id[v]!=id[u]) modify(1,id[son[v]],id[u],k);
        }

        template<
            class ModifyType
        >
        void modify_tree(int u,ModifyType k,function<void(int,int,int,ModifyType&)> modify) {
            modify(1,id[u],id[u]+sz[u]-1,k);
        }

        template<
            class ValueType
        >
        ValueType query_path(int u,int v,bool edge,function<ValueType(int,int,int)> query,function<void(ValueType&,ValueType&,ValueType&)> pushup) {
            ValueType ans;
            while (top[u]!=top[v]) {
                if (dep[top[u]]<dep[top[v]]) swap(u,v);
                ValueType g=query(1,id[top[u]],id[u]);
                pushup(ans,ans,g);
                u=fa[top[u]];
            }
            if (dep[u]<dep[v]) swap(u,v);
            if (!edge) {
                ValueType g=query(1,id[v],id[u]);
                pushup(ans,ans,g);
            }
            if (edge && id[v]!=id[u]) {
                ValueType g=query(1,id[son[v]],id[u]);
                pushup(ans,ans,g);
            }
            return ans;
        }

        template<
            class ValueType
        >
        ValueType query_tree(int u,function<ValueType(int,int,int)> query) {
            return query(1,id[u],id[u]+sz[u]-1);
        }
    }
}

namespace Graph {
    const int N=1;
    const int M=2;
    const int inf=INF;

    int n,m;
    int e[M],ne[M],w[M],h[N],tot;

    void add(int a,int b) {
        e[tot]=b,ne[tot]=h[a],h[a]=tot++;
    }

    void add(int a,int b,int c) {
        e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
    }

    namespace SP {
        int dis[N];
        bool flag[N];
        priority_queue<pii,vector<pii>,greater<pii>> q;

        void dijkstra(int s) {
            _rep(i,0,n) dis[i]=inf,flag[i]=false;
            q.push({dis[s]=0,s});
            while (!q.empty()) {
                auto tp=q.top(); q.pop();
                int u=tp.second;
                if (flag[u]) continue;
                flag[u]=true;
                _graph(i,u) if (dis[e[i]]>dis[u]+w[i]) q.emplace(pii{dis[e[i]]=dis[u]+w[i],e[i]});
            }
        }
    }

    namespace SCC {
        int dfn[N],low[N],ts,scc;
        int id[N];
        bool flag[N];
        bool instk[N];
        stack<int> stk;
        vector<int> scc_nodes[N];

        void tarjan(int u) {
            dfn[u]=low[u]=++ts;
            stk.emplace(u);
            instk[u]=true;
            _graph(i,u) {
                if (!dfn[e[i]]) {
                    tarjan(e[i]);
                    low[u]=min(low[u],low[e[i]]);
                } else if (instk[e[i]]) low[u]=min(low[u],dfn[e[i]]);
            }
            if (low[u]==dfn[u]) {
                int y;
                scc++;
                do {
                    y=stk.top(); stk.pop(); instk[y]=false;
                    scc_nodes[scc].emplace_back(y);
                    id[y]=scc;
                } while (y!=u);
            }
        }
    }

    namespace EDCC {
        int dfn[N],low[N],ts,edcc;
        int id[N];
        bool flag[N];
        stack<int> stk;
        vector<int> edcc_nodes[N];

        void tarjan(int u,int las) {
            dfn[u]=low[u]=++ts;
            flag[u]=true;
            stk.emplace(u);
            _graph(i,u) {
                if (i==(las^1)) continue;
                if (!dfn[e[i]]) {
                    tarjan(e[i],i);
                    low[u]=min(low[u],low[e[i]]);
                } else if (flag[e[i]]) low[u]=min(low[u],dfn[e[i]]);
            }
            if (dfn[u]==low[u]) {
                int y;
                edcc++;
                do {
                    y=stk.top(); stk.pop(); flag[y]=false;
                    edcc_nodes[edcc].emplace_back(y);
                } while (y!=u);
            }
        }
    }

    namespace VDCC {
        int dfn[N],low[N],ts,vdcc;
        int id[N];
        bool flag[N];
        stack<int> stk;
        vector<int> vdcc_nodes[N];

        void tarjan(int u,int las) {
            dfn[u]=low[u]=++ts;
            if (!~h[u] && !~las) {
                vdcc++;
                vdcc_nodes[vdcc].emplace_back(u);
                return;
            }
            flag[u]=true;
            stk.emplace(u);
            _graph(i,u) {
                if (i==(las^1)) continue;
                if (!dfn[e[i]]) {
                    tarjan(e[i],i);
                    low[u]=min(low[u],low[e[i]]);
                    if (low[e[i]]>=dfn[u]) {
                        int y;
                        vdcc++;
                        do {
                            y=stk.top(); stk.pop(); flag[y]=false;
                            vdcc_nodes[vdcc].emplace_back(y);
                        } while (y!=e[i]);
                        vdcc_nodes[vdcc].emplace_back(u);
                    }
                } else if (flag[e[i]]) low[u]=min(low[u],dfn[e[i]]);
            }
        }
    }

    namespace TOPO {
        int indeg[N];

        void topo(int n) {
            _rep(i,0,tot-1) indeg[e[i]]++;
            queue<int> q;
            _rep(i,1,n) if (!indeg[i]) q.emplace(i);
            while (!q.empty()) {
                int u=q.front(); q.pop();
                _graph(i,u) {
                    if (!--indeg[e[i]]) q.emplace(e[i]);
                }
            }
        }
    }

    namespace FLOW {
        int S,T;
        int f[M],c[M];
        int cur[N],dep[N];
        int dis[N],flow[N],bk[N];
        bool flag[N];

        void add(int a,int b,int c) {
            e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
            e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
        }

        void add(int a,int b,int F,int C) {
            e[tot]=b,f[tot]=F,c[tot]=C,ne[tot]=h[a],h[a]=tot++;
            e[tot]=a,f[tot]=0,c[tot]=-C,ne[tot]=h[b],h[b]=tot++;
        }

        bool bfs() {
            queue<int> q;
            memset(dep,0,sizeof(dep));
            q.emplace(S),cur[S]=h[S],dep[S]=1;
            while (!q.empty()) {
                int u=q.front(); q.pop();
                _graph(i,u) {
                    if (!dep[e[i]] && f[i]) {
                        dep[e[i]]=dep[u]+1;
                        cur[e[i]]=h[e[i]];
                        if (e[i]==T) return true;
                        q.emplace(e[i]);
                    }
                }
            }
            return false;
        }

        int dfs(int u,int limit) {
            if (u==T) return limit;
            int k=0;
            _dinic(i,u) {
                cur[u]=i;
                if (dep[e[i]]==dep[u]+1 && f[i]) {
                    int ret=dfs(e[i],min(f[i],limit-k));
                    f[i]-=ret,f[i^1]+=ret,k+=ret;
                    if (!ret) dep[e[i]]=0;
                }
            }
            return k;
        }

        int dinic() {
            int ans=0,k;
            while (bfs()) while (k=dfs(S,inf)) ans+=k;
            return ans;
        }

        bool spfa() {
            _rep(i,1,N-1) dis[i]=flow[i]=inf,flag[i]=0;
            queue<int> q;
            q.emplace(S),dis[S]=0,flag[S]=true;
            while (!q.empty()) {
                int u=q.front(); q.pop(),flag[u]=false;
                _graph(i,u) {
                    if (dis[e[i]]>dis[u]+c[i] && f[i]) {
                        dis[e[i]]=dis[u]+c[i];
                        flow[e[i]]=min(flow[u],f[i]);
                        bk[e[i]]=i;
                        if (!flag[e[i]]) q.emplace(e[i]),flag[e[i]]=true;
                    }
                }
            }
            return dis[T]!=inf;
        }

        pii solve() {
            int F=0,C=0;
            while (spfa()) {
                F+=flow[T];
                int u=T;
                while (u!=S) {
                    int i=bk[u];
                    f[i]-=flow[T],f[i^1]+=flow[T];
                    C+=c[i]*flow[T];
                    u=e[i^1];
                }
            }
            return pii{F,C};
        }
    }
}

template<
    class ValueType,
    void (*UP)(ValueType&,ValueType&,ValueType&),
    void (*DOWN)(ValueType&,ValueType&,ValueType&),
    class ModifyType,
    void (*MODIFY)(ValueType&,ModifyType&)
>
class SEG {
    public:

    struct Seg {
        int l,r;
        ValueType v;
    } *tr;

    SEG() {}

    void reserve(int N) {
        delete[] tr;
        tr=new Seg[N<<2];
        memset(tr,0,sizeof(Seg)*(N<<2));
        build(1,1,N);
    }

    SEG(int N) {
        tr=new Seg[N<<2];
        memset(tr,0,sizeof(Seg)*(N<<2));
        build(1,1,N);
    }

    SEG(int N,ValueType* arr) {
        tr=new Seg[N<<2];
        memset(tr,0,sizeof(Seg)*(N<<2));
        build(1,1,N,arr);
    }

    ~SEG() {
        delete[] tr;
    }

    SEG(const SEG&)=delete;
    SEG& operator=(const SEG&)=delete;

    void pushup(int u) {
        UP(tr[u].v,tr[u<<1].v,tr[u<<1|1].v);
    }

    void pushdown(int u) {
        auto& root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
        DOWN(root.v,left.v,right.v);
    }

    void build(int u,int l,int r) {
        tr[u].l=l,tr[u].r=r,tr[u].v.len=(r-l+1);
        if (l==r) return;
        int mid=l+r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        pushup(u);
    }

    void build(int u,int l,int r,ValueType* arr) {
        tr[u].l=l,tr[u].r=r,tr[u].v=arr[l],tr[u].v.len=(r-l+1);
        if (l==r) return;
        int mid=l+r>>1;
        build(u<<1,l,mid,arr); build(u<<1|1,mid+1,r,arr);
        pushup(u);
    }

    void modify(int u,int l,int r,ModifyType& k) {
        if (tr[u].l>=l && tr[u].r<=r) {
            MODIFY(tr[u].v,k);
        } else {
            pushdown(u);
            int mid=tr[u].l+tr[u].r>>1;
            if (l<=mid) modify(u<<1,l,r,k);
            if (r>mid) modify(u<<1|1,l,r,k);
            pushup(u);
        }
    }

    ValueType query(int u,int l,int r) {
        if (tr[u].l>=l && tr[u].r<=r) return tr[u].v;
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        ValueType ans,L,R;
        if (l<=mid) L=query(u<<1,l,r);
        if (r>mid) R=query(u<<1|1,l,r);
        UP(ans,L,R);
        return ans;
    }
};

template<
    class ValueType
>
class BIT {
    public:

    int n;
    ValueType* tr;

    BIT() {}

    void reserve(int n) {
        delete[] tr;
        tr=new ValueType[n];
        memset(tr,0,sizeof(ValueType)*n);
        this->n=n;
    }

    BIT(int n) {
        tr=new ValueType[n];
        memset(tr,0,sizeof(ValueType)*n);
        this->n=n;
    }

    ~BIT() {
        delete[] tr;
    }

    BIT(const BIT&)=delete;
    BIT& operator=(const BIT&)=delete;

    int lowbit(int x) {
        return x&-x;
    }

    void modify(int x,ValueType k) {
        while (x<=n) tr[x]=tr[x]+k,x+=lowbit(x);
    }

    ValueType query(int x) {
        ValueType ans=0;
        while (x) ans=ans+tr[x],x-=lowbit(x);
        return ans;
    }
};

template<int mod>
class Mint {
    public:

    int a;

    Mint(): a(0) {}

    Mint(int k): a((k%mod+mod)%mod) {}

    Mint(const Mint<mod>& k): a(k) {}

    operator int() const {
        return a;
    }

    operator double() const {
        return (double)a;
    }

    friend Mint operator + (Mint a,Mint b) {
        return Mint(a.a+b.a);
    }

    friend Mint operator + (Mint a,int b) {
        return Mint(a.a+b);
    }

    friend Mint operator + (int b,Mint a) {
        return Mint(a.a+b);
    }

    friend void operator += (Mint& a,Mint b) {
        a.a=(a.a+b.a)%mod;
    }

    friend void operator += (Mint& a,int b) {
        a.a=((a.a+b)%mod+mod)%mod;
    }

    friend Mint operator - (Mint a,Mint b) {
        return Mint(a.a-b.a);
    }

    friend Mint operator - (Mint a,int b) {
        return Mint(a.a-b);
    }

    friend Mint operator - (int b,Mint a) {
        return Mint(a.a-b);
    }

    friend void operator -= (Mint& a,Mint b) {
        a.a=(a.a-b.a+mod)%mod;
    }

    friend void operator -= (Mint& a,int b) {
        a.a=((a.a-b)%mod+mod)%mod;
    }

    friend Mint operator * (Mint a,Mint b) {
        return Mint(a.a*b.a);
    }

    friend Mint operator * (Mint a,int b) {
        return Mint(a.a*b);
    }

    friend Mint operator * (int b,Mint a) {
        return Mint(a.a*b);
    }

    friend void operator *= (Mint& a,Mint b) {
        a.a=(a.a*b.a)%mod;
    }

    friend void operator *= (Mint& a,int b) {
        a.a=((a.a*b)%mod+mod)%mod;
    }

    friend Mint operator / (Mint a,Mint b) {
        return Mint(a.a*Math::inverse(b.a,mod));
    }

    friend Mint operator / (Mint a,int b) {
        return Mint(a.a*Math::inverse(b,mod));
    }

    friend Mint operator / (int b,Mint a) {
        return Mint(a.a*Math::inverse(b,mod));
    }

    friend void operator /= (Mint& a,Mint b) {
        a.a=(a.a*Math::inverse(b.a,mod))%mod;
    }

    friend void operator /= (Mint& a,int b) {
        a.a=((a.a*Math::inverse(b,mod))%mod+mod)%mod;
    }

    friend ostream& operator << (ostream& os,Mint a) {
        os<<a.a;
        return os;
    }

    friend bool operator < (Mint a,Mint b) {
        return a.a<b.a;
    }

    friend bool operator < (Mint a,int b) {
        return a.a<b;
    }

    friend bool operator < (int b,Mint a) {
        return b<a.a;
    }

    friend bool operator <= (Mint a,Mint b) {
        return a.a<=b.a;
    }

    friend bool operator <= (Mint a,int b) {
        return a.a<=b;
    }

    friend bool operator <= (int b,Mint a) {
        return b<=a.a;
    }

    friend bool operator > (Mint a,Mint b) {
        return a.a<b.a;
    }

    friend bool operator > (Mint a,int b) {
        return a.a>b;
    }

    friend bool operator > (int b,Mint a) {
        return b>a.a;
    }

    friend bool operator >= (Mint a,Mint b) {
        return a.a>=b.a;
    }

    friend bool operator >= (Mint a,int b) {
        return a.a>=b;
    }

    friend bool operator >= (int b,Mint a) {
        return b>=a.a;
    }

    friend bool operator == (Mint a,Mint b) {
        return a.a==b.a;
    }

    friend bool operator == (Mint a,int b) {
        return a.a==b;
    }

    friend bool operator == (int b,Mint a) {
        return a.a==b;
    }

    friend bool operator != (Mint a,Mint b) {
        return a.a!=b.a;
    }

    friend bool operator != (Mint a,int b) {
        return a.a!=b;
    }

    friend bool operator != (int b,Mint a) {
        return a.a!=b;
    }
};

template<int n>
class BigInt {
    public:

    int* arr;

    BigInt() {
        arr=new int[n];
        memset(arr,0,sizeof(int)*n);
    }

    BigInt& operator = (const BigInt& b) {
        memcpy(arr,b.arr,sizeof(int)*n);
        return *this;
    }

    ~BigInt() {
        delete[] arr;
    }

    int& operator [] (int pos) {
        return arr[pos];
    }

    const int& operator [] (int pos) const {
        return arr[pos];
    }

    void print() {
        bool st=false;
        _rrep(i,n-1,1) {
            if (!st && !arr[i]) continue;
            write(arr[i]),st=true;
        }
        if (!st) write(0);
    }

    friend BigInt operator + (const BigInt& a,const BigInt& b) {
        BigInt<n> c;
        int jw=0;
        _rep(i,1,n-1) c[i]=a[i]+b[i]+jw,jw=c[i]/10,c[i]%=10;
        return c;
    }

    friend BigInt operator + (const BigInt& a,int b) {
        BigInt<n> c;
        int jw=b;
        _rep(i,1,n-1) c[i]=a[i]+jw,jw=c[i]/10,c[i]%=10;
        return c;
    }

    friend BigInt operator + (int b,const BigInt& a) {
        return a+b;
    }

    friend BigInt operator - (const BigInt& a,const BigInt& b) {
        BigInt<n> c;
        int jw=0;
        _rep(i,1,n-1) {
            c[i]=a[i]-b[i]-jw;
            if (c[i]<0) c[i]+=10,jw=1;
            else jw=0;
        }
        return c;
    }

    friend BigInt operator - (const BigInt& a,int b) {
        BigInt<n> c;
        int jw=b;
        _rep(i,1,n-1) {
            c[i]=a[i]-jw;
            if (c[i]<0) jw=(-c[i]/10+(bool)((-c[i])%10)),c[i]+=jw*10;
            else jw=0;
        }
        return c;
    }

    friend BigInt operator * (const BigInt& a,const BigInt& b) {
        BigInt<n> c;
        _rep(i,1,n-1) _rep(j,1,n-i) c[i+j-1]+=a[i]*b[j];
        int jw=0;
        _rep(i,1,n-1) c[i]+=jw,jw=c[i]/10,c[i]%=10;
        return c;
    }

    friend BigInt operator * (const BigInt& a,int b) {
        BigInt<n> c;
        _rep(i,1,n-1) c[i]=a[i]*b;
        int jw=0;
        _rep(i,1,n-1) c[i]+=jw,jw=c[i]/10,c[i]%=10;
        return c;
    }
    
    friend BigInt operator * (int b,const BigInt& a) {
        return a*b;
    }

    friend BigInt operator / (const BigInt& a,int b) {
        BigInt<n> c;
        int cur=0;
        _rrep(i,n-1,1) cur=cur*10+a[i],c[i]=cur/b,cur%=b;
        return c;
    }

    friend bool operator == (const BigInt& a,const BigInt& b) {
        _rrep(i,n-1,1) if (a[i]!=b[i]) return false;
        return true;
    }

    friend bool operator != (const BigInt& a,const BigInt& b) {
        return !(a==b);
    }

    friend bool operator < (const BigInt& a,const BigInt& b) {
        _rrep(i,n-1,1) {
            if (a[i]<b[i]) return true;
            else if (a[i]>b[i]) return false;
        }
        return false;
    }

    friend bool operator <= (const BigInt& a,const BigInt& b) {
        _rrep(i,n-1,1) {
            if (a[i]<b[i]) return true;
            else if (a[i]>b[i]) return false;
        }
        return true;
    }

    friend bool operator > (const BigInt& a,const BigInt& b) {
        _rrep(i,n-1,1) {
            if (a[i]<b[i]) return false;
            else if (a[i]>b[i]) return true;
        }
        return false;
    }

    friend bool operator >= (const BigInt& a,const BigInt& b) {
        _rrep(i,n-1,1) {
            if (a[i]<b[i]) return false;
            else if (a[i]>b[i]) return true;
        }
        return true;
    }
};

const int N=200005;

int n;
vector<int> vec;

struct node {
    int a,b;
    friend bool operator < (const node& a,const node& b) {
        if (a.a!=b.a) return a.a<b.a;
        else return a.b>b.b;
    }
} arr[N];

int main() {
    read(n);
    _rep(i,1,n) read(arr[i].a,arr[i].b);
    sort(arr+1,arr+1+n);
    _rep(i,1,n) {
        int k=arr[i].b;
        int pos=lower_bound(vec.begin(),vec.end(),k)-vec.begin();
        if (pos==vec.size()) vec.emplace_back(k);
        else vec[pos]=k;
    }
    write(vec.size());
    return 0;
}