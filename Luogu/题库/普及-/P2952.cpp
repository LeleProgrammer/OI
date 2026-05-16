#include <bits/stdc++.h>
using namespace std;

int n,len,cnt=0;
char op,direction;
deque<int> q;

int main() {
    scanf("%d",&n);
    while (scanf(" %c",&op)!=EOF) {
        scanf(" %c",&direction);
        if (op=='A') {
            if (direction=='L') {
                q.push_front(++cnt);
            } else {
                q.push_back(++cnt);
            }
        } else {
            scanf("%d",&len);
            if (direction=='L') {
                while (len--) {
                    q.pop_front();
                }
            } else {
                while (len--) {
                    q.pop_back();
                }
            }
        }
    }
    while (!q.empty()) {
        printf("%d\n",q.front());
        q.pop_front();
    }
    return 0;
}