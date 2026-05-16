#include <bits/stdc++.h>
using namespace std;

string s;

int cnt;

int first=1e9;

int main() {
    getline(cin,s);
    for (int i=0;i<s.size();++i) {
        s[i]=tolower(s[i]);
    }
    string t;
    getline(cin,t);
    for (int i=0;i<t.size();++i) {
        t[i]=tolower(t[i]);
    }
    int k=0;
    for (int i=0;i<(int)t.size()-(int)s.size()+1;++i) {
        if (t[i]==' ') {
            k++;
            continue;
        }
        if (i!=0 && t[i-1]!=' ') continue;
        if (i+s.size()<t.size() && t[i+s.size()]!=' ') continue;
        bool ok=true;
        for (int j=i,k=0;k<s.size();++j,++k) {
            if (t[j]!=s[k]) ok=false;
        }
        cnt+=ok;
        if (ok) first=min(first,k);
    }
    if (!cnt) puts("-1");
    else printf("%d %d",cnt,first);
    return 0;
}