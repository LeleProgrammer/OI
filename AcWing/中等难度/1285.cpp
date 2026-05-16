#include <bits/stdc++.h>
using namespace std;

const int N=205;
const int L=1000005;

int n;
int tr[L][26];
int ne[L];
int ed[N];
char str[L];
int tot;
int q[L];
int ans[L];
int bfs[L],len;

void insert(char str[],int k) {
    int p=0;
    for (int i=0;str[i];++i) {
        int c=str[i]-'a';
        if (!tr[p][c]) tr[p][c]=++tot;
        p=tr[p][c];
        ans[p]++;
    }
    ed[k]=p;
}

void build() {
    int head=0,tail=-1;
    for (int i=0;i<=25;++i) {
        if (tr[0][i]) q[++tail]=tr[0][i],bfs[++len]=tr[0][i];
    }
    while (head<=tail) {
        int curr=q[head++];
        for (int i=0;i<=25;++i) {
            if (!tr[curr][i]) tr[curr][i]=tr[ne[curr]][i];
            else {
                ne[tr[curr][i]]=tr[ne[curr]][i];
                q[++tail]=tr[curr][i];
                bfs[++len]=tr[curr][i];
            }
        }
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%s",str);
        insert(str,i);
    }
    build();
    for (int i=len;i>=1;--i) {
        ans[ne[bfs[i]]]+=ans[bfs[i]];
    }
    for (int i=1;i<=n;++i) printf("%d\n",ans[ed[i]]);
    return 0;
}