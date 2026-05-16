#include <bits/stdc++.h>
using namespace std;

const int N=32768;

int n;
vector<int> ps;
bool flag[N];

void init() {
    for (int i=0;i<=N;++i) flag[i]=true;
    flag[0]=flag[1]=false;
    for (int i=2;i<=N;++i) {
        for (int j=i+i;j<=N;j+=i) {
            flag[j]=false;
        }
    }
    for (int i=0;i<=N;++i) {
        if (flag[i]) ps.push_back(i);
    }
}

int main() {
    init();
    while (true) {
        scanf("%d",&n);
        if (!n) break;
        int ans=0;
        for (int i=0;i<ps.size() && ps[i]<=n;++i) {
            if (flag[n-ps[i]]) {
                ans++;
                if (n-ps[i]==ps[i]) ans++;
            }
        }
        printf("%d\n",ans/2);
    }
    return 0;
}