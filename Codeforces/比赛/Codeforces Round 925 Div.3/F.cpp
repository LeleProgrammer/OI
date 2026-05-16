#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int M=400005;

int T,n,k,tmp,last;
int a[N];
int e[M],ne[M],h[N],tot;
int in[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

bool topu() {
    int cnt=0;
    queue<int> q;
    for (int i=1;i<=n;++i) {
        if (in[i]==0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        cnt++;
        for (int i=h[u];~i;i=ne[i]) {
            in[e[i]]--;
            if (in[e[i]]==0) {
                q.push(e[i]);
            }
        }
    }
    return cnt==n;
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&k);
        tot=0;
        for (int i=1;i<=n;++i) h[i]=-1,in[i]=0;
        for (int i=1;i<=k;++i) {
            for (int i=1;i<=n;++i) {
                scanf("%d",&tmp);
                if (i>=3) {
                    add(last,tmp);
                    in[tmp]++;
                }
                last=tmp;
            }
        }
        if (topu()) puts("YES");
        else puts("NO");
    }
    return 0;
}