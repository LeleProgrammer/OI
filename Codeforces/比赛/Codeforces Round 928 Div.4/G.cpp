#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=200005;

int T,n;
int e[M],ne[M],h[N],tot;
int s[N],p[N];
char tp[N];
bool vis[N];
int ans;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u]=true;
    for (int i=h[u];~i;i=ne[i]) {
        if (vis[e[i]]) continue;
        if (tp[e[i]]=='C') {
            if (tp[u]=='S') s[e[i]]++;
            else p[e[i]]++;
        } else if (tp[e[i]]==tp[u]) {
            dfs(e[i]);
        } else if (tp[e[i]]=='S' && tp[u]=='P') ans++;
    }
}

pair<int,int> dfs2(int u,int fa) {
    if (vis[u]) return {0,0};
    vis[u]=true;
    int ss=s[u],pp=p[u];
    for (int i=h[u];~i;i=ne[i]) {
        if (u==fa) continue;
        if (tp[e[i]]!='C') continue;
        if (vis[e[i]]) continue;
        auto tt=dfs2(e[i],u);
        ss+=tt.first;
        pp+=tt.second;
    }
    return make_pair(ss,pp);
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        for (int i=1;i<=n;++i) {
            h[i]=-1;
            s[i]=0;
            p[i]=0;
            vis[i]=false;
        }
        tot=0;
        for (int i=2;i<=n;++i) {
            int a;
            scanf("%lld",&a);
            add(a,i); add(i,a);
        }
        ans=0;
        scanf("%s",tp+1);
        for (int i=1;i<=n;++i) {
            if (tp[i]!='C') {
                dfs(i);
            }
        }
        for (int i=1;i<=n;++i) {
            if (tp[i]=='C') {
                cout<<s[i]<<" "<<p[i]<<endl;
                auto tt=dfs2(i,-1);
                ans+=min(tt.first,tt.second);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}