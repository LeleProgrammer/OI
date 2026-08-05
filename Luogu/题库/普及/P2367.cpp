#include <bits/stdc++.h>
using namespace std;

int scores[5000005];
int b[5000005];

int main() {
    int n,p;
    scanf("%d %d",&n,&p);
    scanf("%d",scores);
    b[0]=scores[0];
    for (int i=1;i<n;++i) {
        scanf("%d",scores+i);
        b[i]=scores[i]-scores[i-1];
    }
    int x,y,z;
    for (int i=0;i<p;++i) {
        scanf("%d %d %d",&x,&y,&z);
        b[x-1]+=z;
        b[y]-=z;
    }
    int minimum=0x7fffffff;
    int score=0;
    for (int i=0;i<n;++i) {
        score+=b[i];
        if (score<minimum) {
            minimum=score;
        }
    }
    printf("%d",minimum);
    return 0;
}