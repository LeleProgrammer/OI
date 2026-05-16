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

const int N=550005;
const int M=1005;
const int inf=1e18;

int n,m,len;
int a[N],pre[N],his[N],tag[M],taghis[M];
pii arr[N];
int L[N],R[N],B[N],Bn;

bool cmp(pii a,pii b) {
    return a.first<b.first;
}

inline void pushtag(int x) {
    _rep(i,L[x],R[x]) his[i]=max(his[i],a[i]+taghis[x]),a[i]+=tag[x];
    tag[x]=0,taghis[x]=0;
}

inline void rebuild(int x) { // x-th block
    // printf("REBUILD %lld: [%lld,%lld]\n",x,L[x],R[x]);
    _rep(i,L[x],R[x]) arr[i]={a[i],his[i]};
    sort(arr+L[x],arr+R[x]+1);
    pre[L[x]]=arr[L[x]].second;
    _rep(i,L[x]+1,R[x]) pre[i]=max(pre[i-1],arr[i].second);
}

inline void modify(int l,int r,int x) {
    if (B[l]!=B[r]) {
        _rep(i,B[l]+1,B[r]-1) tag[i]+=x,taghis[i]=max(taghis[i],tag[i]);
        pushtag(B[l]),pushtag(B[r]);
        _rep(i,l,R[B[l]]) a[i]+=x,his[i]=max(his[i],a[i]);
        _rep(i,L[B[r]],r) a[i]+=x,his[i]=max(his[i],a[i]);
        rebuild(B[l]),rebuild(B[r]);
    } else {
        pushtag(B[l]);
        _rep(i,l,r) a[i]+=x,his[i]=max(his[i],a[i]);
        rebuild(B[l]);
    }
}

inline int query(int l,int r,int x) {
    int ans=-inf;
    if (B[l]!=B[r]) {
        _rep(i,B[l]+1,B[r]-1) {
            int p=lower_bound(arr+L[i],arr+R[i]+1,pii{x-tag[i],114514LL},cmp)-(arr+1);
            if (p<L[i]) continue;
            ans=max(ans,max(pre[p],arr[p].first+taghis[i]));
        }
        _rep(i,l,R[B[l]]) if (a[i]+tag[B[i]]<x) ans=max(ans,max(his[i],a[i]+taghis[B[i]]));
        _rep(i,L[B[r]],r) if (a[i]+tag[B[i]]<x) ans=max(ans,max(his[i],a[i]+taghis[B[i]]));
    } else {
        _rep(i,l,r) if (a[i]+tag[B[i]]<x) ans=max(ans,max(his[i],a[i]+taghis[B[i]]));
    }
    return ans;
}

inline void test() {
    puts("========");
    printf("B: "); _rep(i,1,n) printf("%lld ",B[i]); putchar(10);
    printf("a: "); _rep(i,1,n) printf("%lld ",a[i]); putchar(10);
    printf("arr: "); _rep(i,1,n) printf("(%lld,%lld) ",arr[i].first,arr[i].second); putchar(10);
    printf("his: "); _rep(i,1,n) printf("%lld ",his[i]); putchar(10);
    printf("pre: "); _rep(i,1,n) printf("%lld ",pre[i]); putchar(10);
    printf("tag: "); _rep(i,1,n) printf("%lld ",tag[B[i]]); putchar(10);
    printf("taghis: "); _rep(i,1,n) printf("%lld ",taghis[B[i]]); putchar(10);
}

signed main() {
    scanf("%lld %lld",&n,&m); len=sqrt(n);
    _rep(i,1,n) scanf("%lld",&a[i]);
    memset(B,-1,sizeof(B));
    _rep(i,1,n) Bn=B[i]=i/len,L[B[i]]=B[i]==B[i-1]?L[B[i-1]]:i;
    _rrep(i,n,1) R[B[i]]=B[i]==B[i+1]?R[B[i+1]]:i;
    _rep(i,1,n) his[i]=-inf;
    _rep(i,0,Bn) rebuild(i);
    while (m--) {
        int o,l,r,x;
        scanf("%lld %lld %lld %lld",&o,&l,&r,&x);
        if (o==1) modify(l,r,x);
        else {
            int ans=query(l,r,x);
            if (ans==-inf) puts("-inf");
            else printf("%lld\n",ans);
        }
    }
    return 0;
}