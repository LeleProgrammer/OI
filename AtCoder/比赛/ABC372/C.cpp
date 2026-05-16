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

int n,Q,cnt;
char s[N];

int main() {
    scanf("%d %d",&n,&Q);
    scanf("%s",s+1);
    _rep(i,1,n-2) if (s[i]=='A' && s[i+1]=='B' && s[i+2]=='C') cnt++;
    while (Q--) {
        int x;
        char c;
        scanf("%d %c",&x,&c);
        if (s[x]=='A' && s[x+1]=='B' && s[x+2]=='C') cnt--;
        else if (x>=1 && s[x-1]=='A' && s[x]=='B' && s[x+1]=='C') cnt--;
        else if (x>=2 && s[x-2]=='A' && s[x-1]=='B' && s[x]=='C') cnt--;
        s[x]=c;
        if (s[x]=='A' && s[x+1]=='B' && s[x+2]=='C') cnt++;
        else if (x>=1 && s[x-1]=='A' && s[x]=='B' && s[x+1]=='C') cnt++;
        else if (x>=2 && s[x-2]=='A' && s[x-1]=='B' && s[x]=='C') cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}