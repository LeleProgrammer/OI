#include <bits/stdc++.h>
using namespace std;

int n,m;
int son1[600005][26];
int son2[600005][26];
int cnt1[600005];
int cnt2[600005];
char str[10005];
int tot,tot2;

void insert(char str[]) {
    int p=0;
    for (int i=1;str[i];++i) {
        int u=str[i]-'a';
        if (!son1[p][u]) son1[p][u]=++tot;
        p=son1[p][u];
    }
    cnt1[p]++;
}

void insert2(char str[]) {
    int p=0;
    for (int i=1;str[i];++i) {
        int u=str[i]-'a';
        if (!son2[p][u]) son2[p][u]=++tot2;
        p=son2[p][u];
    }
    cnt2[p]++;
}

int query(char str[]) {
    int p=0;
    for (int i=1;str[i];++i) {
        int u=str[i]-'a';
        if (!son1[p][u]) return 0;
        p=son1[p][u];
    }
    if (!cnt1[p]) return 0;
    return 1;
}

int query2(char str[]) {
    int p=0;
    for (int i=1;str[i];++i) {
        int u=str[i]-'a';
        if (!son2[p][u]) return 0;
        p=son2[p][u];
    }
    if (!cnt2[p]) return 0;
    return 1;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        cin>>str+1;
        insert(str);
    }
    scanf("%d",&m);
    for (int i=1;i<=m;++i) {
        cin>>str+1;
        int a,b;
        a=query(str);
        if (!a) {
            printf("WRONG\n");
            continue;
        }
        b=query2(str);
        if (!b) {
            printf("OK\n");
            insert2(str);
        } else {
            printf("REPEAT\n");
        }
    }
    return 0;
}