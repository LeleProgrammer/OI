#include <bits/stdc++.h>
using namespace std;

int n,m;
int qua[100005];
deque<int> val;
deque<int> it;

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",qua+i);
    for (int i=1;i<=n;++i) {
        if (!it.empty() && it.front()<i-m+1) {
            it.pop_front();
            val.pop_front();
        }
        if (val.empty() || qua[i]>=val.back()) {
            val.push_back(qua[i]);
            it.push_back(i);
        } else {
            while (!val.empty() && val.back()>qua[i]) {
                val.pop_back();
                it.pop_back();
            }
            val.push_back(qua[i]);
            it.push_back(i);
        }
        if (i>=m) printf("%d\n",val.front());
    }
    return 0;
}