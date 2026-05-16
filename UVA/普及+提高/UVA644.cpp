#include <bits/stdc++.h>
using namespace std;

const int N=10005;

int tt;
int tr[N][2];
int tot;
bool flag[N];
bool passed[N];
char str[N];
bool ans;

bool insert(char str[]) {
    int u=0;
    bool last=false;
    for (int i=0;str[i];++i) {
        int c=str[i]-'0';
        if (!tr[u][c]) tr[u][c]=++tot;
        u=tr[u][c];
        last=passed[u];
        passed[u]=true;
        if (flag[u]) return true;
    }
    flag[u]=true;
    if (last) return true;
    return false;
}

int main() {
    while (scanf("%s",str)!=EOF) {
        if (str[0]=='9') {
            if (ans) {
                printf("Set %d is not immediately decodable\n",++tt);
            } else {
                printf("Set %d is immediately decodable\n",++tt);
            }
            memset(tr,0,sizeof(tr));
            memset(flag,0,sizeof(flag));
            memset(passed,0,sizeof(passed));
            tot=0;
            ans=false;
            continue;
        }
        ans|=insert(str);
    }
    return 0;
}