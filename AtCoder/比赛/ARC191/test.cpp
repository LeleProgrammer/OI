#include <bits/stdc++.h>
using namespace std;

#define int long long

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

// int main() {
//     while (true) {
//         int k;
//         cin>>k;
//         if (k==-1) break;
//         printf("%d:\n",k);
//         vector<int> ans;
//         while (k) ans.emplace_back(k&1),k>>=1;
//         reverse(ans.begin(),ans.end());
//         _iter(it,ans) printf("%d",*it);
//         putchar(10);
//     }
//     return 0;
// }

void sieve(int k) {
    printf("sieve %lld:\n",k);
    _rep(i,2,sqrt(k+1)) {
        if (k%i==0) {
            printf("%lld: ",i);
            int cnt=0;
            while (k%i==0) k/=i,cnt++;
            printf("%lld\n",cnt);
        }
    }
    if (k!=1) {
        printf("%lld: ",k);
        printf("1\n");
    }
}

signed main() {
    int j=11;
    _rep(i,1,20) {
        sieve(j-1);
        j<<=1;
    }
    return 0;
}