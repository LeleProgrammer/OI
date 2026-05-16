#include <bits/stdc++.h>
using namespace std;

int ans=0;

void search(int count,int sum,int last_num,int n,int k) {
    if (count==k) {
        if (sum==n) {
            ++ans;
        }
    } else if (count<k) {
        for (int i=last_num;i+sum<=n;++i) {
            search(count+1,i+sum,i,n,k);
        }
    }
}

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    search(0,0,1,n,k);
    printf("%d",ans);
    return 0;
}