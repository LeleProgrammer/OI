#include <bits/stdc++.h>
using namespace std;

int n;

struct gp {
    int val,item;
} arr[30000005];

stack<gp> s;
int res[3000005];

int main() {
    memset(res,0,sizeof(res));
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i].val);
        arr[i].item=i;
    }
    s.push(arr[1]);
    for (int i=2;i<=n;++i) {
        while (true) {
            if (s.empty()) break;
            if (s.top().val<arr[i].val) {
                res[s.top().item]=i;
                s.pop();
            } else {
                break;
            }
        }
        s.push(arr[i]);
    }
    for (int i=1;i<=n;++i) {
        printf("%d ",res[i]);
    }
    return 0;
}