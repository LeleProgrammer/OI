#include <bits/stdc++.h>
using namespace std;

const int N=10005;
const int M=15;

int t,n,v;
int tr[N*M][M];
int cnt[N*M];
int tot;
bool flag;
char str[M];

void insert(char str[]) {
    int p=0;
    for (int i=0;str[i];++i) {
        int c=str[i]-'0';
        if (!tr[p][c]) tr[p][c]=++tot;
        p=tr[p][c];
        if (cnt[p]) flag=true;
    }
    cnt[p]++;
    for (int i=0;i<=9;++i) {
        if (tr[p][i]) {
            flag=true;
            break;
        }
    }
}

signed main() {
    scanf("%d",&t);
    while (t--) {
        memset(tr,0,sizeof(tr));
        memset(cnt,0,sizeof(cnt));
        tot=0;
        flag=false;
        scanf("%d",&n);
        while (n--) {
            scanf("%s",str);
            if (!flag) insert(str);
        }
        if (flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}