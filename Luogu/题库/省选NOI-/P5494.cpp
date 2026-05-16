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
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=200005;

int n,m;
int arr[N];
int root[N],cnt;
stack<int> stk;

struct Seg {
    int l,r;
    int v;
} tr[N<<3];

void pushup(int u) {
    tr[u].v=tr[tr[u].l].v+tr[tr[u].r].v;
}

int newNode() {
    int ans=stk.top();
    stk.pop();
    return ans;
}

void delNode(int k) {
    tr[k]={0,0,0};
    stk.push(k);
}

int build(int l,int r) {
    int u=newNode();
    tr[u]={0,0,arr[l]};
    if (l==r) return u;
    int mid=l+r>>1;
    tr[u].l=build(l,mid);
    tr[u].r=build(mid+1,r);
    pushup(u);
    return u;
}

void split(int& p,int& t,int x,int y,int l,int r) {
    if (!p) return;
    if (l>=x && r<=y) t=p,p=0;
    else {
        if (!t) t=newNode();
        int mid=l+r>>1;
        if (x<=mid) split(tr[p].l,tr[t].l,x,y,l,mid);
        if (y>mid) split(tr[p].r,tr[t].r,x,y,mid+1,r);
        pushup(p);
        pushup(t);
    }
}

int merge(int t,int p,int l,int r) {
    if (!t) return p;
    else if (!p) return t;
    else if (l==r) tr[p].v+=tr[t].v,delNode(t);
    else {
        int mid=l+r>>1;
        tr[p].l=merge(tr[t].l,tr[p].l,l,mid);
        tr[p].r=merge(tr[t].r,tr[p].r,mid+1,r);
        delNode(t);
        pushup(p);
    }
    return p;
}

void modify(int u,int q,int x,int l,int r) {
    if (l==q && r==q) tr[u].v+=x;
    else {
        int mid=l+r>>1;
        if (q<=mid) {
            if (!tr[u].l) tr[u].l=newNode();
            modify(tr[u].l,q,x,l,mid);
        } else {
            if (!tr[u].r) tr[u].r=newNode();
            modify(tr[u].r,q,x,mid+1,r);
        }
        pushup(u);
    }
}

int query_cnt(int u,int x,int y,int l,int r) {
    if (l>=x && r<=y) return tr[u].v;
    else {
        int mid=l+r>>1;
        int ans=0;
        if (x<=mid) ans+=query_cnt(tr[u].l,x,y,l,mid);
        if (y>mid) ans+=query_cnt(tr[u].r,x,y,mid+1,r);
        return ans;
    }
}

int query_k(int u,int k,int l,int r) {
    if (l==r) return l;
    else {
        int mid=l+r>>1;
        if (k<=tr[tr[u].l].v) return query_k(tr[u].l,k,l,mid);
        else return query_k(tr[u].r,k-tr[tr[u].l].v,mid+1,r);
    }
}

signed main() {
    _rep(i,1,(N<<3)-1) stk.emplace(i);
    scanf("%lld %lld",&n,&m);
    _rep(i,1,n) scanf("%lld",&arr[i]);
    root[cnt=1]=build(1,n);
    while (m--) {
        int op;
        scanf("%lld",&op);
        if (!op) {
            int p,x,y;
            scanf("%lld %lld %lld",&p,&x,&y);
            split(root[p],root[++cnt],x,y,1,n);
        } else if (op==1) {
            int p,t;
            scanf("%lld %lld",&p,&t);
            root[p]=merge(root[t],root[p],1,n);
        } else if (op==2) {
            int p,x,q;
            scanf("%lld %lld %lld",&p,&x,&q);
            modify(root[p],q,x,1,n);
        } else if (op==3) {
            int p,x,y;
            scanf("%lld %lld %lld",&p,&x,&y);
            printf("%lld\n",query_cnt(root[p],x,y,1,n));
        } else if (op==4) {
            int p,k;
            scanf("%lld %lld",&p,&k);
            if (tr[root[p]].v<k) puts("-1");
            else printf("%lld\n",query_k(root[p],k,1,n));
        }
    }
    return 0;
}