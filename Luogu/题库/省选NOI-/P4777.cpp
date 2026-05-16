#include <bits/stdc++.h>
using namespace std;

#define int __int128

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

namespace IO {
    inline void read(int &a) {
        int sym=1,num=0;
        char c=getchar();
        while (c<'0' || c>'9') {
            if (c=='-') {
                sym=-1;
            }
            c=getchar();
        }
        while (c>='0' && c<='9') {
            num=num*10+c-'0';
            c=getchar();
        }
        a=sym*num;
    }
    inline void write(int a) {
        if (a<0) {
            putchar('-');
            a*=-1;
        }
        if (a>=10) {
            write(a/10);
        }
        putchar(a%10+'0');
    }
}

using namespace IO;

const int N=100005;

int n;
int a[N],b[N];

int exgcd(int a,int b,int& x,int& y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int gcd(int a,int b) {
    if (!b) return a;
    else return gcd(b,a%b);
}

int lcm(int a,int b) {
    return a/gcd(a,b)*b;
}

int eqmod(int a,int b,int p) { // ax === b (mod p)
    int x,y;
    int d=exgcd(a,p,x,y);
    x=x*b/d;
    x=(x%p+p)%p;
    // printf("%lld*%lld+%lld*%lld=%lld\n",a,x,y,p,b);
    return x;
}

int exCRT() {
    _rep(i,2,n) {
        int x,y;
        int d=exgcd(b[1],b[i],x,y);
        x=x*(a[i]-a[1])/d;
        a[1]=b[1]*x+a[1];
        b[1]=lcm(b[1],b[i]);
        a[1]%=b[1];
    }
    // cout<<a[1]<<" "<<b[1]<<endl;
    return eqmod(1,a[1],b[1]);
}

signed main() {
    read(n);
    _rep(i,1,n) read(b[i]),read(a[i]);
    write((exCRT()%b[1]+b[1])%b[1]);
    return 0;
}