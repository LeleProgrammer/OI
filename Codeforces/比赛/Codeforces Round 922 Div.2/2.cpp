#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int T,n;

struct node {
    int a,b;
    friend bool operator < (const node& a,const node& b) {
        return a.a<b.a;
    }
} arr[N];

// int lower[N];
// stack<int> stk;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            scanf("%d",&arr[i].a);
        }
        for (int i=1;i<=n;++i) {
            scanf("%d",&arr[i].b);
        }
        sort(arr+1,arr+1+n);
        // while (!stk.empty()) stk.pop();
        // for (int i=1;i<=n;++i) cout<<lower[i]<<" ";
        for (int i=1;i<=n;++i) {
            printf("%d ",arr[i].a);
        }
        putchar(10);
        for (int i=1;i<=n;++i) {
            printf("%d ",arr[i].b);
        }
        putchar(10);
    }
    return 0;
}

/*
1 2 3 4 5 6
-1 ... ->
6 1 2 4 5 3
5 0 0 1 1 0

1 2 3 4 5 6 7
-1 ... ->
5 2 3 7 4 1 6
4 1 1 3 1 0 0
10
*/