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
const int M=1005;
const int K=200005;
const int P=205;
const int mod=998244353;

int n,m,k;
int e[M],w[M],ne[M],h[N],tot;
bool flag[N];
pii edges[M];
vector<int> vec;

unordered_map<int,int> rhs;
int idx;

int f[P][K];

void add(int a,int b,int c) {
    // cout<<a<<" "<<b<<" "<<c<<endl;
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

bool cmp(const int& a,const int& b) {
    return a<b;
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld %lld",&n,&m,&k);
    _rep(i,1,m) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        edges[i]={a,b};
        flag[a]=true;
        flag[b]=true;
    }
    _rep(i,1,n) if (flag[i] || i==1) rhs[i]=++idx,vec.emplace_back(i);
    _rep(i,1,m) add(rhs[edges[i].first],rhs[edges[i].second],1);
    sort(vec.begin(),vec.end(),cmp);
    _rep(i,0,(int)vec.size()-2) add(rhs[vec[i]],rhs[vec[i+1]],vec[i+1]-vec[i]);
    add(rhs[vec.back()],rhs[1],1+n-vec.back());
    _rep(u,1,idx) f[u][0]=1;
    _rep(t,1,k) _rep(u,1,idx) _graph(i,u) f[u][t]=(f[u][t]+((t-w[i]>=0)?f[e[i]][t-w[i]]:1))%mod;
    printf("%lld\n",f[rhs[1]][k]);
    // _rep(t,1,k) _rep(u,1,idx) printf("f[%lld][%lld] = %lld\n",u,t,f[u][t]);
    return 0;
}

/*
10 1 3
1 10
*/

/*
10 1 2
1 5
*/