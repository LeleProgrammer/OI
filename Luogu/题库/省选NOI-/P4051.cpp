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

int n,m;
char s[N];
int sa[N],lsh[N],cnt[N],st[N];
vector<int> vec;

void get_sa() {
    _rep(i,1,n) cnt[lsh[i]=s[i]]++;
    _rep(i,2,m) cnt[i]+=cnt[i-1];
    _rrep(i,n,1) sa[cnt[lsh[i]]--]=i;
    _reps(k,1,n,k<<=1) {
        int idx=0;
        _rep(i,n-k+1,n) st[++idx]=i;
        _rep(i,1,n) if (sa[i]>k) st[++idx]=sa[i]-k;
        _rep(i,1,m) cnt[i]=0;
        _rep(i,1,n) cnt[lsh[i]]++;
        _rep(i,2,m) cnt[i]+=cnt[i-1];
        _rrep(i,n,1) sa[cnt[lsh[st[i]]]--]=st[i],st[i]=0;
        swap(lsh,st);
        idx=1,lsh[sa[1]]=1;
        _rep(i,2,n) lsh[sa[i]]=(st[sa[i]]==st[sa[i-1]] && st[sa[i]+k]==st[sa[i-1]+k])?idx:++idx;
        if (idx==n) break;
        m=idx;
    }
}

int main() {
    scanf("%s",s+1); n=strlen(s+1);
    _rep(i,1,n) s[n+i]=s[i];
    n<<=1;
    m=127;
    get_sa();
    _rep(i,1,n) if (sa[i]<=(n>>1)) vec.emplace_back(sa[i]);
    _iter(it,vec) putchar(s[(*it)+(n>>1)-1]);
    return 0;
}