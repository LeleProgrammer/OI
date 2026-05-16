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

const int N=500005;
const int M=500005;
const int K=35;

int n;
char s[N];
int f[N];
int ans[N];
int e[M],ne[M],h[N],tot;

struct node {
    int len,fa;
    int ch[K];
} arr[N];

int last=1,idx=1;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void extend(char c) {
    int p=last;
    int np=last=++idx;
    f[np]=1;
    arr[np].len=arr[p].len+1;
    for (;p && !arr[p].ch[c];p=arr[p].fa) arr[p].ch[c]=np;
    if (!p) arr[np].fa=1;
    else {
        int q=arr[p].ch[c];
        if (arr[q].len==arr[p].len+1) arr[np].fa=q;
        else {
            int nq=++idx;
            arr[nq]=arr[q];
            arr[nq].len=arr[p].len+1;
            arr[q].fa=arr[np].fa=nq;
            for (;p && arr[p].ch[c]==q;p=arr[p].fa) arr[p].ch[c]=nq;
        }
    }
}

int dfs(int u) {
    _graph(i,u) f[u]+=dfs(e[i]);
    ans[arr[u].len]=max(ans[arr[u].len],f[u]);
    return f[u];
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%s",s+1); n=strlen(s+1);
    _rep(i,1,n) extend(s[i]-'a');
    _rep(i,2,idx) add(arr[i].fa,i);
    dfs(1);
    _rep(i,1,n) printf("%d\n",ans[i]);
    return 0;
}