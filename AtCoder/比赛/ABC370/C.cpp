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

string s,t;
vector<int> a,b;
vector<string> ans;

int main() {
    cin>>s>>t;
    if (s==t) {
        puts("0");
        return 0;
    }
    _rep(i,0,s.size()-1) {
        if (s[i]<t[i]) a.emplace_back(i);
        else if (s[i]>t[i]) b.emplace_back(i);
    }
    _rep(i,0,((int)b.size())-1) {
        s[b[i]]=t[b[i]];
        ans.emplace_back(s);
    }
    _rrep(i,((int)a.size())-1,0) {
        s[a[i]]=t[a[i]];
        ans.emplace_back(s);
    }
    printf("%d\n",ans.size());
    _rep(i,0,ans.size()-1) cout<<ans[i]<<endl;
    return 0;
}