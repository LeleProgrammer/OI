#include <bits/stdc++.h>
using namespace std;

stack<int> pit;

int main() {
    int n;
    scanf("%d",&n);
    int type,weight;
    for (int i=0;i<n;++i) {
        scanf("%d",&type);
        switch (type) {
            case 0: {
                scanf("%d",&weight);
                pit.push(weight);
                break;
            }
            case 1: {
                if (pit.empty()) {
                    break;
                }
                pit.pop();
                break;
            }
            case 2: {
                if (pit.empty()) {
                    printf("0\n");
                    break;
                }
                stack<int> help;
                int maxx=0;
                while (!pit.empty()) {
                    if (pit.top()>maxx) {
                        maxx=pit.top();
                    }
                    help.push(pit.top());
                    pit.pop();
                }
                while (!help.empty()) {
                    pit.push(help.top());
                    help.pop();
                }
                printf("%d\n",maxx);
                break;
            }
            default: {
                break;
            }
        }
    }
    return 0;
}