#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=400005;

typedef pair<int,int> pii;

int n,q;
int p[N];
int tmp[N];
vector<pii> vec;

int find(int x) {
    return (p[x]==x)?p[x]:(p[x]=find(p[x]));
}

struct node {
    int l,r,c,i;
    friend bool operator < (const node& a,const node& b) {
        return a.c<b.c;
    }
} arr[N];

signed main() {
    scanf("%lld %lld",&n,&q);
    for (int i=1;i<=n+q;++i) {
        p[i]=i;
    }
    for (int i=1;i<=q;++i) {
        int l,r,c;
        scanf("%lld %lld %lld",&l,&r,&c);
        arr[i]={l,r,c,i};
        tmp[l]++;
        tmp[r+1]--;
    }
    int least=q-1;
    int two=0;
    int now=0;
    for (int i=1;i<=n;++i) {
        now+=tmp[i];
        if (!now) {
            printf("-1");
            return 0;
        } else if (now>=2) two++;
    }
    if (two<least) {
        printf("-1");
        return 0;
    }
    sort(arr+1,arr+1+n);
    int ans=0;
    vec.push_back({1,n});
    for (int i=1;i<=q;++i) {
        int l,r,c,j;
        l=q[i].l;
        r=q[i].r;
        c=q[i].c;
        j=q[i].j;
        int take=0;
        for (int k=0;k<vec.size();++k) {
            if (vec[k].first>=l && vec[k].second<=r) {
                take+=vec[k].second-vec[k].first+1;
                vec.erase(vec.begin()+k);
                k--;
            } else if (l>=vec[k].first && r<=vec[k].second) {
                take+=r-l+1;
                vec.push_back(vec[k].first,l-1);
                vec.push_back(r+1,vec[k].second);
            }
        }
    }
}