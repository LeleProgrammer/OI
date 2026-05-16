#include <bits/stdc++.h>
using namespace std;

const int N=1500000;

int n;
bool flag[N];
vector<int> p;

void init() {
    for (int i=0;i<N;++i) flag[i]=true;
    flag[0]=flag[1]=false;
    for (int i=2;i<N;++i) {
        for (int j=i+i;j<N;j+=i) {
            flag[j]=false;
        }
    }
    for (int i=0;i<N;++i) {
        if (flag[i]) p.push_back(i);
    }
}

int main() {
    init();
    while (true) {
        scanf("%d",&n);
        if (!n) break;
        if (flag[n]) {
            puts("0");
            continue;
        }
        int pos=lower_bound(p.begin(),p.end(),n)-p.begin();
        printf("%d\n",p[pos]-p[pos-1]);
    }
    return 0;
}