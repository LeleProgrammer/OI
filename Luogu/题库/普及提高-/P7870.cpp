#include <bits/stdc++.h>

#define int long long

using namespace std;

stack< pair<int,int> > s;
int n,op,l,r,k,result;

int sum(int l,int r) {
    return (l+r)*(r-l+1)/2;
}

signed main() {
    scanf("%lld",&n);
    while (n--) {
        scanf("%lld",&op);
        if (op==1) {
            scanf("%lld %lld",&l,&r);
            s.push(make_pair(l,r));
        } else {
            scanf("%lld",&k);
            result=0;
            while (k) {
                if (s.top().second-s.top().first+1<=k) {
                    result+=sum(s.top().first,s.top().second);
                    k-=s.top().second-s.top().first+1;
                    s.pop();
                } else {
                    pair<int,int> p=s.top();
                    s.pop();
                    result+=sum(p.second-k+1,p.second);
                    p.second-=k;
                    k-=k;
                    s.push(p);
                }
            }
            printf("%lld\n",result);
        }
    }
    return 0;
}