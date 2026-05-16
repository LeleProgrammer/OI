#include <bits/stdc++.h>
using namespace std;

int n,kk,d;
string s;
string gett;

vector< pair<string,int> > v;

int main() {
    scanf("%d %d",&n,&kk);
    for (int i=1;i<=n;++i) {
        cin>>s>>d;
        v.push_back(make_pair(s,d));
    }
    char c='a';
    while (c!=10) c=getchar();
    while (kk--) {
        getline(cin,gett);
        for (int i=0;i<gett.size();++i) {
            if (gett[i]!='{') putchar(gett[i]);
            else if (gett[i]=='{') {
                string read;
                int j;
                for (j=i+1;gett[j]!='}';++j) {
                    read.push_back(gett[j]);
                }
                int k;
                for (k=0;k<v.size();++k) {
                    if (v[k].first==read) break;
                }
                printf("%d",v[k].second);
                i=j;
            }
        }
        putchar(10);
    }
    return 0;
}