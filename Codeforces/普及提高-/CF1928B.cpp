#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int T,n;
vector<int> a;
int cf[N];
deque<int> q;
int sum,ans;
int len;

bool cmp(const int& a,const int& b) {
    return a>b;
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        a.clear(); q.clear(); sum=0; ans=1;
        for (int i=1;i<=n;++i) {
            int v;
            scanf("%lld",&v);
            a.push_back(v);
        }
        sort(a.begin(),a.end(),cmp);
        a.erase(unique(a.begin(),a.end()),a.end());
        cf[0]=0;
        for (int i=1;i<a.size();++i) {
            cf[i]=a[i-1]-a[i];
        }
        len=0;
        for (int i=0;i<a.size();++i) {
            q.push_back(cf[i]); sum+=cf[i];
            len++;
            while (sum>n-1) {
                int tmp=q.front(); q.pop_front();
                sum-=q.front();
                q.push_front(tmp);
                q.pop_front();
                len--;
            }
            ans=max(ans,len);
        }
        printf("%lld\n",ans);
    }
    return 0;
}