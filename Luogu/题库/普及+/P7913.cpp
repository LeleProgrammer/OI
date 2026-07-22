#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n,m1,m2;
int cnt1[N],cnt2[N];

struct node {
    int a,b,c;
    friend bool operator < (const node& a,const node& b) {
        if (a.a!=b.a) return a.a<b.a;
        return a.b<b.b;
    }
    friend bool operator > (const node& a,const node& b) {
        return a.b>b.b;
    }
} a[N],b[N];

priority_queue< int,vector<int>,greater<int> > q;
priority_queue< node,vector<node>,greater<node> > q2;

int main() {
    scanf("%d %d %d",&n,&m1,&m2);
    for (int i=1;i<=m1;++i) {
        scanf("%d %d",&a[i].a,&a[i].b);
    }
    for (int i=1;i<=m2;++i) {
        scanf("%d %d",&b[i].a,&b[i].b);
    }
    sort(a+1,a+1+m1);
    sort(b+1,b+1+m2);
    for (int i=1;i<=m1;++i) q.push(i);
    for (int i=1;i<=m1;++i) {
        auto t=a[i];
        while (!q2.empty() && q2.top().b<t.a) {
            q.push(q2.top().c);
            q2.pop();
        }
        int dest=q.top();
        q.pop();
        cnt1[dest]++;
        a[i].c=dest;
        q2.push(a[i]);
    }
    while (!q.empty()) q.pop();
    while (!q2.empty()) q2.pop();
    for (int i=1;i<=m2;++i) q.push(i);
    for (int i=1;i<=m2;++i) {
        auto t=b[i];
        while (!q2.empty() && q2.top().b<t.a) {
            q.push(q2.top().c);
            q2.pop();
        }
        int dest=q.top();
        q.pop();
        cnt2[dest]++;
        b[i].c=dest;
        q2.push(b[i]);
    }
    for (int i=2;i<N;++i) {
        cnt1[i]+=cnt1[i-1];
    }
    for (int i=2;i<N;++i) {
        cnt2[i]+=cnt2[i-1];
    }
    int ans=0;
    for (int i=0;i<=n;++i) {
        ans=max(ans,cnt1[i]+cnt2[n-i]);
    }
    printf("%d",ans);
    return 0;
}