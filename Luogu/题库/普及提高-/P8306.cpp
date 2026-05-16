#include <bits/stdc++.h>
using namespace std;

int T;
int n,q;
int son[3100005][70];
int cnt[3100005];
int tot;
char str[3100005];

int gc(char c) {
    if (isdigit(c)) return c-'0'; // 0~9
    if (isupper(c)) return c-'A'+10; // 10~35
    if (islower(c)) return c-'a'+36; // 36~61
    return 0;
}

void insert(char str[]) {
    int p=0;
    for (int i=1;i<=strlen(str+1);++i) {
        int c=gc(str[i]);
        if (!son[p][c]) son[p][c]=++tot;
        p=son[p][c];
        cnt[p]++;
    }
}

int query(char str[]) {
    int p=0;
    for (int i=1;i<=strlen(str+1);++i) {
        int c=gc(str[i]);
        if (!son[p][c]) return 0;
        p=son[p][c];
    }
    return cnt[p];
}

int main() {
    scanf("%d",&T);
    while (T--) {
        for (int i=0;i<=tot;++i) {
            for (int j=0;j<=69;++j) {
                son[i][j]=0;
            }
        }
        for (int i=0;i<=tot;++i) {
            cnt[i]=0;
        }
        tot=0;
        scanf("%d %d",&n,&q);
        while (n--) {
            scanf("%s",str+1);
            insert(str);
        }
        while (q--) {
            scanf("%s",str+1);
            printf("%d\n",query(str));
        }
    }
    return 0;
}