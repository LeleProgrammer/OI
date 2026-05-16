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

const int N=100005;

int T,n;
int s1[N],s2[N],t1[N],t2[N];
int d1[N],d2[N];
int cnt1[N][2],cnt2[N][2];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        _rep(i,1,n) scanf("%1d",&s1[i]);
        _rep(i,1,n) scanf("%1d",&s2[i]);
        _rep(i,1,n) scanf("%1d",&t1[i]);
        _rep(i,1,n) scanf("%1d",&t2[i]);
        _rep(i,1,n) cnt1[i][0]=cnt1[i][1]=cnt2[i][0]=cnt2[i][1]=d1[i]=d2[i]=0;
        d1[1]=1;
        _rep(i,2,n) {
            if (t1[i] && t1[i-1]) d1[i]=d1[i-1];
            else d1[i]=d1[i-1]+1;
        }
        d2[1]=1;
        _rep(i,2,n) {
            if (t2[i] && t2[i-1]) d2[i]=d2[i-1];
            else d2[i]=d2[i-1]+1;
        }
        _rep(i,1,n) {
            cnt1[d1[i]][s1[i]]++;
            cnt2[d2[i]][s2[i]]++;
        }
        // printf("d1: ");
        // _rep(i,1,n) {
        //     printf("%d",d1[i]);
        // }
        // putchar(10);
        // printf("d2: ");
        // _rep(i,1,n) {
        //     printf("%d",d2[i]);
        // }
        // putchar(10);
        int ans=0;
        _rep(i,1,n) {
            int &a0=cnt1[d1[i]][0];
            int &a1=cnt1[d1[i]][1];
            int &b0=cnt2[d2[i]][0];
            int &b1=cnt2[d2[i]][1];
            if (a0 && b0) a0--,b0--,ans++;
            else if (a1 && b1) a1--,b1--,ans++;
            else {
                if (a0) a0--;
                else a1--;
                if (b0) b0--;
                else b1--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}