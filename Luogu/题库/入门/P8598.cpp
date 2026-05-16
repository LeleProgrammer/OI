#include <bits/stdc++.h>
using namespace std;

int m,n;
bool bucket[100000];

int main() {
    scanf("%d",&n);
    int input;
    memset(bucket,false,sizeof(bucket));
    while (cin>>input) {
        if (bucket[input]==true) {
            n=input;
        }
        bucket[input]=true;
    }
    bool start=false;
    for (int i=0;i<100000;++i) {
        if (start==false) {
            if (bucket[i]) {
                start=true;
            }
            continue;
        }
        if (!bucket[i]) {
            if (!bucket[i+1]) {
                break;
            } else {
                m=i;
            }
        }
    }
    printf("%d %d",m,n);
    return 0;
}