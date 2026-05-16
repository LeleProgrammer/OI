#include <bits/stdc++.h>
using namespace std;

int t;
int n;
char str[15];

int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        scanf("%s",str);
        vector<int> pos;
        for (int i=0;i<n;++i) {
            if (str[i]=='B') {
                pos.push_back(i);
            }
        }
        printf("%d\n",pos.back()-pos[0]+1);
    }
    return 0;
}