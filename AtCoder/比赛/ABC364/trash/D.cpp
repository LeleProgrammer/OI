#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n,m;
int a[N];
vector<int> l,r;
int bias;

struct Query {
    int b,k;
    int id;
    friend bool operator < (const Query& a,const Query& b) {
        return a.b<b.b;
    }
} q[N];

bool cmp(const int& a,const int& b) {
    return a<b;
}

bool cmp2(const int& a,const int& b) {
    return a>b;
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=m;++i) {
        int b,k;
        scanf("%d %d",&b,&k);
        q[i]={b,k,i};
    }
    sort(q+1,q+1+m);
    for (int i=1;i<=n;++i) {
        if (a[i]<=b[1]) {
            l.push_back(b[1]-a[i]);
        } else {
            r.push_back(a[i]-b[1]);
        }
    }
    sort(l.begin(),l.end(),cmp2);
    sort(r.begin(),r.end(),cmp2);
    for (int i=1;i<=m;++i) {
        int b,k,id;
        b=q[i].b;
        k=q[i].k;
        id=q[i].id;
        if (i!=1) {
            ;
        }
    }
}