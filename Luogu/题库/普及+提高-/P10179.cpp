#include <bits/stdc++.h>
using namespace std;

const int N=300005;
const int M=600005;

int T,n,m;
int e[M],ne[M],h[N],tot;

bool vis[N];
vector<int> v[N];
int cnt;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void bfs(int s) { // find connected blocks
    queue<int> q;
    vis[s]=true;
    q.push(s);
    cnt++;
    v[cnt].push_back(s);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (!vis[e[i]]) {
                vis[e[i]]=true;
                q.push(e[i]);
                v[cnt].push_back(e[i]);
            }
        }
    }
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&m);
        for (int i=1;i<=cnt;++i) v[i].clear();
        cnt=0;
        for (int i=1;i<=n;++i) h[i]=-1,vis[i]=0;
        while (m--) {
            int a,b;
            scanf("%d %d",&a,&b);
            add(a,b); add(b,a);
        }
        for (int i=1;i<=n;++i) {
            if (!vis[i]) {
                bfs(i);
            }
        }
        if (cnt==1) {
            puts("No");
            continue;
        }
        puts("Yes");
        for (int i=1;i<=cnt;++i) {
            if (i!=cnt) {
                for (int j=0;j<v[i].size();++j) {
                    printf("%d %d\n",v[i+1][0],v[i][j]);
                }
            } else {
                for (int j=1;j<v[i].size();++j) {
                    printf("%d %d\n",v[i][j],v[i-1][0]);
                }
            }
        }
    }
    return 0;
}