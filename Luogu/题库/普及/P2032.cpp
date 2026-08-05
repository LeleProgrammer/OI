#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[2000005];
deque<int> val;
deque<int> it;

int main() {
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i) {
        scanf("%d",a+i);
    }
    for (int i=1;i<=n;++i) {
        if (!it.empty() && it.front()<i-k+1) {
            it.pop_front();
            val.pop_front();
        }
        if (val.empty() || a[i]<=val.back()) {
            val.push_back(a[i]);
            it.push_back(i);
        } else {
            while (!val.empty() && val.back()<a[i]) {
                val.pop_back();
                it.pop_back();
            }
            val.push_back(a[i]);
            it.push_back(i);
        }
        if (i>=k) {
            printf("%d\n",val.front());
        }
    }
    return 0;
}