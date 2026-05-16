#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> hs[100005];

int n,q;
int op,i,j,k;

int main() {
    scanf("%d %d",&n,&q);
    while (q--) {
        scanf("%d",&op);
        if (op==1) {
            scanf("%d %d %d",&i,&j,&k);
            hs[i][j]=k;
        } else {
            scanf("%d %d",&i,&j);
            printf("%d\n",hs[i][j]);
        }
    }
    return 0;
}