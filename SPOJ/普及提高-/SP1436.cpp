#include <bits/stdc++.h>
using namespace std;

const int N=10005;

int n,m;
int p[N];

int find(int x) {
    return (p[x]==x)?p[x]:(p[x]=find(p[x]));
}

int main() {
    scanf("%d %d",&n,&m);
    if (m!=n-1) {
        puts("NO");
        return 0;
    }
    for (int i=1;i<=n;++i) p[i]=i;
    bool ok=true;
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        if (find(a)==find(b)) {
            puts("NO");
            ok=false;
            break;
        } else {
            p[find(a)]=find(b);
        }
    }
    if (ok) puts("YES");
    return 0;
}