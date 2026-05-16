#include <bits/stdc++.h>
using namespace std;

stack<unsigned long long> stk;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        for (int i=0;i<n;++i) {
            string type;
            cin>>type;
            if (type=="push") {
                unsigned long long x;
                cin>>x;
                stk.push(x);
            } else if (type=="pop") {
                if (stk.empty()) {
                    printf("Empty\n");
                } else {
                    stk.pop();
                }
            } else if (type=="query") {
                if (stk.empty()) {
                    printf("Anguei!\n");
                } else {
                    printf("%llu\n",stk.top());
                }
            } else {
                printf("%d\n",stk.size());
            }
        }
        while (!stk.empty()) {
            stk.pop();
        }
    }
    return 0;
}

// ¿ªunsigned long long