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

const int N=200005;

int n;
int arr[N],rot[N];
int p[N],s[N];
int ans;
deque<int> q;
priority_queue<int> qq;

void add_0() {
    ans+=((n>>1)-1)*(n>>1);
}

void add_1() {
    ans++;
}

signed main() {
    scanf("%lld",&n);
    _rep(i,1,n) scanf("%lld",&arr[i]),rot[arr[i]]=i;
    // _rep(i,1,n) {
    //     _rep(j,1,n) {
    //         if (arr[i]==j) printf("1 ");
    //         else printf("0 ");
    //     }
    //     putchar(10);
    // }
    int k=0;
    _rep(i,1,n>>1) {
        if (arr[i]<=(n>>1)) k++;
    }
    p[1]=k;
    _rep(i,1,(n>>1)+1) {
        if (i!=1) {
            p[i]=p[i-1];
            if (arr[i-1]<=(n>>1)) p[i]--;
            if (arr[i+(n>>1)-1]<=(n>>1)) p[i]++;
        }
    }
    // printf("p: "); _rep(i,1,n) printf("%lld ",p[i]); putchar(10);
    _rep(i,1,n) {
        while (!q.empty() && i-q.front()+1>(n>>1)) q.pop_front();
        if (arr[i]<=(n>>1)) {
            while (!q.empty() && arr[q.back()]<arr[i]) q.pop_back();
            q.emplace_back(i);
        }
        if (i>=(n>>1)-1) {
            if (q.empty()) s[i-(n>>1)+1]=0;
            else s[i-(n>>1)+1]=arr[q.front()];
        }
    }
    // printf("s: "); _rep(i,1,n) printf("%lld ",s[i]); putchar(10);
    _rep(i,1,(n>>1)+1) {
        // printf("%lld :: ",i);
        int A=i,B=i+(n>>1)-1;
        int j=(n>>1);
        int cnt=p[i];
        int mx=s[i];
        // printf("%lld ",cnt);
        while (j<=n) {
            if (!cnt) add_0();
            else if (cnt==1) add_1();
            // else if (mx>((n>>1)+1)) break;
            if (j==n) break;
            if (A<=rot[j+1] && rot[j+1]<=B) cnt++,mx=j+1;
            if (A<=rot[j-(n>>1)+1] && rot[j-(n>>1)+1]<=B) cnt--;
            // printf("%lld ",cnt);
            ++j;
        }
        // putchar(10);
        // printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}