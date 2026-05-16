#include <bits/stdc++.h>
using namespace std;

int k;
string s;
string ans;

int cnt[35];

int main() {
    scanf("%d",&k);
    cin>>s;
    for (char c:s) cnt[c-'a']++;
    bool ok=true;
    for (int i=0;i<=25 && ok;++i) ok&=(cnt[i]%k==0);
    if (!ok) puts("-1");
    else {
        for (int i=0;i<=25;++i) {
            for (int j=1;j<=cnt[i]/k;++j) {
                ans.push_back(i+'a');
            }
        }
        while (k--) cout<<ans;
    }
    return 0;
}