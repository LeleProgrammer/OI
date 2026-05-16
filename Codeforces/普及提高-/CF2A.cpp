#include <bits/stdc++.h>
using namespace std;

typedef pair<string,int> psi;

int n;
map<string,int> a;
map<string,int> b;
vector<psi> qs;
set<string> wins;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        string s;
        int k;
        cin>>s>>k;
        qs.push_back({s,k});
        if (a.find(s)==a.end()) {
            a.insert({s,k});
        } else {
            a[s]+=k;
        }
    }
    int maxn=-100000000;
    for (auto it=a.begin();it!=a.end();++it) {
        maxn=max(maxn,it->second);
    }
    for (auto it=a.begin();it!=a.end();++it) {
        if (it->second==maxn) wins.insert(it->first);
    }
    string ans;
    for (auto p:qs) {
        string s=p.first;
        int k=p.second;
        if (b.find(s)==b.end()) {
            b.insert({s,k});
        } else {
            b[s]+=k;
        }
        if (b[s]>=maxn && wins.find(s)!=wins.end()) {
            ans=s;
            break;
        }
    }
    cout<<ans;
    return 0;
}