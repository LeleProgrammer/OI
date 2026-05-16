#include <bits/stdc++.h>
using namespace std;

const int N=10005;

int l,m;
bool flag[N];

int main() {
    scanf("%d %d",&l,&m); l++;
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        for (int i=a;i<=b;++i) {
            if (!flag[i]) {
                flag[i]=true;
                l--;
            }
        }
    }
    printf("%d",l);
    return 0;
}