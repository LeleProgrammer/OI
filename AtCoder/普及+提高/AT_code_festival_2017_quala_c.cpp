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

const int N=105;
const int M=35;

int n,m;
char arr[N][N];
int cnt[M];
int cnt4,cnt2,cnt1;

int main() {
    scanf("%d %d",&n,&m);
    _rep(i,1,n) _rep(j,1,m) scanf(" %c",&arr[i][j]),cnt[arr[i][j]-'a']++;
    _rep(i,1,n/2+n%2) {
        int a;
        if (i==n/2+n%2 && n%2==1) a=1;
        else a=2;
        _rep(j,1,m/2+m%2) {
            int b;
            if (j==m/2+m%2 && m%2==1) b=1;
            else b=2;
            int t=a*b;
            if (t==1) cnt1++;
            else if (t==2) cnt2++;
            else cnt4++;
        }
    }
    _rep(i,0,25) {
        while (cnt[i]>=4 && cnt4) cnt[i]-=4,cnt4--;
        while (cnt[i]>=2 && cnt2) cnt[i]-=2,cnt2--;
        while (cnt[i]>=1 && cnt1) cnt[i]--,cnt1--;
    }
    if (!cnt1 && !cnt2 && !cnt4) puts("Yes");
    else puts("No");
    return 0;
}