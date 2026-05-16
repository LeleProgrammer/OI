#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d",&n);
    bool ok=false;
    string last="none";
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        if (s=="sweet" && last=="sweet" && i!=n) {
            printf("No");
            return 0;
        }
        last=s;
    }
    printf("Yes");
    return 0;
}