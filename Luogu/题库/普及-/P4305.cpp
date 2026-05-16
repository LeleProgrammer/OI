#include <bits/stdc++.h>
using namespace std;

unordered_set<int> hs;

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        hs.clear();
        while (n--) {
            int v;
            scanf("%d",&v);
            if (hs.find(v)==hs.end()) {
                hs.insert(v);
                printf("%d ",v);
            }
        }
        printf("\n");
    }
    return 0;
}