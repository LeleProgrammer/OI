#include <bits/stdc++.h>

#define int long long

using namespace std;

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

int x,y,z,k;

int a[1005],b[1005],c[1005];

vector<int> v;
vector<int> res;

bool cmp(int a,int b) {
    return a>b;
}

signed main() {
    read(x),read(y),read(z),read(k);
    for (int i=1;i<=x;++i) read(a[i]);
    for (int i=1;i<=y;++i) read(b[i]);
    for (int i=1;i<=z;++i) read(c[i]);
    for (int i=1;i<=x;++i) {
        for (int j=1;j<=y;++j) {
            v.push_back(a[i]+b[j]);
        }
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=0;i<min(k,(int)v.size());++i) {
        for (int j=1;j<=z;++j) {
            res.push_back(v[i]+c[j]);
        }
    }
    sort(res.begin(),res.end(),cmp);
    for (int i=0;i<k;++i) write(res[i]),putchar(10);
    return 0;
}