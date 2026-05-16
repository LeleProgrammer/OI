#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n,m,x,y;
int ina[N],inb[N];
stack<int> a,b;
int t,now;
int ans;

bool cmp(const int& a,const int& b) {
    return a>b;
}

int main() {
    scanf("%d %d %d %d",&n,&m,&x,&y);
    for (int i=1;i<=n;++i) {
        scanf("%d",&ina[i]);
    }
    for (int i=1;i<=m;++i) {
        scanf("%d",&inb[i]);
    }
    sort(ina+1,ina+1+n,cmp);
    sort(inb+1,inb+1+m,cmp);
    for (int i=1;i<=n;++i) {
        a.push(ina[i]);
    }
    for (int i=1;i<=m;++i) {
        b.push(inb[i]);
    }
    while (true) {
        stack<int>& c=now?b:a;
        int d=now?y:x;
        while (!c.empty() && c.top()<t) c.pop();
        if (c.empty()) break;
        ans++;
        t=c.top()+d;
        now^=1;
    }
    printf("%d\n",ans/2);
    return 0;
}