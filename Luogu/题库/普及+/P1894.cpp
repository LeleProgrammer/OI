#include <bits/stdc++.h>
using namespace std;

const int N=205;
const int M=40005;

int n,m;
int e[M],ne[M],h[N],tot;
int mat[N];
bool sta[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

bool loc(int curr) {
    for (int i=h[curr];~i;i=ne[i]) {
        if (!sta[e[i]]) {
            sta[e[i]]=true;
            if (mat[e[i]]==-1 || loc(mat[e[i]])) {
                mat[e[i]]=curr;
                return true;
            }
        }
    }
    return false;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        int s;
        scanf("%d",&s);
        while (s--) {
            int u;
            scanf("%d",&u);
            add(i,u);
        }
    }
    memset(mat,-1,sizeof(mat));
    int ans=0;
    for (int i=1;i<=n;++i) {
        memset(sta,0,sizeof(sta));
        if (loc(i)) ans++;
    }
    printf("%d",ans);
    return 0;
}