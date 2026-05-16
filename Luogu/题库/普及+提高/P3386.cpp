#include <bits/stdc++.h>
using namespace std;

const int N=505;
const int M=50005;

int nl,nr,m;
int e[M],ne[M],h[N],tot;
bool sta[N];
int mat[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

bool loc(int curr) {
    for (int i=h[curr];~i;i=ne[i]) {
        if (!sta[e[i]]) {
            sta[e[i]]=true;
            if (mat[e[i]]==0 || loc(mat[e[i]])) {
                mat[e[i]]=curr;
                return true;
            }
        }
    }
    return false;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d",&nl,&nr,&m);
    while (m--) {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
    }
    int ans=0;
    for (int i=1;i<=nl;++i) {
        memset(sta,0,sizeof(sta));
        if (loc(i)) ans++;
    }
    printf("%d",ans);
    return 0;
}