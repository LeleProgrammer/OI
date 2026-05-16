#include <stdio.h>
#include <string.h>
// using namespace std;

const int N=10005;
const int M=20005;
const int inf=2e9;

int T,n;
int e[M],ne[M],w[M],h[N],tot;
int arr[N];
int id[N],cnt;
int top[N],son[N],fa[N],sz[N],layer[N];
int st[N][2];

struct SegmentTree {
    int l,r;
    int k;
} tr[N*4];

void swap(int& a,int& b) {
    int c=a;
    a=b;
    b=c;
}

int max(int a,int b) {
    if (a>b) return a;
    else return b;
}

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p) {
    sz[u]=1;
    fa[u]=p;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa[u]) continue;
        layer[e[i]]=layer[u]+1;
        dfs1(e[i],u);
        sz[u]+=sz[e[i]];
        if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
    }
}

void dfs2(int u,int p) {
    top[u]=p;
    id[u]=++cnt;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa[u]) continue;
        arr[e[i]]=w[i];
        if (e[i]==son[u]) dfs2(e[i],p);
        else dfs2(e[i],e[i]);
    }
}

void pushup(int u) {
    tr[u].k=max(tr[u<<1].k,tr[u<<1|1].k);
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int p,int k) {
    if (tr[u].l==p && tr[u].r==p) {
        tr[u].k=k;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (p<=mid) modify(u<<1,p,k);
        else modify(u<<1|1,p,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].k;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=-inf;
    if (l<=mid) ans=max(ans,query(u<<1,l,r));
    if (r>mid) ans=max(ans,query(u<<1|1,l,r));
    return ans;
}

int query_path(int u,int v) {
    int ans=-inf;
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        ans=max(ans,query(1,id[top[u]],id[u]));
        u=fa[top[u]];
    }
    if (u!=v) {
        if (layer[u]<layer[v]) swap(u,v);
        ans=max(ans,query(1,id[son[v]],id[u]));
    }
    return ans;
}

int main() {
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            h[i]=-1;
            arr[i]=id[i]=top[i]=son[i]=fa[i]=sz[i]=layer[i]=st[i][0]=st[i][1]=0;
        }
        tot=cnt=0;
        for (int i=1;i<=n-1;++i) {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            st[i][0]=a,st[i][1]=b;
            add(a,b,c);
            add(b,a,c);
        }
        dfs1(1,0);
        dfs2(1,1);
        build(1,1,cnt);
        while (true) {
            char op[10];
            scanf("%s",op);
            if (!strcmp(op,"DONE")) break;
            else if (!strcmp(op,"QUERY")) {
                int a,b;
                scanf("%d %d",&a,&b);
                printf("%d\n",query_path(a,b));
            } else {
                int a,b;
                scanf("%d %d",&a,&b);
                int la=layer[st[a][0]];
                int lb=layer[st[a][1]];
                int k;
                if (la>lb) k=st[a][0];
                else k=st[a][1];
                modify(1,k,b);
            }
        }
        if (T) putchar(10);
    }
    return 0;
}