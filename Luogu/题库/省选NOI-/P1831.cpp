#include <bits/stdc++.h>

#define int long long
#define NONE -0x3f

using namespace std;

int x,y;
int f[35][10005][35];
vector<int> nums;
int ans1,ans2;

int dfs(int pos,int sta,int dot,bool lmt) {
    if (!pos) return !sta;
    if (sta<0) return 0;
    if (!lmt && f[pos][sta][dot]!=NONE) return f[pos][sta][dot];
    int res=0,maxx=lmt?nums[pos]:9;
    for (int i=0;i<=maxx;++i) res+=dfs(pos-1,sta+(pos-dot)*i,dot,lmt&&i==maxx);
    if (!lmt) return f[pos][sta][dot]=res;
    return res;
}

void init() {
    for (int i=0;i<=34;++i) {
        for (int j=0;j<=10004;++j) {
            for (int k=0;k<=34;++k) {
                f[i][j][k]=NONE;
            }
        }
    }
}

void seperate(int n) {
    while (!nums.empty()) nums.pop_back();
    nums.push_back(NONE);
    while (n) nums.push_back(n%10),n/=10;
}

signed main() {
    scanf("%lld %lld",&x,&y);
    init();
    seperate(x-1);
    for (int i=1;i<=nums.size()-1;++i) ans1+=dfs(nums.size()-1,0,i,true); ans1-=nums.size()-2;
    seperate(y);
    for (int i=1;i<=nums.size()-1;++i) ans2+=dfs(nums.size()-1,0,i,true); ans2-=nums.size()-2;
    printf("%lld",ans2-ans1);
    return 0;
}