#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=700005;
const int mod=998244353;

int n,m;
int e[M],ne[M],h[N],tot;
int len[N],cnt[N];
int in[N];
queue<int> q;
int len_sum,cnt_sum;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void topu() {
    for (int i=1;i<=n;++i) {
        if (!in[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            len[e[i]]+=len[u]+cnt[u]; // 注意这里是 len[u]+cnt[u] 而不是 len[u]+1
            cnt[e[i]]+=cnt[u];
            len[e[i]]%=mod;
            cnt[e[i]]%=mod;
            in[e[i]]--;
            if (!in[e[i]]) {
                q.push(e[i]);
            }
        }
    }
}

int exgcd(int a,int b,int& x,int& y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld",&n,&m);
    while (m--) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        add(a,b);
        in[b]++;
    }
    for (int i=1;i<=n;++i) cnt[i]=1;
    topu();
    for (int i=1;i<=n;++i) {
        len_sum+=len[i];
        cnt_sum+=cnt[i];
        len_sum%=mod;
        cnt_sum%=mod;
    }
    int x0,y0;
    int d=exgcd(cnt_sum,mod,x0,y0);
    int x1,y1;
    x1=x0/d;
    y1=y0/d;
    int dx=mod/d;
    int s=ceil((-x1+1.00)/dx);
    printf("%lld",len_sum*((x1+s*dx)%mod)%mod);
    return 0;
}

/*
sigma 路径总长度
---------------
sigma 路径总条数
*/