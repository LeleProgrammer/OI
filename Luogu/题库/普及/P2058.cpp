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

const int N=100005;

int n,ans;
int cnt[N];
int res[N];

struct Data {
    int t,k,i;
    vector<int> vec;
    bool operator < (const Data& a) const {
        return t<a.t;
    }
} arr[N];

queue<Data> q;

void add(int k) {
    if (!cnt[k]) ans++;
    cnt[k]++;
}

void del(int k) {
    cnt[k]--;
    if (!cnt[k]) ans--;
}

int main() {
    scanf("%d",&n);
    _rep(i,1,n) {
        int t,k;
        scanf("%d %d",&t,&k);
        arr[i]={t,k,i};
        _rep(j,1,k) {
            int v;
            scanf("%d",&v);
            arr[i].vec.emplace_back(v);
        }
    }
    sort(arr+1,arr+1+n);
    _rep(i,1,n) {
        auto &cur=arr[i];
        while (!q.empty() && cur.t-q.front().t>=86400) {
            _rep(j,0,q.front().k-1) del(q.front().vec[j]);
            q.pop();
        }
        _rep(j,0,cur.k-1) add(cur.vec[j]);
        q.push(cur);
        res[arr[i].i]=ans;
    }
    _rep(i,1,n) printf("%d\n",res[i]);
    return 0;
}