#include <bits/stdc++.h>
using namespace std;

const int N=100005;

typedef pair<int,int> pii;

int n,m;
int cnt[N];
pii ans[N];

struct node {
    int p,y,i;
} a[N];

bool cmp(const node& a,const node& b) {
    if (a.p==b.p) return a.y<b.y;
    return a.p<b.p;
}

string transform(int k) {
    string ans;
    while (k) {
        ans=(char(k%10+'0'))+ans;
        k/=10;
    }
    while (ans.size()<6) {
        ans.insert(ans.begin(),'0');
    }
    return ans;
}

int main() {
    scanf("%d %d",&m,&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&a[i].p,&a[i].y);
        a[i].i=i;
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;++i) {
        int idx=a[i].i;
        ans[idx]={a[i].p,++cnt[a[i].p]};
    }
    for (int i=1;i<=n;++i) {
        cout<<transform(ans[i].first)<<transform(ans[i].second)<<endl;
    }
    return 0;
}