#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int son[3100005][2];
int tot;
int maxx=0;

void insert(int num) {
    int p=0;
    for (int i=30;i>=0;--i) {
        int bit=(num>>i)&1;
        if (!son[p][bit]) son[p][bit]=++tot;
        p=son[p][bit];
    }
}

int query(int num) {
    int p=0;
    int ans=0;
    for (int i=30;i>=0;--i) {
        int bit=(num>>i)&1;
        int bitxor=!bit;
        if (son[p][bitxor]) {
            p=son[p][bitxor];
            ans+=1<<i;
        } else {
            p=son[p][bit];
        }
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        insert(a[i]);
    }
    for (int i=1;i<=n;++i) {
        maxx=max(maxx,query(a[i]));
    }
    printf("%d",maxx);
    return 0;
}