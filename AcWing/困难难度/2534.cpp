#include <bits/stdc++.h>
using namespace std;

const int N=80005;
const int M=80005;
const int K=100005;
const int D=20;

int n,m,len;
vector<int> nums;
int w[N];
int cnt[K];
int sta[N];
int e[M],ne[M],h[N],tot;
int arr[N],idx;
int layer[N];
int f[N][D];
int fir[N],last[N];
int ans[K];
queue<int> qu;

void add_edge(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

struct Query {
    int id,l,r,p;
} q[K];

int get(int x) {
    return x/len;
}

bool cmp1(const int& a,const int& b) {
    return a<b;
}

bool cmp2(const Query& a,const Query& b) {
    int al=get(a.l);
    int bl=get(b.l);
    if (al!=bl) return al<bl;
    return a.r<b.r;
}

void dfs(int u,int fa) {
    arr[++idx]=u;
    fir[u]=idx;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        dfs(e[i],u);
    }
    arr[++idx]=u;
    last[u]=idx;
}

void bfs() {
    qu.push(1);
    layer[1]=1;
    while (!qu.empty()) {
        int u=qu.front(); qu.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (layer[e[i]]) continue;
            layer[e[i]]=layer[u]+1;
            f[e[i]][0]=u;
            for (int j=1;j<D;++j) {
                f[e[i]][j]=f[f[e[i]][j-1]][j-1];
            }
            qu.push(e[i]);
        }
    }
}

int lca(int x,int y) {
    if (x==y) return x;
    if (layer[x]<layer[y]) swap(x,y);
    for (int j=D-1;~j;--j) {
        if (layer[f[x][j]]>=layer[y]) {
            x=f[x][j];
        }
    }
    if (x==y) return x;
    for (int j=D-1;~j;--j) {
        if (f[x][j]!=f[y][j]) {
            x=f[x][j];
            y=f[y][j];
        }
    }
    return f[x][0];
}

void add(int x,int& s) {
    if (!sta[x]) {
        if (!cnt[w[x]]) s++;
        cnt[w[x]]++;
    } else {
        cnt[w[x]]--;
        if (!cnt[w[x]]) s--;
    }
    sta[x]^=1;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&w[i]);
        nums.push_back(w[i]);
    }
    sort(nums.begin(),nums.end(),cmp1);
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for (int i=1;i<=n;++i) {
        w[i]=lower_bound(nums.begin(),nums.end(),w[i])-nums.begin();
    }
    for (int i=1;i<=n-1;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add_edge(a,b);
        add_edge(b,a);
    }
    dfs(1,0);
    bfs();
    len=sqrt(idx);
    for (int i=1;i<=m;++i) {
        int l,r;
        scanf("%d %d",&l,&r);
        if (fir[r]<fir[l]) swap(l,r);
        int a=lca(l,r);
        if (l==a) q[i]={i,fir[l],fir[r],0};
        else q[i]={i,last[l],fir[r],a};
    }
    sort(q+1,q+1+m,cmp2);
    for (int k=1,i=0,j=1,s=0;k<=m;++k) {
        int id=q[k].id;
        int l=q[k].l;
        int r=q[k].r;
        int p=q[k].p;
        while (i<r) add(arr[++i],s);
        while (i>r) add(arr[i--],s);
        while (j>l) add(arr[--j],s);
        while (j<l) add(arr[j++],s);
        if (p) add(p,s);
        ans[id]=s;
        if (p) add(p,s);
    }
    for (int i=1;i<=m;++i) {
        printf("%d\n",ans[i]);
    }
    return 0;
}