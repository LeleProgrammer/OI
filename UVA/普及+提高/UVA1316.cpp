#include <bits/stdc++.h>
using namespace std;

const int N=10005;

int n;

struct node {
    int p,d;
    friend bool operator < (const node& a,const node& b) {
        if (a.d!=b.d) return a.d<b.d;
        return a.p>b.p;
    }
} arr[N];

priority_queue< int,vector<int>,greater<int> > q;

int main() {
    while (cin>>n) {
        for (int i=1;i<=n;++i) {
            scanf("%d %d",&arr[i].p,&arr[i].d);
        }
        sort(arr+1,arr+1+n);
        for (int i=1;i<=n;++i) {
            q.push(arr[i].p);
            while (q.size()>arr[i].d) {
                q.pop();
            }
        }
        int ans=0;
        while (!q.empty()) {
            ans+=q.top();
            q.pop();
        }
        printf("%d\n",ans);
    }
    return 0;
}