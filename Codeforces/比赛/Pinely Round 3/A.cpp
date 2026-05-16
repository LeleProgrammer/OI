#include <bits/stdc++.h>
using namespace std;

int t,n,x,y;
bool a,b,c,d;

int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        a=b=c=d=false;
        while (n--) {
            scanf("%d %d",&x,&y);
            if (x<0) a=true;
            else if (x>0) b=true;
            if (y<0) c=true;
            else if (y>0) d=true;
        }
        if (a+b+c+d<=3) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}