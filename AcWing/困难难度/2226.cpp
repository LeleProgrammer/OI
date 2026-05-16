#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=150005;
const int M=300005;
const int inf=5e18;

int n,m,A;
int arr[N];
int e[M],ne[M],w[M],h[N],tot;
int del[N];
int las;

struct Centroid {
    int x,k;
    int dis;
};

vector<Centroid> ce[N];

struct Son {
    int a;
    int dis;
    friend bool operator < (const Son& a,const Son& b) {
        return a.a<b.a;
    }
};

vector<Son> pre[N][3];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

int get_size(int u,int fa) {
    if (del[u]) return 0;
    int ans=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        ans+=get_size(e[i],u);
    }
    return ans;
}

int get_cen(int u,int fa,int tot,int& cen) {
    if (del[u]) return 0;
    int sum=1,mx=0;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        int ret=get_cen(e[i],u,tot,cen);
        sum+=ret;
        mx=max(mx,ret);
    }
    mx=max(mx,tot-sum);
    if (mx<=tot/2) cen=u;
    return sum;
}

void get_dis(int u,int fa,int dis,int cen,int k,vector<Son>& pre) {
    if (del[u]) return;
    ce[u].push_back({cen,k,dis}); // u 的重心，哪一个儿子，到重心的距离 
    pre.push_back({arr[u],dis});
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        get_dis(e[i],u,dis+w[i],cen,k,pre);
    }
}

void build(int u) {
    if (del[u]) return;
    get_cen(u,0,get_size(u,0),u);
    del[u]=true;
    for (int i=h[u],k=0;~i;i=ne[i],++k) {
        if (del[e[i]]) continue;
        vector<Son>& so=pre[u][k];
        so.push_back({-inf,0});
        so.push_back({inf,0});
        get_dis(e[i],u,w[i],u,k,so);
        sort(so.begin(),so.end());
        for (int i=1;i<so.size()-1;++i) {
            so[i].dis+=so[i-1].dis;
        }
    }
    for (int i=h[u];~i;i=ne[i]) build(e[i]);
}

int query(int u,int l,int r) {
    int ans=0;
    for (int i=0;i<ce[u].size();++i) { // 枚举重心 
        Centroid& cen=ce[u][i];
        if (arr[cen.x]>=l && arr[cen.x]<=r) ans+=cen.dis; // 重心到 u
        for (int j=0;j<=2;++j) { // 跨过重心 
            if (j==cen.k) continue;
            vector<Son>& s=pre[cen.x][j];
            if (s.empty()) continue;
            int L=lower_bound(s.begin(),s.end(),Son({l,0}))-s.begin();
            int R=lower_bound(s.begin(),s.end(),Son({r+1,0}))-s.begin();
            ans+=(R-L)*cen.dis+s[R-1].dis-s[L-1].dis;
        }
    }
    for (int i=0;i<=2;++i) { // u 作为重心 
        vector<Son>& s=pre[u][i];
        if (s.empty()) continue;
        int L=lower_bound(s.begin(),s.end(),Son({l,0}))-s.begin();
        int R=lower_bound(s.begin(),s.end(),Son({r+1,0}))-s.begin();
        ans+=s[R-1].dis-s[L-1].dis;
    }
    return ans;
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld %lld",&n,&m,&A);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    for (int i=1;i<=n-1;++i) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    build(1);
    while (m--) {
        int u,l,r,a,b;
        scanf("%lld %lld %lld",&u,&a,&b);
        l=min((a+las)%A,(b+las)%A);
        r=max((a+las)%A,(b+las)%A);
        int ans=query(u,l,r);
        printf("%lld\n",las=ans);
    }
    return 0;
}