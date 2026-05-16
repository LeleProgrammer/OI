#include <bits/stdc++.h>
using namespace std;

const int N=105;

int n;
int x[N],y[N];

int get_dis(int x1,int y1,int x2,int y2) {
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&x[i],&y[i]);
    }
    for (int i=1;i<=n;++i) {
        int minn=-1000000000;
        int ans=0;
        for (int j=1;j<=n;++j) {
            if (i==j) continue;
            if (get_dis(x[i],y[i],x[j],y[j])>minn) {
                minn=get_dis(x[i],y[i],x[j],y[j]);
                ans=j;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}