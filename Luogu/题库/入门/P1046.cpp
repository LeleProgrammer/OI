#include <bits/stdc++.h>
using namespace std;

int main() {
    int apples[10];
    for (int i=0;i<10;++i) {
        scanf("%d",apples+i);
    }
    int height;
    scanf("%d",&height);
    height+=30;
    int sum=0;
    for (int i=0;i<10;++i) {
        if (apples[i]<=height) {
            ++sum;
        }
    }
    printf("%d",sum);
    return 0;
}