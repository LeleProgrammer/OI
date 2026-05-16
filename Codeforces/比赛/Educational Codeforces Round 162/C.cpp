#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=300005;

int T,n,q;
int c[N];
int p[N];
// vector<int> v;

int gett(int k) {
    int l=0,r=1000000000;
    while (l<r) {
        int mid=l+r+1>>1;
        if (mid*(mid+1)/2<=k) l=mid;
        else r=mid-1;
    }
    return l;
}

int aaa(int g) {
    return g*(g+1)/2;
}

bool check(int k,int p) {
    if (k==1) return false;
    // if ((k*(k+1)/2)>=p) return true;
    int avg=p/k;
    int rem=p%k;
    int tmp=k/2;
    int cnt=min(p/2,avg-1);
    // cout<<k<<" "<<p<<" "<<avg<<" "<<tmp<<endl;
    rem+=aaa(avg-1);
    if (avg-1-tmp>=0) rem-=aaa(avg-1-tmp);
    int i=gett(rem);
    // int i=lower_bound(v.begin(),v.end(),rem)-v.begin();
    // if (v[i]!=rem) i--;
    cnt+=i;
    // cout<<i<<" "<<cnt<<endl;
    if ((k-cnt)>=k/2+k%2) return false;
    return true;
}

// void init() {
//     v.push_back(0);
//     for (int i=1;v.back()+i<=400000000000000;++i) {
//         v.push_back(v.back()+i);
//     }
// }

signed main() {
    // init();
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld",&n,&q);
        p[0]=0;
        for (int i=1;i<=n;++i) {
            scanf("%lld",&c[i]);
            p[i]=p[i-1]+c[i];
        }
        while (q--) {
            int l,r;
            scanf("%lld %lld",&l,&r);
            int sum=p[r]-p[l-1];
            // if (check(r-l+1,sum)) puts("YES");
            // else { // sum<=(r-l+1)*3 // (r-l+1)*2-(r-l+1)/2<=sum
                if ((double(r-l+1))*1.5<=sum && r!=l) puts("YES");
                else puts("NO");
            // }
        }
    }
    return 0;
}