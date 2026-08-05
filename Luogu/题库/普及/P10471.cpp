#include <bits/stdc++.h>
using namespace std;

const int N=3500005;
const int M=2;

int n;
int tr[N][M];
int tot;
int ans;

void insert(string s) {
    int u=0;
    for (int i=0;i<s.size();++i) {
        int c=s[i]-'0';
        if (!tr[u][c]) tr[u][c]=++tot;
        u=tr[u][c];
    }
}

int query(string s) {
    int u=0;
    int ans=0;
    for (int i=0;i<s.size();++i) {
        int c=s[i]-'0';
        if (tr[u][c^1]) {
            u=tr[u][c^1];
            ans<<=1;
            ans|=1;
        } else {
            u=tr[u][c];
            ans<<=1;
        }
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        int k;
        scanf("%d",&k);
        string s;
        while (k) {
            s.push_back((k&1)+'0');
            k>>=1;
        }
        while (s.size()<32) s.push_back('0');
        reverse(s.begin(),s.end());
        if (i!=1) ans=max(ans,query(s));
        insert(s);
    }
    printf("%d",ans);
    return 0;
}