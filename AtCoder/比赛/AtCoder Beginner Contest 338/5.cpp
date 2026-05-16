#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int n;

struct Segment {
    int a,b;
    friend bool operator < (const Segment& a,const Segment& b) {
        return a.a<b.a;
    }
} arr[N];

int k;

stack<int> limits;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&arr[i].a,&arr[i].b);
        if (abs(arr[i].a-arr[i].b)==1) {
            k=max(arr[i].a,arr[i].b);
        }
    }
    if (!k) {
        printf("Yes\n");
        return 0;
    }
    n*=2;
    k=k-1;
    for (int i=1;i<=n/2;++i) {
        arr[i].a-=k;
        arr[i].b-=k;
        if (arr[i].a<=0) arr[i].a+=n;
        if (arr[i].b<=0) arr[i].b+=n;
        if (arr[i].a>arr[i].b) swap(arr[i].a,arr[i].b);
    }
    sort(arr+1,arr+1+(n/2));
    bool ok=true;
    for (int i=1;i<=n/2;++i) {
        if (limits.empty()) {
            limits.push(arr[i].b);
            continue;
        }
        while ((!limits.empty()) && arr[i].a>limits.top()) {
            limits.pop();
        }
        if (limits.empty()) {
            limits.push(arr[i].b);
            continue;
        }
        if (arr[i].b>limits.top()) {
            ok=false;
            break;
        }
        limits.push(arr[i].b);
    }
    // bool ok=true;
    // for (int i=1;i<=(n/2)-1 && ok;++i) {
    //     if (arr[i].a+1!=arr[i+1].a) {
    //         ok=false;
    //         break;
    //     }
    // }
    // if (arr[n/2].a+1!=arr[n/2].b) ok=false;
    // for (int i=n/2;i>=2 && ok;--i) {
    //     if (arr[i].b+1!=arr[i-1].b) {
    //         ok=false;
    //         break;
    //     }
    // }
    if (ok) printf("No\n");
    else printf("Yes\n");
    return 0;
}