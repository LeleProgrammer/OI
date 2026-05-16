#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=300005;

int T,n,v;
int cnt[N];
bool flag[N];
vector<int> app;
int gx;
int ans;

bool cmp(const int& a,const int& b) {
    return a<b;
}

int tb2[N]; // C(i,2)
int tb3[N]; // C(i,3)

void init() {
    for (int i=3;i<=300000;++i) {
        tb2[i]=i*(i-1)/2;
        tb3[i]=i*(i-1)*(i-2)/6;
    }
}

signed main() {
    init();
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        for (int i=0;i<=n;++i) cnt[i]=0,flag[i]=false;
        while (!app.empty()) app.pop_back();
        for (int i=1;i<=n;++i) {
            scanf("%lld",&v);
            cnt[v]++;
            if (!flag[v]) {
                flag[v]=true;
                app.push_back(v);
            }
        }
        sort(app.begin(),app.end(),cmp);
        gx=0; ans=0;
        for (int i=0;i<app.size();++i) {
            if (cnt[app[i]]==2) {
                ans+=gx;
            } else if (cnt[app[i]]>=3) {
                ans+=tb3[cnt[app[i]]];
                ans+=tb2[cnt[app[i]]]*gx;
            }
            gx+=cnt[app[i]];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

/*
1 2 4 8 16 32 64 128 256
不能选三根长度不一样的
可以等边三角形
两边相等的话，第三边必须小于这两条相等的边
*/