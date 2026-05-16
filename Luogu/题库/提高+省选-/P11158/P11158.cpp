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
int arr[N];
int p[N];
int ans;

struct Seg {
    int l,r;
    int cnt;
} tr[N<<2];

void add_0() {
    ans+=((n>>1)-1)*(n>>1);
}

void add_1() {
    ans++;
}

void add_1(int k) {
    ans+=k;
}

void pushup(int u) {
    tr[u].cnt=tr[u<<1].cnt+tr[u<<1|1].cnt;
}

void build(int u,int l,int r) {
    tr[u]={l,r,p[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int p,int k) {
    // cout<<tr[u].l<<" "<<tr[u].r<<" "<<p<<" "<<k<<endl;
    if (tr[u].l==p && tr[u].r==p) tr[u].cnt=k;
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if (p<=mid) modify(u<<1,p,k);
        else modify(u<<1|1,p,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].cnt;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query(u<<1,l,r);
    if (r>mid) ans+=query(u<<1|1,l,r);
    return ans;
}

int get_nearest_1(int pos) {
    if (query(1,pos,pos)) return pos;
    if (pos==n) return n+1;
    _rrep(i,20,0) {
        int k=pos+(1<<i);
        int r=min(k,n);
        int ret=query(1,pos,r);
        if (!ret && r==n) break;
        else if (ret) continue;
        pos+=(1<<i);
    }
    if (query(1,pos+1,pos+1)) return pos+1;
    return n+1;
}

int get_rev_nearest_1(int pos) {
    if (query(1,pos,pos)) return pos;
    if (pos==1) return 0;
    _rrep(i,20,0) {
        int k=pos-(1<<i);
        int r=max(k,1LL);
        int ret=query(1,r,pos);
        if (!ret && r==1) break;
        else if (ret) continue;
        pos-=(1<<i);
    }
    if (query(1,pos-1,pos-1)) return pos-1;
    return 0;
}

// void test() {
//     n=4;
//     p[1]=1;
//     p[2]=0;
//     p[3]=1;
//     p[4]=0;
//     build(1,1,n);
//     printf("%d\n",get_nearest_1(4));
// }

// void test() {
//     cout<<"TEST: "<<endl;
//     _rep(i,1,n) printf("%lld ",query(1,i,i));
//     putchar(10);
// }

signed main() {
    // test();
    scanf("%lld",&n);
    _rep(i,1,n) scanf("%lld",&arr[i]);
    // _rep(i,1,n) {
    //     _rep(j,1,n) {
    //         if (arr[i]==j) printf("1 ");
    //         else printf("0 ");
    //     }
    //     putchar(10);
    // }
    _rep(i,1,n>>1) p[arr[i]]=1;
    build(1,1,n);
    _rep(i,1,(n>>1)+1) {
        int l=1,r=(n>>1);
        int cnt=query(1,l,r);
        // cout<<"NUMBER: "<<i<<endl;
        // test();
        while (true) {
            // cout<<l<<" "<<r<<" "<<cnt<<" "<<ans<<endl;
            if (r>n) break;
            if (!cnt) add_0();
            else if (cnt==1) add_1();
            // cout<<"now: "<<ans<<endl;
            if (r==n) break;
            if (!cnt) {
                l++,r++;
                cnt=query(1,l,r);
            } else if (cnt==1) {
                int L=get_nearest_1(l)-l;
                int R=get_nearest_1(r+1)-(r+1);
                // cout<<L<<" "<<R<<" test"<<endl;
                int k=min(L,R);
                add_1(k);
                // cout<<"k: "<<k<<endl;
                k++;
                l+=k,r+=k;
                cnt=query(1,l,r);
            } else {
                // cout<<l<<" "<<r<<endl;
                int k=get_rev_nearest_1(r);
                k=get_rev_nearest_1(k-1)+1-l;
                l+=k,r+=k;
                if (r>n) break;
                cnt=query(1,l,r);
            }
        }
        if (i!=((n>>1)+1)) {
            modify(1,arr[i],0);
            modify(1,arr[i+(n>>1)],1);
        }
        // cout<<ans<<endl;
    }
    printf("%lld",ans);
    return 0;
}

/*
10
7 9 8 10 5 6 4 1 2 3 
*/