#include <bits/stdc++.h>
using namespace std;

int n;
char str[100005];
int son[100005][26];
int cnt[100005];
int tot=0;
string op;

void insert(char str[]) {
    int p=0;
    for (int i=1;i<=strlen(str+1);++i) {
        int u=str[i]-'a';
        if (!son[p][u]) son[p][u]=++tot;
        p=son[p][u];
    }
    cnt[p]++;
}

int query(char str[]) {
    int p=0;
    for (int i=1;i<=strlen(str+1);++i) {
        int u=str[i]-'a';
        if (!son[p][u]) return 0;
        p=son[p][u];
    }
    return cnt[p];
}

int main() {
    scanf("%d",&n);
    while (n--) {
        cin>>op>>str+1;
        if (op[0]=='I') insert(str);
        else printf("%d\n",query(str));
    }
    return 0;
}