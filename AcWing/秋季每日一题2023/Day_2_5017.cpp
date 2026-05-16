#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

int n,m,k;
int t[MAXN],c[MAXN];

bool check(int mid) {
    long long result=0LL;
    for (int i=1;i<=n;++i) {
        if (t[i]>mid) {
            result+=(long long)(t[i]-mid)*c[i];
        }
    }
    return result<=m;
}

int main() {
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",t+i,c+i);
    }
    int l=k,r=1e5;
    while (l<r) {
        int mid=(l+r)/2;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d",l);
    return 0;
}