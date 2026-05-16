#include <bits/stdc++.h>

#define int long long

using namespace std;

int a,b,len,t,ansa,ansb;
const int MAXN=25;
const int MAXK=59049+10;
int f[MAXN][MAXK][2];
vector<int> num;

namespace Ternary {

    int pw[25];

    inline void create_pw() {
        register int k=1;
        for (register int i=0;i<=MAXN;++i,k*=3) {
            pw[i]=k;
        }
    }

    inline int L(int a,int b) {
        a*=pw[b];
        return a;
    }

    inline int R(int a,int b) {
        a/=pw[b];
        return a;
    }

    inline int G(int a,int b) {
        return R(a,b)%3;
    }

    inline bool C(int a,int b,int c) {
        return G(a,b)==c;
    }

    inline int S(int a,int b,int c) {
        a-=L(G(a,b),b);
        a+=L(c,b);
        return a;
    }

}

using namespace Ternary;

inline void init() {
    for (int i=0;i<=MAXN-1;++i) {
        for (int j=0;j<=MAXK-1;++j) {
            f[i][j][0]=f[i][j][1]=-1;
        }
    }
}

inline void split(int n) {
    while (!num.empty()) {
        num.pop_back();
    }
    num.push_back(-0x3f);
    while (n) {
        num.push_back(n%10);
        n/=10;
    }
    len=num.size()-1;
}

int dfs(int pos,int state,bool zero,bool limit) {
    if (!pos) {
        for (register int i=0;i<=9;++i) {
            if (!((G(state,i)==0) || (G(state,i)==1 && i%2==0) || (G(state,i)==2 && i%2==1))) {
                return 0;
            }
        }
        return 1;
    }
    if (f[pos][state][zero]!=-1 && !limit) return f[pos][state][zero];
    int ans=0; int maxx;
    if (limit) maxx=num[pos];
    else maxx=9;
    for (register int i=0;i<=maxx;++i) {
        if (G(state,i)==1) ans=ans+dfs(pos-1,zero&&i==0?0:S(state,i,2),zero && i==0,limit && i==maxx);
        else ans=ans+dfs(pos-1,zero&&i==0?0:S(state,i,1),zero && i==0,limit && i==maxx);
    }
    if (limit) return ans;
    else return f[pos][state][zero]=ans;
}

signed main() {
    init(); create_pw();
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld %lld",&a,&b); a--;
        split(a); ansa=dfs(len,0,true,true);
        split(b); ansb=dfs(len,0,true,true);
        printf("%lld\n",ansb-ansa);
    }
    return 0;
}