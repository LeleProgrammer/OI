#include <bits/stdc++.h>
using namespace std;

unordered_set<string> hs;

int main() {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        hs.insert(s);
    }
    printf("%d",hs.size());
    return 0;
}