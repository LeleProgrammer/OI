#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int M=400005;
const int K=1100005;
const int inf=1e9;

typedef pair<int,int> pii;

int n,k;
int e[M],w[M],ne[M],h[N],tot;
bool del[N];
int f[K];
pii arr[N];
int idx;

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

void get_dis(int u,int fa,int dis,int cnt,pii* arr,int& idx) {
    if (del[u] || dis>k) return;
    arr[++idx]={dis,cnt};
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        get_dis(e[i],u,dis+w[i],cnt+1,arr,idx);
    }
}

void solve(int u,int& ans) {
    if (del[u]) return;
    get_cen(u,0,get_size(u,0),u);
    del[u]=true;
    vector<int> restore;
    for (int i=h[u];~i;i=ne[i]) {
        idx=0; get_dis(e[i],u,w[i],1,arr,idx);
        for (int j=1;j<=idx;++j) {
            if (k-arr[j].first>=0) ans=min(ans,f[k-arr[j].first]+arr[j].second);
            if (arr[j].first==k) ans=min(ans,arr[j].second);
        }
        for (int j=1;j<=idx;++j) {
            f[arr[j].first]=min(f[arr[j].first],arr[j].second);
            restore.push_back(arr[j].first);
        }
    }
    for (int i=0;i<restore.size();++i) f[restore[i]]=inf;
    for (int i=h[u];~i;i=ne[i]) solve(e[i],ans);
}

int main() {
    memset(h,-1,sizeof(h));
    for (int i=0;i<K;++i) f[i]=inf;
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n-1;++i) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c); a++,b++;
        add(a,b,c);
        add(b,a,c);
    }
    int ans=inf;
    solve(1,ans);
    if (ans==inf) printf("-1");
    else printf("%d",ans);
    return 0;
}