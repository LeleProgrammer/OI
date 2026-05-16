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

const int N=6005;
const int M=2;

int n,cnt=1,last=1;
char s[N];
int e[N],ne[N],h[N],tot;
int f[N];
int ans[N];

struct node {
    int len,fa;
    int ch[M];
} arr[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void extend(int k) {
    int p=last;
    int np=last=++cnt;
    f[cnt]=1;
    arr[np].len=arr[p].len+1;
    for (;p && !arr[p].ch[k];p=arr[p].fa) arr[p].ch[k]=np;
    if (!p) arr[np].fa=1;
    else {
        int q=arr[p].ch[k];
        if (arr[q].len==arr[p].len+1) arr[np].fa=q;
        else {
            int nq=++cnt;
            arr[nq]=arr[q];
            arr[nq].len=arr[p].len+1;
            arr[q].fa=nq;
            arr[np].fa=nq;
            for (;p && arr[p].ch[k]==q;p=arr[p].fa) arr[p].ch[k]=nq;
        }
    }
}

void dfs(int u) {
    _graph(i,u) {
        dfs(e[i]);
        f[u]+=f[e[i]];
    }
}

void dfs2(int u) {
    if (f[u]>=2 && u!=1) printf("%d\n",f[u]);
    _rep(i,0,1) {
        if (!arr[u].ch[i]) continue;
        dfs2(arr[u].ch[i]);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    scanf("%s",s+1);
    _rep(i,1,n) extend(s[i]-'0');
    _rep(i,2,cnt) add(arr[i].fa,i);
    dfs(1);
    dfs2(1);
    return 0;
}