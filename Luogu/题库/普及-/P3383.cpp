#include <bits/stdc++.h>
using namespace std;

const int N=5800005;
const int M=100000005;

int n,q;
int pri[N],idx;
bool flag[M];

void init() {
    for (int i=2;i<M;++i) {
        if (!flag[i]) pri[++idx]=i;
        for (int j=1;j<=idx && pri[j]*i<M;++j) {
            flag[i*pri[j]]=true;
            if (i%pri[j]==0) break;
        }
    }
}

int main() {
    init();
    scanf("%d %d",&n,&q);
    while (q--) {
        int k;
        scanf("%d",&k);
        printf("%d\n",pri[k]);
    }
    return 0;
}