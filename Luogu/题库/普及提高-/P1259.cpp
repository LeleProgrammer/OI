#include <bits/stdc++.h>
using namespace std;

int n;

void output_empty_right(int k) {
    for (int i=1;i<=k;++i) {
        printf("o");
    }
    for (int i=1;i<=k;++i) {
        printf("*");
    }
    printf("--");
}

void output_empty_mid(int k) {
    for (int i=1;i<=k;++i) {
        printf("o");
    }
    printf("--");
    for (int i=1;i<=k;++i) {
        printf("*");
    }
}

void output_one_o_one_star(int k) {
    for (int i=1;i<=k;++i) {
        printf("o*");
    }
}

int main() {
    scanf("%d",&n);
    output_empty_right(n);
    printf("\n");
    for (int i=1;i<=n;++i) {
        if (n-i==3) {
            output_empty_mid(n-i);
            output_one_o_one_star(i);
            printf("\n");
            printf("ooo*o**--*");
            output_one_o_one_star(i-1);
            printf("\n");
            printf("o--*o**o");
            output_one_o_one_star(i);
            printf("\n");
            printf("o*o*o*--");
            output_one_o_one_star(i);
            printf("\n");
            i=n;
        }
        output_empty_mid(n-i);
        output_one_o_one_star(i);
        printf("\n");
        if (i==n) break;
        output_empty_right(n-i);
        output_one_o_one_star(i);
        printf("\n");
    }
}