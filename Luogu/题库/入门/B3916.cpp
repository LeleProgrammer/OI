#include <bits/stdc++.h>

#define int long long

using namespace std;

int a,b,c,d,e,f,g,p,x1,x2,y11,y2;
int ans;

int ff(int x,int y) {
    return (a*x*x*x+b*y*y*y+c*x*x*y+d*x*y*y+e*x*y+f*x+g*y)%p;
}

signed main() {
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&g,&p,&x1,&x2,&y11,&y2);
    for (int x=x1;x<=x2;++x) {
        for (int y=y11;y<=y2;++y) {
            ans=max(ans,ff(x,y));
        }
    }
    printf("%lld",ans);
    return 0;
}