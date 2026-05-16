#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    int q;
    scanf("%d", &q);
    int op, x;
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &op, &x);
        if (op == 5) {
            v.push_back(x);
        } else {
            sort(v.begin(), v.end());
            if (op == 1) {
                auto it = lower_bound(v.begin(), v.end(), x);
                int rank = it - v.begin() + 1;
                printf("%d\n", rank);
            } else if (op == 2) {
                printf("%d\n", v[x - 1]);
            } else if (op == 3) {
                auto it = lower_bound(v.begin(), v.end(), x);
                if (it != v.begin()) {
                    --it;
                    printf("%d\n", *it);
                } else {
                    printf("%d\n", -2147483647);
                }
            } else if (op == 4) {
                auto it = upper_bound(v.begin(), v.end(), x);
                if (it != v.end()) {
                    printf("%d\n", *it);
                } else {
                    printf("%d\n", 2147483647);
                }
            }
        }
    }
    return 0;
}
