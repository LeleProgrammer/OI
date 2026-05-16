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

const int N=400005;
const int M=800005;
const int K=30;

int T,n;
int w[N];
int e[M],ne[M],h[N],tot;
int layer[N];
int f[N][K];
queue<int> q;
vector<int> vec[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void bfs() {
    q.emplace(1);
    layer[1]=1;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        _graph(i,u) {
            if (layer[e[i]]) continue;
            layer[e[i]]=layer[u]+1;
            f[e[i]][0]=u;
            _rep(j,1,K-1) f[e[i]][j]=f[f[e[i]][j-1]][j-1];
            q.push(e[i]);
        }
    }
}

int lca(int a,int b) {
    // cout<<"lca1 "<<a<<" "<<b<<" "<<layer[a]<<" "<<layer[b]<<endl;
    if (a==b) return a;
    if (layer[a]<layer[b]) swap(a,b);
    _rrep(i,K-1,0) if (layer[f[a][i]]>=layer[b]) a=f[a][i];
    // cout<<"lca2 "<<a<<" "<<b<<" "<<layer[a]<<" "<<layer[b]<<endl;
    if (a==b) return a;
    _rrep(i,K-1,0) if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
    // cout<<"lca3 "<<a<<" "<<b<<" "<<layer[a]<<" "<<layer[b]<<endl;
    return f[a][0];
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n); tot=0;
        _rep(i,1,n) {
            h[i]=-1,layer[i]=0,vec[i].clear();
            _rep(j,0,K-1) f[i][j]=0;
        }
        vector<int> dif;
        _rep(i,1,n) scanf("%d",&w[i]),vec[w[i]].emplace_back(i),dif.emplace_back(w[i]);
        _rep(i,1,n-1) {
            int a,b;
            scanf("%d %d",&a,&b);
            add(a,b); add(b,a);
        }
        bfs();
        sort(dif.begin(),dif.end());
        dif.erase(unique(dif.begin(),dif.end()),dif.end());
        reverse(dif.begin(),dif.end());
        // printf("lay:"); _rep(i,1,n) printf("%d ",layer[i]); putchar(10);
        int ans=0;
        _rep(i,0,(int)dif.size()-2) {
            // cout<<"TEST: "<<dif[i]<<endl;
            int g=vec[dif[i]][0];
            // cout<<g<<endl;
            _rep(j,1,(int)vec[dif[i]].size()-1) g=lca(g,vec[dif[i]][j]);
            _rep(j,0,(int)vec[dif[i+1]].size()-1) {
                int k=lca(g,vec[dif[i+1]][j]);
                // cout<<g<<" "<<vec[dif[i+1]][j]<<" "<<k<<endl;
                if (k!=vec[dif[i+1]][j]) {
                    ans=vec[dif[i+1]][j];
                    break;
                }
            }
            if (ans) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}