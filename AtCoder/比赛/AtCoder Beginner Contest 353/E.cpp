#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=300005;
const int M=35;

int n;
string arr[N];
int son[N][M];
int cnt[N];
int tot;
int ans;

void insert(string s) {
    int u=0;
    for (int i=0;i<s.size();++i) {
        int c=s[i]-'a';
        if (!son[u][c]) son[u][c]=++tot;
        u=son[u][c];
        ans+=cnt[u];
        cnt[u]++;
    }
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        cin>>arr[i];
    }
    for (int i=1;i<=n;++i) {
        insert(arr[i]);
    }
    printf("%lld",ans);
    return 0;
}