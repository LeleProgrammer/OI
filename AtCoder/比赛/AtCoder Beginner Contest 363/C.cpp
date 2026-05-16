#include <bits/stdc++.h>
using namespace std;

int k,n;
string s;
set<string> hs;

bool check() {
    for (int l=0,r=k-1;r<s.size();++l,++r) {
        int i=l,j=r;
        bool ok=true;
        while (i<j) {
            if (s[i]!=s[j]) {
                ok=false;
                break;
            }
            ++i,--j;
        }
        if (ok) return true;
    }
    return false;
}

int main() {
    scanf("%d %d",&n,&k);
    cin>>s;
    sort(s.begin(),s.end());
    int ans=0;
    do {
        if (hs.find(s)!=hs.end()) continue;
        hs.insert(s);
        if (!check()) ans++;
    } while (next_permutation(s.begin(),s.end()));
    printf("%d",ans);
    return 0;
}