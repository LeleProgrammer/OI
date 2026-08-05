#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> tree[1000005];
int cnt,pt;
int f1[1000005][3]; // maximum 0 1 2 r g b
int f2[1000005][3]; // minimum 0 1 2 r g b

void dfs1() {
    if (s[pt]=='0') {
        ++cnt;
        return;
    }
    if (s[pt]=='1') {
        int v=++cnt;
        tree[v].push_back(v+1);
        ++pt;
        dfs1();
        return;
    }
    if (s[pt]=='2') {
        int v=++cnt;
        tree[v].push_back(v+1);
        ++pt;
        dfs1();
        tree[v].push_back(cnt+1);
        ++pt;
        dfs1();
        return;
    }
}

void dfs2(int pos) {
    if (tree[pos].size()==0) {
        f1[pos][0]=0;
        f1[pos][1]=1;
        f1[pos][2]=0;
    } else if (tree[pos].size()==1) {
        dfs2(tree[pos][0]);
        for (int i=0;i<=2;++i) {
            for (int j=0;j<=2;++j) {
                if (i!=j) {
                    f1[pos][i]=max(f1[pos][i],f1[tree[pos][0]][j]);
                }
            }
        }
        f1[pos][1]++;
    } else {
        dfs2(tree[pos][0]); dfs2(tree[pos][1]);
        for (int i=0;i<=2;++i) {
            for (int j=0;j<=2;++j) {
                for (int k=0;k<=2;++k) {
                    if (i!=j && i!=k && j!=k) {
                        f1[pos][i]=max(f1[pos][i],f1[tree[pos][0]][j]+f1[tree[pos][1]][k]);
                    }
                }
            }
        }
        f1[pos][1]++;
    }
}

void dfs3(int pos) {
    if (tree[pos].size()==0) {
        f2[pos][0]=0;
        f2[pos][1]=1;
        f2[pos][2]=0;
    } else if (tree[pos].size()==1) {
        dfs3(tree[pos][0]);
        for (int i=0;i<=2;++i) {
            for (int j=0;j<=2;++j) {
                if (i!=j) {
                    f2[pos][i]=min(f2[pos][i],f2[tree[pos][0]][j]);
                }
            }
        }
        f2[pos][1]++;
    } else {
        dfs3(tree[pos][0]); dfs3(tree[pos][1]);
        for (int i=0;i<=2;++i) {
            for (int j=0;j<=2;++j) {
                for (int k=0;k<=2;++k) {
                    if (i!=j && i!=k && j!=k) {
                        f2[pos][i]=min(f2[pos][i],f2[tree[pos][0]][j]+f2[tree[pos][1]][k]);
                    }
                }
            }
        }
        f2[pos][1]++;
    }
}

int main() {
    cin>>s;
    cnt=0,pt=0;
    dfs1();
    memset(f1,0,sizeof(f1));
    dfs2(1);
    memset(f2,0x3f,sizeof(f2));
    dfs3(1);
    printf("%d %d",max(max(f1[1][0],f1[1][1]),f1[1][2]),min(min(f2[1][0],f2[1][1]),f2[1][2]));
    return 0;
}