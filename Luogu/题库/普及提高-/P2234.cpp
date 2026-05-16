#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=32767+5;

int n;
int tot;
int root;
int a;
int res;

struct node {
    int l,r;
    int key,val;
    int cnt;
} tr[N];

void zig(int &p) {
    int q=tr[p].l;
    tr[p].l=tr[q].r;
    tr[q].r=p;
    p=q;
}

void zag(int &p) {
    int q=tr[p].r;
    tr[p].r=tr[q].l;
    tr[q].l=p;
    p=q;
}

int get_node(int k) {
    tr[++tot].key=k;
    tr[tot].val=rand();
    tr[tot].cnt=1;
    return tot;
}

void build() {
    get_node(-inf);
    get_node(inf);
    root=1;
    tr[root].r=2;
}

void insert(int &p,int x) {
    if (!p) p=get_node(x);
    else if (x==tr[p].key) tr[p].cnt++;
    else if (x<tr[p].key) {
        insert(tr[p].l,x);
        if (tr[tr[p].l].val>tr[p].val) zig(p);
    } else {
        insert(tr[p].r,x);
        if (tr[tr[p].r].val>tr[p].val) zag(p);
    }
}

int get_upper_bound(int &p,int x) {
    if (!p) return -inf;
    else if (x<tr[p].key) return get_upper_bound(tr[p].l,x);
    else if (x==tr[p].key) {
        if (tr[p].cnt>=2) return tr[p].key;
        else return get_upper_bound(tr[p].l,x);
    }
    else return max(get_upper_bound(tr[p].r,x),tr[p].key);
}

int get_lower_bound(int &p,int x) {
    if (!p) return inf;
    else if (x>tr[p].key) return get_lower_bound(tr[p].r,x);
    else if (x==tr[p].key) {
        if (tr[p].cnt>=2) return tr[p].key;
        else return get_lower_bound(tr[p].r,x);
    }
    else return min(get_lower_bound(tr[p].l,x),tr[p].key);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a);
        insert(root,a);
        if (i==1) {
            res+=a;
            continue;
        }
        int l,r;
        l=get_upper_bound(root,a);
        r=get_lower_bound(root,a);
        l=abs(a-l);
        r=abs(a-r);
        res+=min(l,r);
    }
    printf("%d",res);
    return 0;
}