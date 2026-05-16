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

int n,m;

struct odt {
    int l,r;
    mutable int v;
    odt(const int& ll,const int& rr,const int& vv) : l(ll),r(rr),v(vv) {}
    friend bool operator < (const odt& a,const odt& b) {
        return a.l<b.l;
    }
};

set<odt> arr;

auto split(int x) {
    auto it=arr.lower_bound(odt{x,0,0});
    if (it!=arr.end() && it->l==x) return it;
    --it;
    int l=it->l,r=it->r,v=it->v;
    arr.erase(it);
    arr.insert(odt{l,x-1,v});
    return arr.insert(odt{x,r,v}).first;
}

void assign(int l,int r,int v) {
    auto R=split(r+1),L=split(l);
    arr.erase(L,R);
    arr.insert(odt{l,r,v});
}

int main() {
    scanf("%d %d",&n,&m);
    arr.insert(odt{1,n+1,1});
    while (m--) {
        int l,r;
        scanf("%d %d",&l,&r);
        assign(l,r,0);
        int ans=0;
        _iter(it,arr) if (it->v) ans+=it->r-it->l+1;
        printf("%d\n",ans-1);
    }
    return 0;
}