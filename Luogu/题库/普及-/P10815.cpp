#include <bits/stdc++.h>

#define int long long

using namespace std;

namespace IO {
    inline void read(int &a) {
        int sym=1,num=0;
        char c=getchar_unlocked();
        while (c<'0' || c>'9') {
            if (c=='-') {
                sym=-1;
        }
        c=getchar_unlocked();
        }
        while (c>='0' && c<='9') {
            num=num*10+c-'0';
            c=getchar_unlocked();
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

int n;

signed main() {
    read(n);
    int ans=0;
    for (int i=1;i<=n;++i) {
        int v;
        read(v);
        ans+=v;
    }
    printf("%lld",ans);
    return 0;
}