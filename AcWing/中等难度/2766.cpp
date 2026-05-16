#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=2000005;
const int M=26;

int n;
char s[N];
int f[N];
int cnt=1;
int last=1;
int e[N],ne[N],h[N],tot;
int ans;

struct SAM {
    int len,fa;
    int s[M];
} node[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void extend(int c) {
    int p=last,np=last=++cnt;
    f[cnt]=1;
    node[np].len=node[p].len+1;
    for (;p && !node[p].s[c];p=node[p].fa) node[p].s[c]=np;
    if (!p) node[np].fa=1;
    else {
        int q=node[p].s[c];
        if (node[q].len==node[p].len+1) node[np].fa=q;
        else {
            int nq=++cnt;
            node[nq]=node[q];
            node[nq].len=node[p].len+1;
            node[q].fa=nq;
            node[np].fa=nq;
            for (;p && node[p].s[c]==q;p=node[p].fa) node[p].s[c]=nq;
        }
    }
}

void dfs(int u) {
    for (int i=h[u];~i;i=ne[i]) {
        dfs(e[i]);
        f[u]+=f[e[i]];
    }
    if (f[u]!=1) ans=max(ans,f[u]*node[u].len);
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%s",s+1); n=strlen(s+1);
    for (int i=1;i<=n;++i) extend(s[i]-'a');
    for (int i=2;i<=cnt;++i) add(node[i].fa,i);
    dfs(1);
    printf("%lld",ans);
    return 0;
}