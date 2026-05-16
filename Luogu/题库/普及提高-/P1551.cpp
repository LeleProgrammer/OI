#include <bits/stdc++.h>
using namespace std;

const int N=5005;

int n,m,a,b,P;
int p[N];

int fd(int x) {
    if (p[x]!=x) p[x]=fd(p[x]);
    return p[x];
}

int main() {
    scanf("%d %d %d",&n,&m,&P);
    for (int i=1;i<=n;++i) p[i]=i;
    while (m--) {
        scanf("%d %d",&a,&b);
        p[fd(a)]=fd(b);
    }
    while (P--) {
        scanf("%d %d",&a,&b);
        if (fd(a)==fd(b)) printf("Yes");
        else printf("No");
        putchar(10);
    }
    return 0;
}