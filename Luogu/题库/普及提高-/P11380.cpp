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
typedef pair<int,int> pii;

const int N=200005;
const int mod=1e9+7;

int n,m;
int p[N];
int L[N],R[N];
unordered_set<int> hs;

int find(int x) {
    return (p[x]==x)?p[x]:(p[x]=find(p[x]));
}

void merge(int a,int b) {
    p[find(a)]=find(b);
    L[a]=b,R[b]=a;
}

int main() {
    scanf("%d %d",&n,&m);
    _rep(i,1,n) p[i]=i;
    bool ok=true;
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        if (!L[a] && !R[b] && find(a)!=find(b)) merge(a,b);
        else if (!(L[a]==b && R[b]==a)) ok=false;
        else merge(a,b);
    }
    if (!ok) {
        puts("0");
        return 0;
    }
    LL ans=1;
    _rep(i,1,n) hs.emplace(find(i));
    _rep(i,2,(int)hs.size()) ans=ans*i%mod;
    printf("%lld",ans);
    return 0;
}