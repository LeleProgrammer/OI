#include <bits/stdc++.h>
using namespace std;

const int N=400005;
const int M=400005;

int n,m,k;
int p[N];
bool flag[N];
int cnt;
int e[M],ne[M],h[N],tot;
vector<int> vec;
vector<int> ans;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

int find(int x) {
    return (p[x]==x)?(p[x]):(p[x]=find(p[x]));
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        p[i]=i;
    }
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b); a++,b++;
        add(a,b);
        add(b,a);
    }
    scanf("%d",&k);
    while (k--) {
        int a;
        scanf("%d",&a); a++;
        vec.push_back(a);
        flag[a]=true;
    }
    reverse(vec.begin(),vec.end());
    for (int u=1;u<=n;++u) {
        if (flag[u]) continue;
        cnt++;
        for (int i=h[u];~i;i=ne[i]) {
            if (flag[e[i]]) continue;
            int pa=find(u);
            int pb=find(e[i]);
            if (pa==pb) continue;
            p[pa]=pb;
            cnt--;
        }
    }
    ans.push_back(cnt);
    for (int t=0;t<vec.size();++t) {
        int u=vec[t];
        flag[u]=false;
        cnt++;
        for (int i=h[u];~i;i=ne[i]) {
            if (flag[e[i]]) continue;
            int pa=find(u);
            int pb=find(e[i]);
            if (pa==pb) continue;
            p[pa]=pb;
            cnt--;
        }
        ans.push_back(cnt);
    }
    reverse(ans.begin(),ans.end());
    for (int i=0;i<ans.size();++i) {
        printf("%d\n",ans[i]);
    }
    return 0;
}