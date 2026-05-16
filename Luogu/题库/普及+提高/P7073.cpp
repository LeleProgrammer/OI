#include <bits/stdc++.h>
using namespace std;

const int N=1000005;

int n,q;
int cnt,root;
int a[N]; // &:0 |:-1 !:-2
int arr[N];
int b[N];
stack<int> stk;
int expr;

struct node {
    int l,r;
    int val;
    bool tag;
} tr[N];

void build() {
    for (int i=1;i<=cnt;++i) {
        tr[i].val=a[i];
    }
    for (int i=1;i<=cnt;++i) {
        if (a[i]>=1) stk.push(i);
        else {
            if (a[i]==-2) {
                int a=stk.top(); stk.pop();
                tr[i].l=a;
                stk.push(i);
            } else {
                int a=stk.top(); stk.pop();
                int b=stk.top(); stk.pop();
                tr[i].l=a;
                tr[i].r=b;
                stk.push(i);
            }
        }
    }
    root=stk.top(); stk.pop();
}

int dfs(int u) {
    if (!u) return 0;
    int l=dfs(tr[u].l);
    int r=dfs(tr[u].r);
    if (tr[u].val>=1) {
        b[tr[u].val]=u;
        return arr[tr[u].val];
    }
    if (tr[u].val==0) {
        if (!l) tr[tr[u].r].tag=1;
        if (!r) tr[tr[u].l].tag=1;
        return l&r;
    } else if (tr[u].val==-1) {
        if (l) tr[tr[u].r].tag=1;
        if (r) tr[tr[u].l].tag=1;
        return l|r;
    } else return l^1;
}

void pushdown(int u,bool flag) {
    if (flag) tr[u].tag=1;
    if (tr[u].l) pushdown(tr[u].l,flag|tr[tr[u].l].tag);
    if (tr[u].r) pushdown(tr[u].r,flag|tr[tr[u].r].tag);
}

int main() {
    string s;
    getline(cin,s);
    for (int i=0;i<s.size();++i) {
        if (s[i]=='x') {
            int num=0;
            int j;
            for (j=i+1;isdigit(s[j]);++j) {
                num=num*10+s[j]-'0';
            }
            i=j;
            a[++cnt]=num;
        } else {
            if (s[i]=='&') a[++cnt]=0;
            else if (s[i]=='|') a[++cnt]=-1;
            else a[++cnt]=-2;
            ++i;
        }
    }
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    build();
    expr=dfs(root);
    pushdown(root,tr[root].tag);
    scanf("%d",&q);
    while (q--) {
        int v;
        scanf("%d",&v);
        if (tr[b[v]].tag) printf("%d",expr);
        else printf("%d",expr^1);
        putchar(10);
    }
    return 0;
}