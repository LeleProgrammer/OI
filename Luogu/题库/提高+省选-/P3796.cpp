#include <bits/stdc++.h>
using namespace std;

const int N=10505;
const int M=35;
const int K=75;
const int P=1000005;

int n;
int tr[N][M],tot;
int ne[N*M];
int cnt[N*M];
char T[P];
char strs[155][K];
int ans[155];
queue<int> q;

void insert(char str[],int idx) {
    int u=0;
    for (int i=0;str[i];++i) {
        int c=str[i]-'a';
        if (!tr[u][c]) tr[u][c]=++tot;
        u=tr[u][c];
    }
    cnt[u]=idx;
}

void build() {
    for (int i=0;i<=25;++i) {
        if (tr[0][i]) q.push(tr[0][i]);
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=0;i<=25;++i) {
            if (!tr[u][i]) tr[u][i]=tr[ne[u]][i];
            else {
                ne[tr[u][i]]=tr[ne[u]][i];
                q.push(tr[u][i]);
            }
        }
    }
}

int main() {
    while (true) {
        scanf("%d",&n);
        if (!n) break;
        memset(tr,0,sizeof(tr)); tot=0;
        memset(ans,0,sizeof(ans));
        memset(ne,0,sizeof(ne));
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;++i) {
            scanf("%s",strs[i]);
        }
        for (int i=1;i<=n;++i) {
            insert(strs[i],i);
        }
        scanf("%s",T);
        build();
        for (int i=0,j=0;T[i];++i) {
            int c=T[i]-'a';
            j=tr[j][c];
            for (int u=j;u;u=ne[u]) {
                if (!cnt[u]) continue;
                ans[cnt[u]]++;
            }
        }
        int maxx=0;
        for (int i=1;i<=n;++i) {
            maxx=max(maxx,ans[i]);
        }
        printf("%d\n",maxx);
        for (int i=1;i<=n;++i) {
            if (ans[i]==maxx) {
                printf("%s\n",strs[i]);
            }
        }
    }
    return 0;
}