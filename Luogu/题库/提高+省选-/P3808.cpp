#include <bits/stdc++.h>
using namespace std;

const int N=1000005;
const int T=1000005;
const int L=1000005;

int n;
int tr[L][26];
int ne[L];
int cnt[L];
char str[L];
char com[T];
int tot;
int q[L];
bool vis[L];

void insert(char str[]) {
    int p=0;
    for (int i=0;str[i];++i) {
        int c=str[i]-'a';
        if (!tr[p][c]) tr[p][c]=++tot;
        p=tr[p][c];
    }
    cnt[p]++;
}

void build() {
    int head=0,tail=-1;
    for (int i=0;i<=25;++i) {
        if (tr[0][i]) q[++tail]=tr[0][i];
    }
    while (head<=tail) {
        int curr=q[head++];
        for (int i=0;i<=25;++i) {
            if (!tr[curr][i]) tr[curr][i]=tr[ne[curr]][i];
            else {
                ne[tr[curr][i]]=tr[ne[curr]][i];
                q[++tail]=tr[curr][i];
            }
        }
    }
}

int main() {
    scanf("%d",&n);
    while (n--) {
        scanf("%s",str);
        insert(str);
    }
    build();
    scanf("%s",com);
    int ans=0;
    for (int i=0,curr=0;com[i];++i) {
        int c=com[i]-'a';
        curr=tr[curr][c];
        for (int j=curr;j && !vis[j];j=ne[j]) {
            ans+=cnt[j];
            cnt[j]=0;
            vis[j]=true;
        }
    }
    printf("%d",ans);
    return 0;
}