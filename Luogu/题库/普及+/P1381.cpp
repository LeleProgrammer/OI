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

const int N=1005;
const int M=100005;

int n,m,idx,mx;
int arr[M];
int cnt[N],res;
map<string,int> hs;

void add(int x) {
    if (!x) return;
    if (!cnt[x]) res++;
    cnt[x]++;
}

void del(int x) {
    if (!x) return;
    cnt[x]--;
    if (!cnt[x]) res--;
}

void restore() {
    memset(cnt,0,sizeof(cnt));
    res=0;
}

bool check(int mid) {
    restore();
    _rep(i,1,mid) add(arr[i]);
    if (res==mx) return true;
    int l=1,r=mid;
    while (r<m) {
        del(arr[l++]),add(arr[++r]);
        if (res==mx) return true;
    }
    return false;
}

int main() {
    scanf("%d",&n);
    _rep(i,1,n) {
        string s;
        cin>>s;
        hs[s]=++idx;
    }
    scanf("%d",&m);
    _rep(i,1,m) {
        string s;
        cin>>s;
        arr[i]=hs[s];
    }
    restore();
    _rep(i,1,m) add(arr[i]);
    mx=res;
    printf("%d\n",mx);
    if (!mx) {
        puts("0");
        return 0;
    }
    int l=1,r=m;
    while (l<r) {
        int mid=l+r>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d",r);
    return 0;
}