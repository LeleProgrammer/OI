#include <bits/stdc++.h>
using namespace std;

int pre[5005];
int n,k,val;
double maxx=-1;

int main() {
    scanf("%d %d",&n,&k);
    pre[0]=0;
    for (int i=1;i<=n;++i) {
        scanf("%d",&val);
        pre[i]=pre[i-1]+val;
    }
    for (int len=k;len<=n;++len) {
        for (int l=1,r=l+len-1;r<=n;++l,++r) {
            maxx=max(maxx,(double)(pre[r]-pre[l-1])/(double)(len));
        }
    }
    printf("%.10lf",maxx);
    return 0;
}