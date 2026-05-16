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

const int N=400005;

int n,m,q,ans;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int p[4][N];
bool flag[N];

int get(int i,int j) {
    if (!i || !j || i==n+1 || j==m+1) return 0;
    return (i-1)*m+j;
}

pii get(int i) {
    if (i%m) return {i/m+1,i%m};
    else return {i/m,m};
}

int find(int x,int i) {
    if (p[i][x]==x) return p[i][x];
    return p[i][x]=find(p[i][x],i);
}

bool check(int i,int j) {
    return i>=1 && i<=n && j>=1 && j<=m;
}

void merge(int i,int j,int k) {
    // cout<<"merge: "<<i<<" "<<j<<" "<<k<<endl;
    // cout<<"m: "<<find(i,k)<<" "<<find(j,k)<<endl;
    p[k][find(i,k)]=find(j,k);
    // cout<<"stop merge"<<endl;
}

void init(int a,int b) {
    flag[get(a,b)]=true;
    _rep(t,0,3) {
        int pos=get(a,b);
        int npos=find(pos,t);
        auto np=get(npos);
        // cout<<"T2: "<<np.first<<" "<<np.second<<endl;
        np.first+=dx[t];
        np.second+=dy[t];
        merge(pos,get(np.first,np.second),t);
    }
}

signed main() {
    scanf("%lld %lld %lld",&n,&m,&q); ans=n*m;
    _rep(i,0,3) _rep(j,1,n*m) p[i][j]=j;
    while (q--) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        // printf("flag[%d][%d] = %d\n",a,b,flag[get(a,b)]);
        if (!flag[get(a,b)]) {
            init(a,b);
            ans--;
            continue;
        }
        _rep(t,0,3) {
            int pos=get(a,b);
            int npos=find(pos,t);
            auto np=get(npos);
            if (!check(np.first,np.second)) continue;
            // cout<<"TEST: "<<np.first<<" "<<np.second<<endl;
            // flag[get(np.first,np.second)]=true;
            init(np.first,np.second);
            // printf("set flag[%d][%d] = %d\n",np.first,np.second,flag[get(np.first,np.second)]);
            np.first+=dx[t];
            np.second+=dy[t];
            ans--;
            if (!check(np.first,np.second)) merge(pos,0,t);
            else {
                merge(pos,get(np.first,np.second),t);
                merge(npos,pos,t^1);
            }
        }
        // cout<<"TEST: "<<ans<<endl;
    }
    printf("%lld",ans);
    return 0;
}