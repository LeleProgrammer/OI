#include <bits/stdc++.h>
using namespace std;

int l,r;
vector<int> nums;
int f[35][35][35]; // f[i][j][k] i位二进制数，j个0，k个1
int ansl,ansr;

void seperate(int num) {
    while (!nums.empty()) nums.pop_back();
    nums.push_back(-0x3f);
    while (num) {
        nums.push_back(num&1);
        num>>=1;
    }
}

int dfs(int pos,int zero,int one,bool limit,bool front_zero) {
    if (!pos) {
        if (zero>=one) return 1;
        else return 0;
    }
    if (!limit && f[pos][zero][one]!=-1 && !front_zero) return f[pos][zero][one];
    int ans=0,maxx;
    if (limit) maxx=nums[pos];
    else maxx=1;
    for (int i=0;i<=maxx;++i) {
        if (!i) ans+=dfs(pos-1,front_zero?0:(zero+1),front_zero?0:one,limit&&i==maxx,front_zero);
        else ans+=dfs(pos-1,zero,one+1,limit&&i==maxx,false);
    }
    if (limit || front_zero) return ans;
    else return f[pos][zero][one]=ans;
}

int main() {
    scanf("%d %d",&l,&r); l--;
    memset(f,-1,sizeof(f));
    seperate(l); ansl=dfs(nums.size()-1,0,0,true,true);
    seperate(r); ansr=dfs(nums.size()-1,0,0,true,true);
    printf("%d",ansr-ansl);
    return 0;
}