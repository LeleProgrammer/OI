#include <bits/stdc++.h>
using namespace std;

const int N=10005;

int n,m;
int p[N];
int x,y,z;

int fd(int x) {
    if (p[x]!=x) p[x]=fd(p[x]);
    return p[x];
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) p[i]=i;
    while (m--) {
        scanf("%d %d %d",&z,&x,&y);
        if (z==1) p[fd(x)]=fd(y);
        else printf(fd(x)==fd(y)?"Y":"N"),putchar(10);
    }
    return 0;
}