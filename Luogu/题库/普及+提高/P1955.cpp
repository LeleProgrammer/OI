#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

int T,n;
unordered_map<int,int> hs;
int tot;
int p[M];

struct node {
    int a,b,type;
    friend bool operator < (const node& a,const node& b) {
        return a.type>b.type;
    }
} arr[N];

int get(int k) {
    auto iter=hs.find(k);
    if (iter==hs.end()) {
        hs.insert({k,++tot});
        return tot;
    } else {
        return iter->second;
    }
}

int find(int x) {
    if (p[x]==x) return x;
    else return p[x]=find(p[x]);
}

signed main() {
    scanf("%d",&T);
    while (T--) {
        hs.clear(); tot=0;
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            scanf("%d %d %d",&arr[i].a,&arr[i].b,&arr[i].type);
        }
        sort(arr+1,arr+1+n);
        for (int i=1;i<=n;++i) {
            get(arr[i].a);
            get(arr[i].b);
        }
        for (int i=1;i<=tot;++i) {
            p[i]=i;
        }
        int i;
        for (i=1;i<=n && arr[i].type;++i) {
            int a=get(arr[i].a);
            int b=get(arr[i].b);
            int pa=find(a);
            int pb=find(b);
            if (pa==pb) continue;
            p[pa]=pb;
        }
        bool ok=true;
        for (;i<=n;++i) {
            int a=get(arr[i].a);
            int b=get(arr[i].b);
            int pa=find(a);
            int pb=find(b);
            if (pa!=pb) continue;
            ok=false;
            break;
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}