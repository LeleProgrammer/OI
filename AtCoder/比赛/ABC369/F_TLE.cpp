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

const int N=200005;
const int inf=2e9;

int n,m,k;
vector<int> arr[N];
string ans;
map<pair<int,int>,pair<int,int>> hs;
set<pair<int,int>> st;
int las=1;
bool fir;

struct SegmentTree {
    int l,r;
    int max;
    int pos;
} tr[N<<2];

void pushup(int u) {
    tr[u].max=max(tr[u<<1].max,tr[u<<1|1].max);
    if (tr[u].max==tr[u<<1].max) tr[u].pos=tr[u<<1].pos;
    else tr[u].pos=tr[u<<1|1].pos;
}

void build(int u,int l,int r) {
    tr[u]={l,r,0,l};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int p,int k) {
    if (tr[u].l==p && tr[u].r==p) {
        tr[u].max=k;
        return;
    }
    int mid=tr[u].l+tr[u].r>>1;
    if (p<=mid) modify(u<<1,p,k);
    else modify(u<<1|1,p,k);
    pushup(u);
}

SegmentTree max(SegmentTree a,SegmentTree b) {
    SegmentTree ans={0,0,-inf,0};
    ans.max=max(a.max,b.max);
    if (ans.max==a.max) ans.pos=a.pos;
    else ans.pos=b.pos;
    return ans;
}

SegmentTree query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    int mid=tr[u].l+tr[u].r>>1;
    SegmentTree ans={0,0,-inf,0};
    if (l<=mid) ans=max(ans,query(u<<1,l,r));
    if (r>mid) ans=max(ans,query(u<<1|1,l,r));
    return ans;
}

int main() {
    scanf("%d %d %d",&n,&m,&k);
    build(1,1,m);
    _rep(i,1,k) {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a].emplace_back(b);
    }
    _rep(i,1,n) if (!arr[i].empty()) sort(arr[i].begin(),arr[i].end());
    _rep(i,1,n) {
        if (arr[i].empty()) continue;
        _iter(it,arr[i]) {
            int j=(*it);
            auto t=query(1,1,j);
            modify(1,j,t.max+1);
            hs[{i,j}]={las,t.pos};
            st.insert({i,j});
            las=i;
        }
    }
    auto t=query(1,1,m);
    printf("%d\n",t.max);
    if (!st.count({n,m})) hs[{n,m}]={las,t.pos};
    // _iter(it,hs) {
    //     auto a=it->first,b=it->second;
    //     printf("{%d,%d} -> {%d,%d}\n",a.first,a.second,b.first,b.second);
    // }
    pair<int,int> now={n,m};
    while (true) {
        while (!hs.count(now) || hs[now]==now) {
            if (now.first==1) {
                while (now.second>1) {
                    now.second--;
                    ans.push_back('R');
                }
                break;
            }
            now.first--;
            ans.push_back('D');
            if (now.first==1 && now.second==1) break;
        }
        auto t=hs[now];
        while (now.first>t.first) {
            now.first--;
            ans.push_back('D');
        }
        while (now.second>t.second) {
            now.second--;
            ans.push_back('R');
        }
        if (now.first==1 && now.second==1) break;
    }
    reverse(ans.begin(),ans.end());
    printf("%s",ans.c_str());
    return 0;
}

/*
5 6 7
1 1
1 4
1 5
2 3
3 1
4 2
5 6
*/