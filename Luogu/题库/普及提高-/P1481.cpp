#include <bits/stdc++.h>
using namespace std;

const int N=2005;
const int M=80;

int n;
int tr[N*M][26];
int cnt[N*M];
int tot;
char str[M];
int ans=1;

void insert(char str[]) {
    int p=0;
    for (int i=0;str[i];++i) {
        int c=str[i]-'a';
        if (!tr[p][c]) tr[p][c]=++tot;
        p=tr[p][c];
    }
    cnt[p]++;
}

void dfs(int p,int idx) {
    if (!p) ans=max(ans,idx);
    else {
        for (int i=0;i<=25;++i) {
            dfs(tr[p][i],idx+cnt[p]);
        }
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%s",str);
        insert(str);
    }
    for (int i=0;i<=25;++i) dfs(tr[0][i],0);
    printf("%d",ans);
    return 0;
}