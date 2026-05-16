#include <bits/stdc++.h>
using namespace std;

int T,n;
string strs[10005];
int son[1500005][15];
bool cnt[1500005];
int tot=0;
bool ok=false;

bool cmp(const string& a,const string& b) {
    return a.size()<b.size();
}

int insert(const char str[]) {
    int p=0;
    for (int i=0;str[i];++i) {
        int u=str[i]-'0';
        if (!son[p][u]) son[p][u]=++tot;
        p=son[p][u];
        if (cnt[p]) return 1;
    }
    cnt[p]=true;
    return 0;
}

int main() {
    memset(son,0,sizeof(son));
    memset(cnt,false,sizeof(false));
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        ok=false;
        for (int i=0;i<=tot;++i) {
            for (int j=0;j<=9;++j) {
                son[i][j]=0;
            }
            cnt[i]=false;
        }
        tot=0;
        for (int i=1;i<=n;++i) {
            cin>>strs[i];
        }
        sort(strs+1,strs+1+n,cmp);
        for (int i=1;i<=n;++i) {
            if (insert(strs[i].c_str())) {
                ok=true;
                break;
            }
        }
        if (ok) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}