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

const int N=3000005;

int T,n;
char s[N];
bool flag[N];
queue<int> a;
queue<pii> b;

struct Info {
    int a,b,c;
};

vector<Info> ans;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%s",s+1); n=strlen(s+1);
        while (!a.empty()) a.pop();
        while (!b.empty()) b.pop();
        ans.clear();
        _rep(i,1,n) flag[i]=false;
        _rep(i,1,n) {
            if (s[i]=='A') a.emplace(i);
            else if (s[i]=='P') {
                if (a.empty()) continue;
                b.push({a.front(),i});
                a.pop();
            } else if (s[i]=='C') {
                if (b.empty()) continue;
                ans.emplace_back(Info{b.front().first,b.front().second,i});
                flag[b.front().first]=true;
                flag[b.front().second]=true;
                flag[i]=true;
                b.pop();
            }
        }
        int cnt=0;
        _rep(i,1,n) if (flag[i]) cnt++;
        if (cnt==n) printf("Perfect");
        else _rep(i,1,n) if (!flag[i]) putchar(s[i]);
        putchar(10);
        printf("%d\n",ans.size());
        _iter(it,ans) printf("%d %d %d\n",it->a,it->b,it->c);
    }
    return 0;
}