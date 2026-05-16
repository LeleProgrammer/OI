#include <bits/stdc++.h>

#define int long long
#define inf 2147483647

using namespace std;

int n,m,s,u,v,w;
vector<int> G[100005];
vector<int> W[100005];
int dis[100005];
bool check[100005];

// struct cmp {
//     bool operator () (const int& a,const int& b) {
//         return dis[a]>dis[b];
//     }
// };

// priority_queue< int,vector<int>,cmp > q;

void dijkstra() {
    for (int i=1;i<=10000;++i) dis[i]=inf,check[i]=false;
    dis[s]=0;
    // q.push(s);
    for (int p=1;p<=n;++p) {
        // int curr=q.top();
        // q.pop();
        int curr,minn=inf;
        for (int i=1;i<=n;++i) {
            if (dis[i]<=minn && !check[i]) {
                minn=dis[i];
                curr=i;
            }
        }
        check[curr]=true;
        for (int i=0;i<G[curr].size();++i) {
            if (!check[G[curr][i]] && dis[curr]+W[curr][i]<dis[G[curr][i]]) {
                dis[G[curr][i]]=dis[curr]+W[curr][i];
                // q.push(G[curr][i]);
            }
        }
    }
}

signed main() {
    scanf("%lld %lld %lld",&n,&m,&s);
    for (int i=1;i<=m;++i) {
        scanf("%lld %lld %lld",&u,&v,&w);
        G[u].push_back(v);
        W[u].push_back(w);
    }
    dijkstra();
    for (int i=1;i<=n;++i) printf("%lld ",dis[i]);
    return 0;
}