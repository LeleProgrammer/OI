#include <bits/stdc++.h>
using namespace std;

int n;

unordered_map<string,int> s;

int maxx=-1;
string ans;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        string name;
        cin>>name;
        unordered_map<string,int>::iterator iter=s.find(name);
        if (iter==s.end()) {
            s.insert(make_pair(name,1));
        } else {
            s[name]++;
        }
    }
    for (unordered_map<string,int>::iterator iter=s.begin();iter!=s.end();++iter) {
        if (iter->second>maxx) ans=iter->first,maxx=iter->second;
    }
    cout<<ans<<endl;
    return 0;
}