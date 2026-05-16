#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;

int n;
map<string,int> arr;
int ans;

bool cmp(const char& a,const char& b) {
    return a<b;
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        sort(s.begin(),s.end(),cmp);
        if (arr.find(s)==arr.end()) arr.insert({s,1});
        else arr[s]++;
    }
    for (auto it=arr.begin();it!=arr.end();++it) {
        int k=it->second;
        ans+=k*(k-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}