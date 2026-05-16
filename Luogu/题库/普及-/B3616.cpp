#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
    int n;
    scanf("%d",&n);
    int type,x;
    for (int i=0;i<n;++i) {
        scanf("%d",&type);
        if (type==1) {
            scanf("%d",&x);
            q.push(x);
        } else if (type==2) {
            if (q.empty()) {
                printf("ERR_CANNOT_POP\n");
            } else {
                q.pop();
            }
        } else if (type==3) {
            if (q.empty()) {
                printf("ERR_CANNOT_QUERY\n");
            } else {
                printf("%d\n",q.front());
            }
        } else if (type==4) {
            printf("%d\n",q.size());
        }
    }
    return 0;
}