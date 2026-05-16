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

int a,b,c;
int cnt[5];

void process(int k) {
    if (k>=85) cnt[0]++;
    else if (k>=45) cnt[1]++;
    else if (k>=25) cnt[2]++;
    else if (k>=1) cnt[3]++;
    else cnt[4]++;
}

int main() {
    scanf("%d %d %d",&a,&b,&c);
    process(a),process(b),process(c);
    if (cnt[1]==1 && cnt[2]==1 && cnt[3]==1) puts("Yes");
    else if (cnt[0]==1 && cnt[1]==1 && cnt[2]==1) puts("Yes");
    else if (cnt[0]==2 && (cnt[1]==1 || cnt[2]==1)) puts("Yes");
    else if (cnt[0]==3) puts("Yes");
    else puts("No");
    return 0;
}