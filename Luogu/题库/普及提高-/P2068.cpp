#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,w;
int tr[400020];
char op[2];
int a,b;

int lowbit(int x) {
    return x & -x;
}

void modify(int a,int x) {
    for (int i=a;i<=n;i+=lowbit(i)) tr[i]+=x;
}

int query(int k) {
    int res=0;
    for (int i=k;i;i-=lowbit(i)) res+=tr[i];
    return res;
}

signed main() {
    scanf("%lld",&n);
    scanf("%lld",&w);
    while (w--) {
        scanf("%s %lld %lld",op,&a,&b);
        if (*op=='x') modify(a,b);
        else printf("%lld\n",query(b)-query(a-1));
    }
    return 0;
}