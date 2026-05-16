#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n;
set< vector<int> > st;

bool cmp(const int& a,const int& b) {
    return a<b;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        vector<int> a;
        for (int j=1;j<=6;++j) {
            int v;
            scanf("%d",&v);
            a.push_back(v);
        }
        sort(a.begin(),a.end(),cmp);
        if (st.find(a)!=st.end()) {
            puts("Twin snowflakes found.");
            return 0;
        }
        st.insert(a);
    }
    puts("No two snowflakes are alike.");
    return 0;
}