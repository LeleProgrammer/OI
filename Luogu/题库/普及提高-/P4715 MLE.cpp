#include <bits/stdc++.h>
using namespace std;

int n;
int ability[130];

int winner(int l,int r) {
    if (l+1==r) {
        return ability[l]>ability[r]?l:r;
    } else {
        int mid_left=(l+r)/2;
        int mid_right=mid_left+1;
        int left_winner=winner(l,mid_left);
        int right_winner=winner(mid_right,r);
        return ability[left_winner]>ability[right_winner]?left_winner:right_winner;
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=pow(2,n);++i) {
        scanf("%d",ability+i);
    }
    int l=1;
    int r=pow(2,n);
    int mid_left=(l+r)/2;
    int mid_right=mid_left+1;
    int left_winner=winner(l,mid_left);
    int right_winner=winner(mid_right,r);
    if (ability[left_winner]>ability[right_winner]) {
        printf("%d",right_winner);
    } else {
        printf("%d",left_winner);
    }
    return 0;
}