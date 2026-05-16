#include <bits/stdc++.h>
using namespace std;

const int N=500005;

int m,n;
int tr[N][2];
int cnt[N];
int st[N];
int tot;

void insert(string s) {
    int u=0;
    for (int i=0;i<s.size();++i) {
        int c=s[i]-'0';
        if (!tr[u][c]) tr[u][c]=++tot;
        u=tr[u][c];
        cnt[u]++;
    }
    st[u]++;
}

int query(string s) {
    int u=0;
    int ans=0;
    for (int i=0;i<s.size();++i) {
        int c=s[i]-'0';
        if (!tr[u][c]) {
            return ans;
        }
        u=tr[u][c];
        if (i!=s.size()-1) {
            ans+=st[u];
        }
    }
    ans+=cnt[u];
    return ans;
}

int main() {
    scanf("%d %d",&m,&n);
    for (int i=1;i<=m;++i) {
        int len;
        scanf("%d",&len);
        string s;
        for (int j=1;j<=len;++j) {
            int v;
            scanf("%d",&v);
            s+=v+'0';
        }
        insert(s);
    }
    for (int i=1;i<=n;++i) {
        int len;
        scanf("%d",&len);
        string s;
        for (int j=1;j<=len;++j) {
            int v;
            scanf("%d",&v);
            s+=v+'0';
        }
        printf("%d\n",query(s));
    }
    return 0;
}