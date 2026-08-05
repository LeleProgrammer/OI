#include <bits/stdc++.h>
using namespace std;

int n,w;
int tr[100005];
int arr[100005];
int pre[100005];
int x,b;
int xmaxx;
int ans;

int lowbit(int x) {
    return x & -x;
}

int query(int n) {
    int res=0;
    for (int i=n;i;i-=lowbit(i)) res+=tr[i];
    return res;
}

int sum(int a,int b) {
    return query(b)-query(a);
}

int add(int x,int v) {
    for (int i=x;i<=xmaxx;i+=lowbit(i)) {
        tr[i]+=v;
    }
}

int main() {
    scanf("%d %d",&n,&w);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&x,&b);
        arr[x]+=b;
        xmaxx=max(xmaxx,x);
    }
    for (int i=1;i<=xmaxx;++i) add(i,arr[i]);
    for (int l=1,r=1+w;r<=xmaxx;++l,++r) {
        ans=max(ans,sum(l,r));
    }
    printf("%d",ans);
    return 0;
}