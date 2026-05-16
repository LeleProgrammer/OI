#include <bits/stdc++.h>
using namespace std;

const int N=105;
const int M=405;

typedef pair<int,int> pii;

int n,a,b,c;
int e[M],ne[M],h[N],tot;
int p[N];
int dis[N];
bool check[N];
priority_queue< pii,vector<pii>,greater<pii> > q;
int ans;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s) {
    memset(dis,0x3f,sizeof(dis));
    memset(check,0,sizeof(check));
    dis[s]=0;
    q.push(make_pair(dis[s],s));
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int curr=tp.second;
        check[curr]=true;
        for (int i=h[curr];~i;i=ne[i]) {
            if (dis[e[i]]>dis[curr]+1 && !check[e[i]]) {
                dis[e[i]]=dis[curr]+1;
                q.push(make_pair(dis[e[i]],e[i]));
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d %d",&a,&b,&c);
        p[i]=a;
        if (b) add(i,b),add(b,i);
        if (c) add(i,c),add(c,i);
    }
    ans=2147483647;
    for (int i=1;i<=n;++i) {
        dijkstra(i);
        int sum=0;
        for (int j=1;j<=n;++j) sum+=(dis[j]*p[j]);
        ans=min(ans,sum);
    }
    printf("%d",ans);
    return 0;
}