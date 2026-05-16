#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

int main() {
    while (true) {
        int n;
        scanf("%d",&n);
        if (!n) break;
        vec.push_back(n);
    }
    reverse(vec.begin(),vec.end());
    for (int i:vec) printf("%d ",i);
    return 0;
}