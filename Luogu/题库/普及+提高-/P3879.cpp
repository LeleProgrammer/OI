#include <bits/stdc++.h>
using namespace std;

int n,m,l;
int son[500005][30];
vector<int> cnt[500005];
int tot;
char str[25];

void insert(char str[],int num) {
    int p=0;
    for (int i=1;str[i];++i) {
        int u=str[i]-'a';
        if (!son[p][u]) son[p][u]=++tot;
        p=son[p][u];
    }
    if ((cnt[p].size() && cnt[p].back()!=num) || !cnt[p].size()) cnt[p].push_back(num);
}

int query(char str[]) {
    int p=0;
    for (int i=1;str[i];++i) {
        int u=str[i]-'a';
        if (!son[p][u]) return 0;
        p=son[p][u];
    }
    if (cnt[p].size()) return p;
    else return 0;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&l);
        while (l--) {
            scanf("%s",str+1);
            insert(str,i);
        }
    }
    scanf("%d",&m);
    while (m--) {
        scanf("%s",str+1);
        int item=query(str);
        if (!item) {
            printf("\n");
        } else {
            for (int i=0;i<cnt[item].size();++i) {
                printf("%d ",cnt[item][i]);
            }
            printf("\n");
        }
    }
    return 0;
}