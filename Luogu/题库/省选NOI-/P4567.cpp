#include <bits/stdc++.h>
using namespace std;

const int N=2197152; // 2^21+1e5

int n;
int root;
int cur;
int tot;

struct Splay {
    int s[2],p;
    int size;
    char c;
    int flag;
    void init(int p,int c) {
        this->p=p;
        this->c=c;
        this->size=1;
    }
} tr[N];

void pushup(int u) {
    tr[u].size=tr[tr[u].s[0]].size+tr[tr[u].s[1]].size+1;
}

void pushdown(int u) {
    if (tr[u].flag) {
        swap(tr[u].s[0],tr[u].s[1]);
        tr[tr[u].s[0]].flag^=1;
        tr[tr[u].s[1]].flag^=1;
        tr[u].flag^=1;
    }
}

void rotate(int x) {
    int y=tr[x].p;
    int z=tr[y].p;
    int k=(x==tr[y].s[1]);
    tr[z].s[tr[z].s[1]==y]=x,tr[x].p=z;
    tr[y].s[k]=tr[x].s[k^1],tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y,tr[y].p=x;
    pushup(y);
    pushup(x);
}

void splay(int x,int k) {
    while (tr[x].p!=k) {
        int y=tr[x].p;
        int z=tr[y].p;
        if (z!=k) {
            if ((y==tr[z].s[1])^(x==tr[y].s[1])) {
                rotate(x);
            } else {
                rotate(y);
            }
        }
        rotate(x);
    }
    if (!k) root=x;
}

int getk(int k) {
    int u=root;
    while (true) {
        pushdown(u);
        if (tr[tr[u].s[0]].size>=k) u=tr[u].s[0];
        else if (k==tr[tr[u].s[0]].size+1) return u;
        else k-=tr[tr[u].s[0]].size+1,u=tr[u].s[1];
    }
}

int insert(int l,int r,int p,string& s) {
    int u=++tot;
    int mid=l+r>>1;
    tr[u].init(p,s[mid]);
    if (l!=r) {
        if (l<=mid-1) tr[u].s[0]=insert(l,mid-1,u,s);
        if (mid+1<=r) tr[u].s[1]=insert(mid+1,r,u,s);
        pushup(u);
    }
    return u;
}

void init() {
    root=++tot;
    tr[root].init(0,' ');
    tr[++tot].init(root,' ');
    tr[root].s[1]=tot;
    pushup(root);
    cur=1;
}

int main() {
    init();
    scanf("%d",&n);
    while (n--) {
        char op[6];
        scanf(" %s",op);
        if (!strcmp(op,"Move")) {
            int k;
            scanf("%d",&k); k++;
            cur=k;
        } else if (!strcmp(op,"Insert")) {
            int m;
            string s=" ";
            scanf("%d",&m);
            int cnt=0;
            bool start=false;
            while (true) {
                char c=getchar();
                if ((c<32 || c>126) && !start) {
                    start=true;
                    continue;
                }
                start=true;
                cnt++;
                s.push_back(c);
                if (cnt==m) break;
            }
            splay(getk(cur),0);
            splay(getk(cur+1),root);
            tr[tr[root].s[1]].s[0]=insert(1,cnt,tr[root].s[1],s);
            pushup(tr[root].s[1]);
            pushup(root);
        } else if (!strcmp(op,"Delete")) {
            int m;
            scanf("%d",&m);
            splay(getk(cur),0);
            splay(getk(cur+m+1),root);
            tr[tr[root].s[1]].s[0]=0;
            pushup(tr[root].s[1]);
            pushup(root);
        } else if (!strcmp(op,"Rotate")) {
            int m;
            scanf("%d",&m);
            splay(getk(cur),0);
            splay(getk(cur+m+1),root);
            tr[tr[tr[root].s[1]].s[0]].flag^=1;
        } else if (!strcmp(op,"Get")) {
            splay(getk(cur+1),0);
            printf("%c",tr[root].c);
            if (tr[root].c!='\n') putchar(10);
        } else if (!strcmp(op,"Prev")) {
            cur--;
        } else if (!strcmp(op,"Next")) {
            cur++;
        }
    }
    return 0;
}