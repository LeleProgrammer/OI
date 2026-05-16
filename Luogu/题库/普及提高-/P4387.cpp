#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    scanf("%d",&q);
    for (int i=0;i<q;++i) {
        int n;
        scanf("%d",&n);
        stack<int> main_s;
        queue<int> pushed,poped;
        for (int j=0;j<n;++j) {
            int in;
            scanf("%d",&in);
            pushed.push(in);
        }
        for (int j=0;j<n;++j) {
            int in;
            scanf("%d",&in);
            poped.push(in);
        }
        while (true) {
            if (main_s.empty()) {
                if (pushed.empty()) {
                    printf("No\n");
                    break;
                } else {
                    main_s.push(pushed.front());
                    pushed.pop();
                }
            } else {
                if (main_s.top()==poped.front()) {
                    main_s.pop();
                    poped.pop();
                    if (poped.empty()) {
                        printf("Yes\n");
                        break;
                    }
                } else {
                    if (pushed.empty()) {
                        printf("No\n");
                        break;
                    } else {
                        main_s.push(pushed.front());
                        pushed.pop();
                    }
                }
            }
        }
    }
    return 0;
}