#include <bits/stdc++.h>
using namespace std;

const int N=300005;
const int M=600005;

int n,m;
int e[M],ne[M],h[N],tot;
int f[N],g[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

bool cmp(const int& a,const int& b) {
    return a>b;
}

void dfs(int u,int fa) {
    int s=0;
    vector<int> vec;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        dfs(e[i],u);
        vec.push_back(f[e[i]]);
        s++;
    }
    if (vec.size()==0) {
        f[u]=1;
        return;
    }
    sort(vec.begin(),vec.end(),cmp);
    f[u]=vec[0]+s; // 加上自己这个点，减掉选择的链的重复点，抵消
    if (vec.size()>=2) {
        g[u]=vec[0]+vec[1]+s-1; // 加上自己，减掉选择的链的重复点两个，等价于直接减一
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs(1,0);
    for (int i=2;i<=n;++i) g[i]++; // 折线，需要加上父节点
    int ans=0;
    for (int i=1;i<=n;++i) {
        ans=max(ans,max(f[i],g[i]));
    }
    printf("%d",ans);
    return 0;
}

// f[i] 表示 i 为链的顶部，最大大小
// g[i] 表示 i 为链的转折点，最大大小

/*
16 15
1 2
1 3
2 4
3 5
5 6
6 7
7 8
8 9
9 10
5 11
11 12
12 13
13 14
14 15
15 16
*/