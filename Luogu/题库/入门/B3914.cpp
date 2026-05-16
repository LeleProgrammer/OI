#include <bits/stdc++.h>
using namespace std;

int a,b,c;
int minn=0x3f3f3f3f;
int z,yz;

int main() {
    scanf("%d %d %d",&a,&b,&c);
    if (abs(a+b-c)<minn) {
        minn=abs(a+b-c);
        z=max(a+b,c); yz=min(a+b,c);
    }
    if (abs(a+c-b)<minn) {
        minn=abs(a+c-b);
        z=max(a+c,b); yz=min(a+c,b);
    }
    if (abs(b+c-a)<minn) {
        minn=abs(b+c-a);
        z=max(b+c,a); yz=min(b+c,a);
    }
    printf("%d %d",z,yz);
    return 0;
}