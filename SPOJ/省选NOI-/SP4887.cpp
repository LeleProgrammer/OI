#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=200005;
const int inf=2e9;

int n,m;
int arr[N];
int stk[N],top;
int root;

struct Splay {
    int s[2],p,v,sz;
    int lmx,rmx,mmx;
    int sum;
    void init() {
        s[0]=s[1]=p=v=sz=lmx=rmx=mmx=sum=0;
    }
    void init(int p,int v) {
        this->p=p;
        this->v=v;
        s[0]=s[1]=0;
        lmx=rmx=max(v,0LL);
        mmx=sum=v;
        sz=1;
    }
} tr[N];

Splay pushup(Splay& u,Splay& l,Splay& r) {
    Splay ans;
    ans=u;
    ans.sz=l.sz+r.sz+1;
    ans.sum=l.sum+r.sum+u.v;
    ans.lmx=max(l.lmx,l.sum+u.v+r.lmx);
    ans.rmx=max(r.rmx,r.sum+u.v+l.rmx);
    ans.mmx=max(max(l.mmx,r.mmx),l.rmx+u.v+r.lmx);
    return ans;
}

void pushup(int u) {
    tr[u]=pushup(tr[u],tr[tr[u].s[0]],tr[tr[u].s[1]]);
}

int build(int l,int r,int fa) {
    int u=stk[top--];
    int mid=l+r>>1;
    tr[u].init(fa,arr[mid]);
    if (l<mid) tr[u].s[0]=build(l,mid-1,u);
    if (r>mid) tr[u].s[1]=build(mid+1,r,u);
    pushup(u);
    return u;
}

void rotate(int x) {
    int y=tr[x].p;
    int z=tr[y].p;
    int k=x==tr[y].s[1];
    tr[z].s[tr[z].s[1]==y]=x,tr[x].p=z;
    tr[y].s[k]=tr[x].s[k^1],tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y,tr[y].p=x;
    pushup(y);
    pushup(x);
}

void splay(int x,int k) {
    while (tr[x].p!=k) {
        int y=tr[x].p;
        int z=tr[y].p;
        if (z!=k) {
            if ((tr[y].s[1]==x)^(tr[z].s[1]==y)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if (!k) root=x;
}

int get_k(int k) {
    int u=root;
    while (u) {
        if (k<=tr[tr[u].s[0]].sz) u=tr[u].s[0];
        else if (k==tr[tr[u].s[0]].sz+1) return u;
        else k-=tr[tr[u].s[0]].sz+1,u=tr[u].s[1];
    }
    return -1;
}

signed main() {
    _rrep(i,N-1,1) stk[++top]=i;
    tr[0].mmx=-inf;
    scanf("%lld",&n);
    _rep(i,1,n) scanf("%lld",&arr[i]);
    arr[0]=-inf,arr[n+1]=-inf;
    root=build(0,n+1,0);
    scanf("%lld",&m);
    while (m--) {
        char op[2];
        scanf("%s",op);
        if (*op=='I') {
            int p,x;
            scanf("%lld %lld",&p,&x);
            int l=get_k(p);
            int r=get_k(p+1);
            splay(l,0);
            splay(r,l);
            int u=stk[top--];
            tr[u].init(r,x);
            tr[r].s[0]=u;
            pushup(r);
            pushup(l);
        } else if (*op=='D') {
            int p;
            scanf("%lld",&p); p++;
            int l=get_k(p-1);
            int r=get_k(p+1);
            splay(l,0);
            splay(r,l);
            stk[++top]=tr[r].s[0];
            tr[r].s[0]=0;
            pushup(r);
            pushup(l);
        } else if (*op=='R') {
            int p,x;
            scanf("%lld %lld",&p,&x); p++;
            int l=get_k(p);
            splay(l,0);
            tr[l].v=x;
            pushup(l);
        } else {
            int l,r;
            scanf("%lld %lld",&l,&r); l++,r++; l--,r++;
            l=get_k(l);
            r=get_k(r);
            splay(l,0);
            splay(r,l);
            printf("%lld\n",tr[tr[r].s[0]].mmx);
        }
    }
    return 0;
}