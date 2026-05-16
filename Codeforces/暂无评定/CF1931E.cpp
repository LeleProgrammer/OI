#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int T,n,m;
int a;
vector<int> v;
int cnt;

bool cmp(const int& a,const int& b) {
    return a>b;
}

int main() {
    scanf("%d",&T);
    while (T--) {
        v.clear();
        scanf("%d %d",&n,&m);
        cnt=0;
        for (int i=1;i<=n;++i) {
            scanf("%d",&a);
            v.push_back(0);
            bool ok=true;
            while (a) {
                if (a%10==0 && ok) v.back()++;
                else ok=false;
                a/=10;
                cnt++;
            }
        }
        if (cnt<=m) {
            puts("Anna");
            continue;
        }
        sort(v.begin(),v.end(),cmp);
        int dis=0;
        for (int i=0;i<v.size();i+=2) {
            dis+=v[i];
        }
        if (cnt-dis<=m) puts("Anna");
        else puts("Sasha");
    }
    return 0;
}