#include <bits/stdc++.h>
using namespace std;

const int N=105;

int n;

struct node {
    int val;
    int pos;
} arr[N];

bool cmp(const node& a,const node& b) {
    return a.val>b.val;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i].val);
        arr[i].pos=i;
    }
    sort(arr+1,arr+1+n,cmp);
    printf("%d",arr[2].pos);
    return 0;
}