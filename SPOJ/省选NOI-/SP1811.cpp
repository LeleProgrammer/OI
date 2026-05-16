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
const int M=35;

int n,m;
char s[N];
char t[N];

struct node {
    int len,fa;
    int ch[M];
} arr[N];

int last=1,idx=1;

void extend(int k) {
    int p=last;
    int np=last=++idx;
    arr[np].len=arr[p].len+1;
    for (;p && !arr[p].ch[k];p=arr[p].fa) arr[p].ch[k]=np;
    if (!p) arr[np].fa=1;
    else {
        int q=arr[p].ch[k];
        if (arr[q].len==arr[p].len+1) arr[np].fa=q;
        else {
            int nq=++idx;
            arr[nq]=arr[q];
            arr[nq].len=arr[p].len+1;
            arr[q].fa=nq;
            arr[np].fa=nq;
            for (;p && arr[p].ch[k]==q;p=arr[p].fa) arr[p].ch[k]=nq;
        }
    }
}

int main() {
    scanf("%s",s+1); n=strlen(s+1);
    _rep(i,1,n) extend(s[i]-'a');
    scanf("%s",t+1); m=strlen(t+1);
    int ans=0,now=0,u=1;
    _rep(i,1,m) {
        while (now && !arr[u].ch[t[i]-'a']) {
            u=arr[u].fa,now=arr[u].len;
        }
        if (!arr[u].ch[t[i]-'a']) continue;
        u=arr[u].ch[t[i]-'a'],ans=max(ans,++now);
    }
    printf("%d",ans);
    return 0;
}