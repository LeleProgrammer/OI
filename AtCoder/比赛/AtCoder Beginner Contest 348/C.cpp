#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int n;
int a[N],c[N];
unordered_map<int,int> s;
int maxx;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&a[i],&c[i]);
        if (s.find(c[i])==s.end()) {
            s.insert({c[i],a[i]});
        } else {
            if (a[i]<s[c[i]]) {
                s[c[i]]=a[i];
            }
        }
    }
    for (auto it=s.begin();it!=s.end();++it) {
        maxx=max(maxx,it->second);
    }
    printf("%d",maxx);
    return 0;
}