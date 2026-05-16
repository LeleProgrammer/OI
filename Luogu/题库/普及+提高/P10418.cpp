#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;
const int M=400005;
const int inf=1000000000000000000LL;

typedef pair<int,int> pii;

int n;
int e[M],ne[M],h[N],w[M],tot;
int f[N][7];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

bool cmp(const pii& a,const pii& b) {
    return a.first>b.first;
}

void dfs(int u,int fa) {
    for (int i=0;i<=6;++i) {
        f[u][i]=-inf;
    }
    vector<pii> vec1,vec2;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        dfs(e[i],u);
        f[u][0]=max(f[u][0],w[i]);
        f[u][2]=max(f[u][2],f[e[i]][0]+w[i]);
        f[u][3]=max(f[u][3],f[e[i]][2]+w[i]);
        f[u][5]=max(f[u][5],f[e[i]][1]+w[i]);
        vec1.push_back({w[i],i});
        vec2.push_back({f[e[i]][0]+w[i],i});
    }
    sort(vec1.begin(),vec1.end(),cmp);
    sort(vec2.begin(),vec2.end(),cmp);
    if (vec1.size()>=2) {
        f[u][1]=vec1[0].first+vec1[1].first;
        if (vec1.size()>=3) {
            f[u][6]=vec1[0].first+vec1[1].first+vec1[2].first;
        }
    }
    if (vec1.size() && vec2.size()) {
        if (vec1[0].second==vec2[0].second) {
            if (vec1.size()>=2 && vec2.size()>=2) {
                f[u][4]=max(vec1[0].first+vec2[1].first,vec1[1].first+vec2[0].first);
            } else if (vec1.size()==1 && vec2.size()>=2) {
                f[u][4]=vec1[0].first+vec2[1].first;
            } else if (vec1.size()>=2 && vec2.size()==1) {
                f[u][4]=vec1[1].first+vec2[0].first;
            }
        } else {
            f[u][4]=vec1[0].first+vec2[0].first;
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=2;i<=n;++i) {
        int x,y;
        scanf("%lld %lld",&x,&y);
        add(i,x,y);
        add(x,i,y);
    }
    dfs(1,0);
    int ans=-inf;
    for (int i=1;i<=n;++i) {
        for (int j=2;j<=6;++j) {
            ans=max(ans,f[i][j]);
        }
    }
    printf("%lld",ans);
    return 0;
}

/*
0:
0
|
0

1:
  0
 / \
0   0

2:
0
|
0
|
0

3:
0
|
0
|
0
|
0

4:
  0
 / \
0   0
|
0

5:
  0
  |
  0
 / \
0   0

6:
  0
 /|\
0 0 0
*/