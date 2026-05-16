#include <bits/stdc++.h>
using namespace std;

int n;
int f[8][11];
vector<int> nums;
int len;

void seperate(int n) {
    nums.clear();
    nums.push_back(114514);
    while (n) {
        nums.push_back(n%10);
        n/=10;
    }
    len=nums.size()-1;
}

int dfs(int pos,int sta,bool zero,bool lmt) {
    if (!pos) {
        if (!zero) return 1;
        else return 0;
    }
    if (!lmt && ~f[pos][sta]) return f[pos][sta];
    int res=0,maxx=lmt?nums[pos]:9;
    for (int i=0;i<=maxx;++i) {
        if ((zero && !i) || (!((pos%2)^(i%2)))) {
            res+=dfs(pos-1,i,zero&&!i,lmt&&i==maxx);
        }
    }
    if (lmt && zero) return res;
    return f[pos][sta]=res;
}

int main() {
    memset(f,-1,sizeof(f));
    scanf("%d",&n);
    seperate(n);
    int ans=dfs(len,0,true,true);
    printf("%d",ans);
    putchar(10);
    for (int i=1;i<=5;++i) {
        for (int j=0;j<=9;++j) {
            printf("%d %d: %d\n",i,j,f[i][j]);
        }
    }
    return 0;
}