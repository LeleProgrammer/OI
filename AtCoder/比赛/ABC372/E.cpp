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

int n,Q;
int p[N];
vector<int> vec[N];

bool cmp(const int& a,const int& b) {
    return a>b;
}

int find(int x) {
    return (p[x]==x)?p[x]:(p[x]=find(p[x]));
}

int main() {
    scanf("%d %d",&n,&Q);
    _rep(i,1,n) vec[i].emplace_back(i);
    _rep(i,1,n) p[i]=i;
    while (Q--) {
        int op,a,b;
        scanf("%d %d %d",&op,&a,&b);
        if (op==1) {
            int pa,pb;
            pa=find(a);
            pb=find(b);
            if (pa==pb) continue;
            p[pb]=pa;
            _iter(it,vec[pb]) vec[pa].emplace_back(*it);
            sort(vec[pa].begin(),vec[pa].end(),cmp);
            while (vec[pa].size()>10) vec[pa].pop_back();
        } else if (op==2) {
            int pa=find(a);
            if (vec[pa].size()<b) puts("-1");
            else printf("%d\n",vec[pa][b-1]);
        }
    }
    return 0;
}