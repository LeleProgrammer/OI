#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n,h;
int ans;

struct node {
    int a;
    bool b;
} arr[N*2];

bool cmp(const node& a,const node& b) {
    return a.a>b.a;
}

int main() {
    scanf("%d %d",&n,&h);
    for (int i=1;i<=n;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[i*2-1]={a,1};
        arr[i*2]={b,0};
    }
    sort(arr+1,arr+1+n+n,cmp);
    for (int i=1;i<=n*2;++i) {
        if (arr[i].b) {
            ans+=h/arr[i].a;
            if (h%arr[i].a) ans++;
            break;
        } else {
            ans++;
            h-=arr[i].a;
            if (h<=0) break;
        }
    }
    printf("%d\n",ans);
    return 0;
}