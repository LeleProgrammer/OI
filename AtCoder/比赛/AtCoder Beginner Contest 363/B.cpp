#include <bits/stdc++.h>
using namespace std;

const int N=105;

int n;
int arr[N];
int t,p;

int main() {
    scanf("%d %d %d",&n,&t,&p);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    int k=-1;
    while (true) {
        k++;
        int cnt=0;
        for (int i=1;i<=n;++i) {
            if (arr[i]>=t) cnt++;
            arr[i]++;
        }
        if (cnt>=p) break;
    }
    printf("%d",k);
    return 0;
}