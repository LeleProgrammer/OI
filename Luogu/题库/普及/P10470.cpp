#include <bits/stdc++.h>
using namespace std;

const int N=1000005;
const int M=35;

int n,m;
int tr[N][M];
int cnt[N];
char str[N];
int tot;

void insert(char str[]) {
    int u=0;
    for (int i=0;str[i];++i) {
        int c=str[i]-'a';
        if (!tr[u][c]) tr[u][c]=++tot;
        u=tr[u][c];
    }
    cnt[u]++;
}

int query(char str[]) {
    int u=0;
    int ans=0;
    for (int i=0;str[i];++i) {
        int c=str[i]-'a';
        if (!tr[u][c]) break;
        u=tr[u][c];
        ans+=cnt[u];
    }
    return ans;
}

int main() {
    scanf("%d %d",&n,&m);
    while (n--) {
        scanf("%s",str);
        insert(str);
    }
    while (m--) {
        scanf("%s",str);
        printf("%d\n",query(str));
    }
    return 0;
}