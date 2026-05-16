#include <bits/stdc++.h>
using namespace std;

const int N=4005;
const int M=16005;

int n;
int e[M],ne[M],h[N],tot;
int mat[N];
bool sta[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

bool loc(int u) {
    for (int i=h[u];~i;i=ne[i]) {
        if (!sta[e[i]]) {
            sta[e[i]]=true;
            if (mat[e[i]]==0 || loc(mat[e[i]])) {
                mat[e[i]]=u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n*2;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(i,a); add(i,b);
        add(i,a+n); add(i,b+n);
    }
    int ans=0;
    for (int i=1;i<=n*2;++i) {
        memset(sta,0,sizeof(sta));
        if (loc(i)) ans++;
    }
    printf("%d",ans);
    return 0;
}