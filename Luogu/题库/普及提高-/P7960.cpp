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

const int N=15000005;

int T;
int flag[N];
int pre[N];

bool check(int k) {
    while (k) {
        int t=k%10;
        k/=10;
        if (t==7) return true;
    }
    return false;
}

void init() {
    _rep(i,1,N-1) flag[i]=1;
    _rep(i,1,N-1) {
        if (!check(i)) continue;
        _reps(j,i,N-1,j+=i) flag[j]=0;
    }
    _rep(i,1,N-1) pre[i]=pre[i-1]+flag[i];
}

int main() {
    init();
    scanf("%d",&T);
    while (T--) {
        int x;
        scanf("%d",&x);
        if (!flag[x]) {
            puts("-1");
            continue;
        }
        _rrep(i,30,0) {
            int j=x+(1<<i);
            if (j>=N) continue;
            if (pre[j]==pre[x]) x=j;
        }
        printf("%d\n",x+1);
    }
    return 0;
}