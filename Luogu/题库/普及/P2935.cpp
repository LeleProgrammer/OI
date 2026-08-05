#include <bits/stdc++.h>
using namespace std;

const int N=505;
const int M=16005;

typedef pair<int,int> pii;

int n,m,k,a,b,c;
int e[M],w[M],ne[M],h[N],tot;
int f[N];
int dis[N];
bool check[N];
priority_queue< pii,vector<pii>,greater<pii> > q;
double minn;
int ans;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
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
            if (dis[e[i]]>dis[curr]+w[i] && !check[e[i]]) {
                dis[e[i]]=dis[curr]+w[i];
                q.push(make_pair(dis[e[i]],e[i]));
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d",&n,&k,&m);
    for (int i=1;i<=k;++i) scanf("%d",&f[i]);
    while (m--) {
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c); add(b,a,c);
    }
    minn=0x3f3f3f3f;
    for (int i=1;i<=n;++i) {
        dijkstra(i);
        int sum=0;
        double avg;
        for (int j=1;j<=k;++j) sum+=dis[f[j]];
        avg=(double(sum))/(double(k));
        if (avg<minn) minn=avg,ans=i;
    }
    printf("%d",ans);
    return 0;
}