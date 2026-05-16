#include <bits/stdc++.h>

#define int unsigned long long

using namespace std;

int n,k;
int pw[64];

void init() {
    pw[0]=1;
    for (int i=1;i<=63;++i) {
        pw[i]=pw[i-1]<<1;
    }
}

string dfs(int cnt,int idx) {
    if (cnt==1) {
        if (idx==1) return "0";
        else return "1";
    } else {
        int half=pw[cnt-1];
        if (idx>half) return "1"+dfs(cnt-1,half-(idx-half)+1);
        else return "0"+dfs(cnt-1,idx);
    }
}

signed main() {
    init();
    scanf("%llu %llu",&n,&k);
    if (k==18446744073709551615ULL) cout<<"1000000000000000000000000000000000000000000000000000000000000000";
    else cout<<dfs(n,k+1);
    return 0;
}

/*
ull max: 18446744073709551615
*/