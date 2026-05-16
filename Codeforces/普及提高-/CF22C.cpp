#include <bits/stdc++.h>
using namespace std;

int n,m,v;

vector<int> ds;
vector< pair<int,int> > ans;

int main() {
    scanf("%d %d %d",&n,&m,&v);
    if (m<n-1 || m>n*(n-1)/2) puts("-1");
    else {
        for (int i=1;i<=n;++i) {
            if (i!=v) ans.push_back({i,v}),m--,ds.push_back(i);
        }
        bool ok=true;
        for (int i=0;i<ds.size()-1 && m;++i) {
            for (int j=i+1;j<ds.size()-1 && m;++j) {
                ans.push_back({ds[i],ds[j]}),m--;
            }
        }
        if (m) puts("-1");
        else {
            for (auto p:ans) {
                printf("%d %d\n",p.first,p.second);
            }
        }
    }
    return 0;
}