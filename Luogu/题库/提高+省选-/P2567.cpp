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

const int N=3005;

int a,b,ans;
int arr[N],n;

void bfs() {
    queue<int> q;
    q.emplace(0);
    while (!q.empty()) {
        int num=q.front(); q.pop();
        if (num>b) continue;
        if (num) {
            bool ok=true;
            _rep(i,1,n) {
                if (num%arr[i]==0) {
                    ok=false;
                    break;
                }
            }
            if (ok) arr[++n]=num;
        }
        q.emplace(num*10+6);
        q.emplace(num*10+8);
    }
}

int gcd(int a,int b) {
    if (!b) return a;
    else return gcd(b,a%b);
}

__int128 lcm(int a,int b) {
    return (__int128)a/gcd(a,b)*b;
}

void dfs(int pos,int cnt,__int128 cur) {
    if (cur>b) return;
    if (pos>n) {
        int k=b/cur-a/cur;
        if (a%cur==0) k++;
        if (cnt&1) ans+=k;
        else if (cnt) ans-=k;
        return;
    }
    dfs(pos+1,cnt,cur);
    if (lcm(cur,arr[pos])<=b) dfs(pos+1,cnt+1,lcm(cur,arr[pos]));
    return;
}

bool cmp(const int& a,const int& b) {
    return a>b;
}

signed main() {
    scanf("%lld %lld",&a,&b);
    bfs();
    sort(arr+1,arr+1+n,cmp);
    dfs(1,0,1);
    printf("%lld",ans);
    return 0;
}