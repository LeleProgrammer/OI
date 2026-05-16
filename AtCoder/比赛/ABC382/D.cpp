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

const int N=15;

int n,m,cnt;
int arr[N];

void print1() {
    cnt++;
}

void print2() {
    _rep(i,1,n) printf("%d ",arr[i]);
    putchar(10);
}

void dfs1(int pos) {
    if (pos==n+1) print1();
    else {
        _rep(i,arr[pos-1]+10,m-10*(n-pos)) {
            arr[pos]=i;
            dfs1(pos+1);
        }
    }
}

void dfs2(int pos) {
    if (pos==n+1) print2();
    else {
        _rep(i,arr[pos-1]+10,m-10*(n-pos)) {
            arr[pos]=i;
            dfs2(pos+1);
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    arr[0]=-9;
    dfs1(1);
    printf("%d\n",cnt);
    dfs2(1);
    return 0;
}