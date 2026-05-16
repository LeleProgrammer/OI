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

const int N=1000005;
const int M=10;

int n,m;
char s[N],t[N];
vector<int> pos[M];
bool changed[N];
int flag[N];

int main() {
    scanf("%d %d",&n,&m);
    scanf("%s %s",s+1,t+1);
    _rep(i,1,m) pos[t[i]-'0'].emplace_back(i);
    _rep(i,1,n) {
        _rrep(j,9,s[i]-'0'+1) {
            if (!pos[j].empty()) {
                changed[i]=true;
                flag[pos[j].back()]=i;
                pos[j].pop_back();
                break;
            }
        }
    }
    _rep(i,1,n) {
        if (changed[i]) continue;
        if (!pos[s[i]-'0'].empty()) {
            flag[pos[s[i]-'0'].back()]=i;
            pos[s[i]-'0'].pop_back();
        }
    }
    // _rep(i,1,m) printf("%d ",flag[i]); putchar(10);
    bool ok=false;
    _rrep(i,m,1) {
        if (flag[i]) ok=true;
        else if (ok) flag[i]=n+1;
    }
    // _rep(i,1,m) printf("%d ",flag[i]); putchar(10);
    int las=0;
    _rrep(i,m,1) {
        if (!flag[i]) {
            las=t[i]-'0';
            break;
        }
    }
    _rep(i,1,m) s[flag[i]]=t[i];
    if (las) s[n]=las+'0';
    _rep(i,1,n) putchar(s[i]);
    return 0;
}