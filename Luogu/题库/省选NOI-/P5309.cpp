#include <bits/stdc++.h>

#define rint register int

using namespace std;

typedef long long LL;

namespace IO {
    template<class T>
    inline void read(T &a) {
        rint sym=1,num=0;
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

using IO::read;

const int N=200005;
const int M=455*5;
const int mod=1e9+7;

int n,m;
LL arr[N];
int len,avg;
LL sum[M];
LL pre[M][M];

inline int get(int x) {
    return x/len;
}

inline int getl(int x) {
    return x*len;
}

inline int getr(int x) {
    return getl(x+1)-1;
}

inline void modify(int x,int y,LL z) {
    if (x>=avg) {
        for (rint i=y;i<=n;i+=x) {
            sum[get(i)]+=z;
            arr[i]+=z;
        }
    } else {
        for (rint i=y;i<=x;++i) {
            pre[x][i]+=z;
        }
    }
}

inline LL query(int l,int r) {
    LL ans=0;
    if (get(l)==get(r)) {
        for (rint i=l;i<=r;++i) {
            ans+=1ll*arr[i];
        }
    } else {
        for (rint i=get(l)+1;i<=get(r)-1;++i) {
            ans+=1ll*sum[i];
        }
        for (rint i=l;i<=getr(get(l));++i) {
            ans+=1ll*arr[i];
        }
        for (rint i=getl(get(r));i<=r;++i) {
            ans+=1ll*arr[i];
        }
    }
    for (rint i=1;i<=avg;++i) {
        if (!pre[i][i] && !pre[i][r%i] && !pre[i][(l-1)%i]) continue;
        ans+=1ll*(r/i-(l-1)/i)*pre[i][i]+1ll*pre[i][r%i]-1ll*pre[i][(l-1)%i];
    }
    return ans;
}

signed main() {
    read(n); read(m);
    // len=sqrt(n)/4+1;
    // avg=sqrt(n)/4+1;
    len=sqrt(n);
    avg=sqrt(n)/4+1;
    for (rint i=1;i<=n;++i) {
        read(arr[i]);
        sum[get(i)]+=arr[i];
    }
    while (m--) {
        rint op;
        read(op);
        if (op==1) {
            rint x,y,z;
            read(x); read(y); read(z);
            modify(x,y,z);
        } else {
            rint l,r;
            read(l); read(r);
            LL ans=query(l,r);
            ans=(ans+mod)%mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}