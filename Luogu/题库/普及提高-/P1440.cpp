#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[20000005];
deque<int> q;
deque<int> it;

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",a+i);
    printf("0\n");
    for (int i=1;i<=n-1;++i) {
        if (!q.empty() && it.front()<i-m+1) {
            it.pop_front();
            q.pop_front();
        } 
        if (q.empty() || a[i]>=q.back()) {
            q.push_back(a[i]);
            it.push_back(i);
        } else {
            while (!q.empty() && q.back()>a[i]) q.pop_back(),it.pop_back();
            q.push_back(a[i]);
            it.push_back(i);
        }
        printf("%d\n",q.front());
    }
    return 0;
}