#include <bits/stdc++.h>
using namespace std;

const int N=12000005;

int n;
int tot;

struct node {
    int l,r;
    int size;
    char c;
} tr[N];

int root[N],pt;
int cnt[N];

int build(int l,int r) {
    int u=++tot;
    tr[u].size=r-l+1;
    if (l==r) return tot;
    int mid=l+r>>1;
    tr[u].l=build(l,mid);
    tr[u].r=build(mid+1,r);
    return tot;
}

void modify(int p,int& u,int l,int r,int pos,char x) {
    u=++tot;
    tr[u].l=tr[p].l;
    tr[u].r=tr[p].r;
    tr[u].size=tr[p].size;
    tr[u].c=tr[p].c;
    if (l==r) tr[u].c=x;
    else {
        int mid=l+r>>1;
        if (pos<=mid) modify(tr[p].l,tr[u].l,l,mid,pos,x);
        else modify(tr[p].r,tr[u].r,mid+1,r,pos,x);
    }
}

char query(int u,int l,int r,int pos) {
    if (l==r) return tr[u].c;
    int mid=l+r>>1;
    if (pos<=mid) return query(tr[u].l,l,mid,pos);
    else return query(tr[u].r,mid+1,r,pos);
}

int main() {
    scanf("%d",&n);
    root[0]=build(1,n);
    cnt[0]=0;
    pt=0;
    for (int i=1;i<=n;++i) {
        char op[2];
        scanf("%s",op);
        if (*op=='T') {
            char c;
            scanf(" %c",&c);
            pt++;
            cnt[pt]=cnt[pt-1]+1;
            root[pt]=0;
            modify(root[pt-1],root[pt],1,n,cnt[pt],c);
        } else if (*op=='U') {
            int x;
            scanf("%d",&x);
            root[pt+1]=++tot;
            auto &u=tr[root[pt+1]];
            auto p=tr[root[pt-x]];
            u.l=p.l;
            u.r=p.r;
            u.size=p.size;
            u.c=p.c;
            cnt[pt+1]=cnt[pt-x];
            pt++;
        } else if (*op=='Q') {
            int x;
            scanf("%d",&x);
            printf("%c\n",query(root[pt],1,n,x));
        }
    }
    return 0;
}