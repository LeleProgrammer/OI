#include <bits/stdc++.h>
using namespace std;

const int N=7;
const int inf=1e9;
const double pi=3.1415926535897932384626433832795028841971693993751058;

int n;
double a,b,c,d;
double x[N],y[N];
int per[N];
double rs[N];
double ans;

double dis(int a,int b,int c,int d) {
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

int main() {
    scanf("%d",&n);
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    for (int i=1;i<=n;++i) {
        scanf("%lf %lf",&x[i],&y[i]);
    }
    for (int i=1;i<=n;++i) {
        per[i]=i;
    }
    do {
        memset(rs,0,sizeof(rs));
        for (int i=1;i<=n;++i) {
            double r=inf;
            for (int j=1;j<i;++j) {
                double k=dis(x[per[i]],y[per[i]],x[per[j]],y[per[j]]);
                k-=rs[per[j]];
                if (k<0) k=0;
                r=min(r,k);
            }
            r=min(r,abs(x[per[i]]-a));
            r=min(r,abs(x[per[i]]-c));
            r=min(r,abs(y[per[i]]-b));
            r=min(r,abs(y[per[i]]-d));
            rs[per[i]]=r;
        }
        double s=0;
        for (int i=1;i<=n;++i) {
            s+=pi*rs[i]*rs[i];
        }
        ans=max(ans,s);
    } while (next_permutation(per+1,per+1+n));
    printf("%d",(int)round(abs(a-c)*abs(b-d)-ans));
    return 0;
}