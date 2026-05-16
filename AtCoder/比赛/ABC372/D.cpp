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
typedef pair<int,int> pii;

const int N=200005;

int n;
int arr[N];
int ans[N];
stack<int> stk;

int main() {
    scanf("%d",&n);
    _rep(i,1,n) scanf("%d",&arr[i]);
    _rrep(i,n,1) {
        ans[i]=stk.size();
        while (!stk.empty() && stk.top()<arr[i]) stk.pop();
        stk.push(arr[i]);
    }
    _rep(i,1,n) printf("%d ",ans[i]);
    return 0;
}