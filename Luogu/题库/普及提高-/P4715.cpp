#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int ablt[130];
    int winners[130];
    int next_winners[130];
    for (int i=1;i<=pow(2,n);++i) {
        scanf("%d",&ablt[i]);
        next_winners[i]=i;
    }
    while (true) {
        swap(winners,next_winners);
        memset(next_winners,0,sizeof(next_winners));
        int c=1;
        for (int i=1;i<=pow(2,n)-1;i+=2) {
            if (n==1) {
                if (ablt[winners[i]]>ablt[winners[i+1]]) {
                    cout<<winners[i+1];
                } else {
                    cout<<winners[i];
                }
                return 0;
            }
            if (ablt[winners[i]]>ablt[winners[i+1]]) {
                next_winners[c]=winners[i];
            } else {
                next_winners[c]=winners[i+1];
            }
            ++c;
        }
        --n;
    }
}