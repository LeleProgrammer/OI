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

const int N=15;

int m;
int pw[N];
vector<int> vec;

int main() {
    scanf("%d",&m);
    pw[0]=1;
    _rep(i,1,10) pw[i]=pw[i-1]*3;
    int i=10;
    while (true) {
        if (i==-1) break;
        if (pw[i]>m) {
            i--;
            continue;
        }
        vec.emplace_back(i);
        m-=pw[i];
        if (!m) break;
    }
    printf("%d\n",vec.size());
    _iter(it,vec) printf("%d ",*it);
    return 0;
}