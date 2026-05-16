#include <bits/stdc++.h>
using namespace std;

int x,y,p,q;

int main() {
    scanf("%d %d %d %d",&x,&y,&p,&q);
    printf("%d",min(min(min(y-q,q),x-p),p));
    return 0;
}