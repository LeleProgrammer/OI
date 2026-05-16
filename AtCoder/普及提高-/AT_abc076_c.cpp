#include <bits/stdc++.h>
using namespace std;

const int N=55;

int n,m;
char s[N],t[N];
vector<string> ans;

bool cmp(const string& a,const string& b) {
    for (int i=0;i<a.size();++i) {
        if (a[i]==b[i]) continue;
        return a[i]<b[i];
    }
    return a[0]<b[0];
}

int main() {
    scanf("%s",s+1);
    scanf("%s",t+1);
    n=strlen(s+1);
    m=strlen(t+1);
    for (int l=1,r=m;r<=n;++l,++r) {
        bool ok=true;
        for (int i=1;i<=m;++i) {
            if (s[l+i-1]!=t[i] && s[l+i-1]!='?') {
                ok=false;
                break;
            }
        }
        if (ok) {
            string k="";
            for (int i=1;i<=l-1;++i) {
                if (s[i]=='?') k.push_back('a');
                else k.push_back(s[i]);
            }
            for (int i=l;i<=r;++i) {
                k.push_back(t[i-l+1]);
            }
            for (int i=r+1;i<=n;++i) {
                if (s[i]=='?') k.push_back('a');
                else k.push_back(s[i]);
            }
            ans.push_back(k);
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    if (ans.size()==0) puts("UNRESTORABLE");
    else {
        cout<<ans[0]<<endl;
    }
    return 0;
}