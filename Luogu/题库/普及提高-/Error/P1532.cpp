#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
int c=10;

signed main() {
    while (scanf("%lld",&n)!=EOF) {
        vector<int> v;
        unordered_set<int> hs;
        v.push_back(n);
        hs.insert(n);
        while (c--) {
            int a=0,n2=n;
            while (n2) {
                a=a*10+n2%10;
                n2/=10;
            }
            n-=a;
            if (hs.find(n)!=hs.end()) {
                bool start=false;
                for (int i=0;i<v.size();++i) {
                    if (v[i]==n) start=true;
                    if (start) {
                        printf("%lld ",v[i]);
                    }
                }
                printf("\n");
                break;
            } else {
                hs.insert(n);
                v.push_back(n);
            }
            vector<int> tmp;
            while (n) {
                tmp.push_back(n%10);
                n/=10;
            }
            sort(tmp.begin(),tmp.end(),greater<int>());
            for (int i=0;i<tmp.size();++i) {
                n=n*10+tmp[i];
            }
        }
    }
    return 0;
}