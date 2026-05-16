#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=100005;

int n;
int opt,x;
int tot;
int root;

struct node {
    int l,r;
    int key,val;
    int cnt,size;
} tr[N];

int getnode(int k) {
    tr[++tot].key=k;
    tr[tot].size=1;
    tr[tot].cnt=1;
    tr[tot].val=rand();
    return tot;
}

void pushup(int p) {
    tr[p].size=tr[tr[p].l].size+tr[tr[p].r].size+tr[p].cnt;
}

void zig(int &p) {
    int l=tr[p].l;
    tr[p].l=tr[l].r;
    tr[l].r=p;
    p=l;
    pushup(tr[p].r);
    pushup(p);
}

void zag(int &p) {
    int r=tr[p].r;
    tr[p].r=tr[r].l;
    tr[r].l=p;
    p=r;
    pushup(tr[p].l);
    pushup(p);
}

void build() {
    getnode(-inf);
    getnode(inf);
    root=1;
    tr[1].r=2;
    pushup(root);
    if (tr[2].val>tr[1].val) zag(root);
}

void insert(int &p,int x) {
    if (!p) p=getnode(x);
    else if (x==tr[p].key) tr[p].cnt++;
    else if (x<tr[p].key) {
        insert(tr[p].l,x);
        if (tr[tr[p].l].val>tr[p].val) zig(p);
    } else {
        insert(tr[p].r,x);
        if (tr[tr[p].r].val>tr[p].val) zag(p);
    }
    pushup(p);
}

void remove(int &p,int x) {
    if (!p) return;
    else if (x==tr[p].key) {
        if (tr[p].cnt>1) tr[p].cnt--;
        else if (tr[p].l || tr[p].r) {
            if (tr[tr[p].l].val>tr[tr[p].r].val || !tr[p].r) {
                zig(p);
                remove(tr[p].r,x);
            } else {
                zag(p);
                remove(tr[p].l,x);
            }
        } else p=0;
    } else if (x<tr[p].key) remove(tr[p].l,x);
    else remove(tr[p].r,x);
    pushup(p);
}

int get_rank_by_num(int p,int x) {
    if (!p) return inf;
    else if (x==tr[p].key) return tr[tr[p].l].size+1;
    else if (x<tr[p].key) return get_rank_by_num(tr[p].l,x);
    else return get_rank_by_num(tr[p].r,x)+tr[tr[p].l].size+tr[p].cnt;
}

int get_num_by_rank(int p,int x) {
    if (!p) return inf;
    else if (x<=tr[tr[p].l].size) return get_num_by_rank(tr[p].l,x);
    else if (x<=tr[tr[p].l].size+tr[p].cnt) return tr[p].key;
    else return get_num_by_rank(tr[p].r,x-tr[tr[p].l].size-tr[p].cnt);
}

int get_upper_bound(int p,int x) {
    if (!p) return -inf; /* 这里必须使用 -inf，下面返回的时候选择的是 max，如果是 inf 的话会出错 */
    else if (x<=tr[p].key) return get_upper_bound(tr[p].l,x);
    else return max(tr[p].key,get_upper_bound(tr[p].r,x));
}

int get_lower_bound(int p,int x) {
    if (!p) return inf;
    else if (x>=tr[p].key) return get_lower_bound(tr[p].r,x);
    else return min(tr[p].key,get_lower_bound(tr[p].l,x));
}

int main() {
    scanf("%d",&n);
    build();
    while (n--) {
        scanf("%d %d",&opt,&x);
        if (opt==1) insert(root,x);
        else if (opt==2) remove(root,x);
        else if (opt==3) {
            insert(root,x);
            printf("%d\n",get_rank_by_num(root,x)-1);
            remove(root,x);
        }
        else if (opt==4) {
            printf("%d\n",get_num_by_rank(root,x+1));
        }
        else if (opt==5) {
            insert(root,x);
            printf("%d\n",get_upper_bound(root,x));
            remove(root,x);
        }
        else if (opt==6) {
            insert(root,x);
            printf("%d\n",get_lower_bound(root,x));
            remove(root,x);
        }
    }
    return 0;
}