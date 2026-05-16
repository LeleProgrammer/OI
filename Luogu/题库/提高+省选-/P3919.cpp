#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000005;

int n,m;
int a[MAXN];
int tot;
int roots[MAXN];
int v,op,loc,val;

struct node {
    int l;
    int r;
    int val;
} tr[MAXN*4+MAXN*30];

int build(int l,int r) {
    int curr=++tot;
    if (l==r) {
        tr[curr]={l,r,a[l]};
        return curr;
    } else {
        int mid=l+r>>1;
        tr[curr].l=build(l,mid);
        tr[curr].r=build(mid+1,r);
        return curr;
    }
}

int modify(int p,int l,int r,int tar,int val) {
    int q=++tot;
    tr[q]=tr[p];
    if (l==r) {
        tr[q].val=val;
        return q;
    } else {
        int mid=l+r>>1;
        if (tar<=mid) {
            tr[q].l=modify(tr[p].l,l,mid,tar,val);
        } else {
            tr[q].r=modify(tr[p].r,mid+1,r,tar,val);
        }
        return q;
    }
}

int query(int u,int l,int r,int tar) {
    if (l==r) return tr[u].val;
    int mid=l+r>>1;
    if (tar<=mid) return query(tr[u].l,l,mid,tar);
    else return query(tr[u].r,mid+1,r,tar);
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    roots[0]=build(1,n);
    for (int i=1;i<=m;++i) {
        scanf("%d %d %d",&v,&op,&loc);
        if (op==1) {
            scanf("%d",&val);
            roots[i]=modify(roots[v],1,n,loc,val);
        } else {
            roots[i]=++tot;
            tr[roots[i]]=tr[roots[v]];
            printf("%d\n",query(roots[v],1,n,loc));
        }
    }
    return 0;
}