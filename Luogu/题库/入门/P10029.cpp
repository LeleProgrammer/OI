#include <bits/stdc++.h>
using namespace std;

int t,n,m,p;
int alice,bob;

int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&n,&m,&p);
        alice=bob=0;
        while (m && m%p) bob++,m-=m%p;
        while (n && n%p) alice++,n-=n%p;
        if (m && n) printf("Lasting Battle\n");
        else if (m && !n) printf("Bob\n");
        else if (n && !m) printf("Alice\n");
        else if (alice<=bob) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}