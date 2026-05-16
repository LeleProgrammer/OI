#include <bits/stdc++.h>
using namespace std;

int n,val,tot,a,b;
priority_queue< int,vector<int>,greater<int> > q;

int main() {
    while (true) {
        scanf("%d",&n);
        if (n==0) break;
        for (int i=1;i<=n;++i) {
            scanf("%d",&val);
            q.push(val);
        }
        tot=0;
        while (q.size()>=2) {
            a=q.top(); q.pop();
            b=q.top(); q.pop();
            tot=tot+a+b;
            q.push(a+b);
        }
        q.pop();
        printf("%d\n",tot);
    }
    return 0;
}