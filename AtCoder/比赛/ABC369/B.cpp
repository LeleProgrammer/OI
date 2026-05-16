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

const int N=105;

int n;
int l=-1,r=-1;
int ans;

int main() {
    scanf("%d",&n);
    while (n--) {
        int a;
        char s;
        scanf("%d %c",&a,&s);
        if (s=='L') {
            if (l!=-1) ans+=abs(l-a);
            l=a;
        } else {
            if (r!=-1) ans+=abs(r-a);
            r=a;
        }
    }
    printf("%d",ans);
    return 0;
}