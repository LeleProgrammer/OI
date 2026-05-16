#include <bits/stdc++.h>
using namespace std;

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

namespace IO {
    inline void read(int &a) {
        int sym=1,num=0;
        char c=getchar();
        while (c<'0' || c>'9') {
            if (c=='-') {
                sym=-1;
            }
            c=getchar();
        }
        while (c>='0' && c<='9') {
            num=num*10+c-'0';
            c=getchar();
        }
        a=sym*num;
    }
    inline void write(int a) {
        if (a<0) {
            putchar('-');
            a*=-1;
        }
        if (a>=10) {
            write(a/10);
        }
        putchar(a%10+'0');
    }
}

using IO::read;

const int N=405;
const int M=400005;
const LL inf=9e18;

typedef pair<LL,int> pii;

int n,m,Q;
int e[M],ne[M],w[M],h[N],tot;
int per[N];
pii b[N];
LL dis[N][N];
bool flag[N];
priority_queue<pii,vector<pii>,greater<pii>> q;

inline void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

inline void dijkstra(int s) {
    _rep(i,1,n) dis[s][i]=inf,flag[i]=false;
    q.push({dis[s][s]=0,s});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (flag[u]) continue;
        flag[u]=true;
        _graph(i,u) if (dis[s][e[i]]>dis[s][u]+w[i] && !flag[e[i]]) q.push({dis[s][e[i]]=dis[s][u]+w[i],e[i]});
    }
}

inline int get_edge(int k) {
    return (k-1)<<1;
}

int main() {
    memset(h,-1,sizeof(h));
    read(n); read(m);
    _rep(i,1,m) {
        int a,b,c;
        read(a); read(b); read(c);
        add(a,b,c);
        add(b,a,c);
    }
    _rep(i,1,n) dijkstra(i);
    read(Q);
    while (Q--) {
        int k;
        read(k);
        LL edgeSum=0;
        _rep(i,1,k) {
            int v;
            read(v);
            int t=get_edge(v);
            b[i]={e[t],e[t^1]};
            edgeSum+=w[t];
        }
        _rep(i,1,k) per[i]=i;
        LL ans=inf;
        do {
            _rep(i,0,(1<<k)-1) {
                LL sum=edgeSum;
                _rep(j,1,k+1) {
                    if (j==1) {
                        if ((i>>(j-1))&1) sum+=dis[1][b[per[j]].second];
                        else sum+=dis[1][b[per[j]].first];
                    } else if (j==k+1) {
                        if ((i>>(j-2))&1) sum+=dis[b[per[j-1]].first][n];
                        else sum+=dis[b[per[j-1]].second][n];
                    } else {
                        sum+=dis[((i>>(j-2))&1)?b[per[j-1]].first:b[per[j-1]].second][((i>>(j-1))&1)?b[per[j]].second:b[per[j]].first];
                    }
                }
                ans=min(ans,sum);
            }
        } while (next_permutation(per+1,per+1+k));
        printf("%lld\n",ans);
    }
    return 0;
}