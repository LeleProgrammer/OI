#include <bits/stdc++.h>
using namespace std;

int n;
string s[25];
unordered_map< string,int > hs;

int hex_stoi(string hx) {
    int res=0;
    if (isdigit(hx[0])) {
        res+=(hx[0]-'0')*16;
    } else {
        res+=(hx[0]-'A'+10)*16;
    }
    if (isdigit(hx[1])) {
        res+=(hx[1]-'0')*1;
    } else {
        res+=(hx[1]-'A'+10)*1;
    }
    return res;
}

string hex_itos(int hx) {
    string res;
    if (hx<=9) res+=(hx+'0');
    else res+=('A'+hx-10);
    return res;
}

bool cmp(pair< string,int > a,pair< string,int > b) {
    if (a.second!=b.second) return a.second>b.second;
    else return hex_stoi(a.first)<hex_stoi(b.first);
}

vector< pair< string,int > > v;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        cin>>s[i];
    }
    for (int i=1;i<=n;++i) {
        for (int j=0;j<s[i].size();j+=2) {
            if (hs.find(s[i].substr(j,2))==hs.end()) {
                hs.insert(make_pair(s[i].substr(j,2),1));
            } else {
                hs[s[i].substr(j,2)]++;
            }
        }
    }
    for (unordered_map< string,int >::iterator iter=hs.begin();iter!=hs.end();++iter) {
        v.push_back(*iter);
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=0;i<16;++i) {
        cout<<v[i].first;
    }
    putchar(10);
    for (int i=1;i<=n;++i) {
        for (int j=0;j<s[i].size();j+=2) {
            int minn=0x3f3f3f3f,mini;
            for (int p=0;p<16;++p) {
                if (abs(hex_stoi(v[p].first)-hex_stoi(s[i].substr(j,2)))<minn) {
                    minn=abs(hex_stoi(v[p].first)-hex_stoi(s[i].substr(j,2)));
                    mini=p;
                    // cout<<"TEST"<<s[i].substr(j,2)<<" "<<mini<<endl;
                }
            }
            cout<<hex_itos(mini);
        }
        cout<<endl;
    }
    return 0;
}