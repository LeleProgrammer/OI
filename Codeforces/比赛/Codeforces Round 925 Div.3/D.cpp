#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int T;
int n,x,y;
int a[N];
int b[N],c[N];
int ans;

map< pair<int,int>,int > hs;

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&n,&x,&y);
        hs.clear();
        ans=0;
        for (int i=1;i<=n;++i) {
            scanf("%lld",&a[i]);
            b[i]=a[i]%x;
            c[i]=a[i]%y;
            if (hs.find(make_pair(b[i],c[i]))==hs.end()) {
                hs.insert(make_pair(make_pair(b[i],c[i]),1));
            } else {
                hs[make_pair(b[i],c[i])]++;
            }
        }
        for (int i=1;i<=n;++i) {
            pair<int,int> need={(x-b[i])%x,c[i]};
            int cnt=0;
            auto it=hs.find(need);
            if (it!=hs.end()) cnt=it->second;
            ans+=cnt;
            if (need.first==b[i] && cnt) ans--;
        }
        printf("%lld\n",ans/2);
    }
    return 0;
}