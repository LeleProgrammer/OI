#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005,M=300005;

int n,k,x,a,b;
int e[M],ne[M],h[N],w[M],tot;

void add(int a,int b,int c) {
    e[++tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot;
}

int dis[N];
int cnt[N];
bool flag[N];
stack<int> q;

bool spfa() {
    memset(dis,-0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    memset(flag,0,sizeof(flag));
    dis[0]=0;
    q.push(0);
    flag[0]=true;
    while (!q.empty()) {
        int curr=q.top(); q.pop();
        flag[curr]=false;
        for (int i=h[curr];i;i=ne[i]) {
            if (dis[e[i]]<dis[curr]+w[i]) {
                dis[e[i]]=dis[curr]+w[i];
                cnt[e[i]]=cnt[curr]+1;
                if (cnt[e[i]]>=n+1) { // 多了个超级源点，所以 +1
                    return true; // 正环
                }
                if (!flag[e[i]]) {
                    flag[e[i]]=true;
                    q.push(e[i]);
                }
            }
        }
    }
    return false;
}

signed main() {
    scanf("%lld %lld",&n,&k);
    while (k--) {
        scanf("%lld %lld %lld",&x,&a,&b);
        if (x==1) { // a=b -> a>=b+0 && b>=a+0
            add(a,b,0);
            add(b,a,0);
        } else if (x==2) { // a<b -> b>=a+1
            add(a,b,1);
        } else if (x==3) { // a>=b -> a>=b+0
            add(b,a,0);
        } else if (x==4) { // a>b -> a>=b+1
            add(b,a,1);
        } else if (x==5) { // a<=b -> b>=a+0
            add(a,b,0);
        }
    }
    // i>=0+1
    for (int i=1;i<=n;++i) {
        add(0,i,1);
    }
    if (spfa()) {
        printf("-1");
    } else {
        int ans=0;
        for (int i=1;i<=n;++i) {
            ans+=dis[i];
        }
        printf("%lld",ans);
    }
    return 0;
}