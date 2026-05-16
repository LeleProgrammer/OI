#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;

int T,n,m,x,y,ans;
int a[N];

// int r_l[N],r_r[N],r_s[N],rtot,rpos[N],r_2[N];
// int l_l[N],l_r[N],l_s[N],ltot,lpos[N],l_2[N];

int r[N];
int l[N];

void init() {
    for (int i=1;i<=n-1;++i) {
        if (abs(a[i]-a[i+1])<abs(a[i]-a[i-1]) || i==1) {
            r[i+1]=r[i]+1;
        } else {
            r[i+1]=r[i]+abs(a[i]-a[i+1]);
        }
    }
    for (int i=n;i>=2;--i) {
        if (abs(a[i]-a[i-1])<abs(a[i]-a[i+1]) || i==n) {
            l[i-1]=l[i]+1;
        } else {
            l[i-1]=l[i]+abs(a[i]-a[i-1]);
        }
    }
    // bool block=true; rtot=1; r_l[1]=1;
    // for (int i=1;i<=n-1;++i) {
    //     if (i==1 || abs(a[i]-a[i+1])<abs(a[i]-a[i-1])) {
    //         if (!block) {
    //             block=true;
    //             r_l[++rtot]=i;
    //         }
    //         rpos[i]=rtot;
    //     } else {
    //         if (block) {
    //             block=false;
    //             r_r[rtot]=i;
    //             r_2[rtot]=r_2[rtot-1]+(r_r[rtot]-r_l[rtot]);
    //             r_s[rtot]=r_s[rtot-1];
    //         }
    //         r_s[rtot]+=abs(a[i]-a[i+1]);
    //         rpos[i]=rtot;
    //     }
    // }
    // rpos[n]=rtot;
    // if (block) r_r[rtot]=n,r_2[rtot]=r_2[rtot-1]+(r_r[rtot]-r_l[rtot]);
    // // for (int i=1;i<=rtot;++i) {
    // //     printf("test: %lld %lld %lld\n",r_l[i],r_r[i],r_s[i]);
    // // }
    // block=true; ltot=1; l_r[1]=n;
    // for (int i=n;i>=2;--i) {
    //     if (i==n || abs(a[i]-a[i+1])>abs(a[i]-a[i-1])) {
    //         if (!block) {
    //             block=true;
    //             l_r[++ltot]=i;
    //         }
    //         lpos[i]=ltot;
    //     } else {
    //         if (block) {
    //             cout<<i<<endl;
    //             block=false;
    //             l_l[ltot]=i;
    //             l_2[ltot]=l_2[ltot-1]+(l_r[ltot]-l_l[ltot]);
    //             l_s[ltot]=l_s[ltot-1];
    //         }
    //         l_s[ltot]+=abs(a[i]-a[i-1]);
    //         lpos[i]=ltot;
    //     }
    // }
    // lpos[1]=ltot;
    // if (block) l_l[ltot]=1,l_2[ltot]=l_2[ltot-1]+(l_r[ltot]-l_l[ltot]);
    // // for (int i=1;i<=ltot;++i) {
    // //     printf("test: %lld %lld %lld\n",l_l[i],l_r[i],l_s[i]);
    // // }
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
        init();
        scanf("%lld",&m);
        while (m--) {
            scanf("%lld %lld",&x,&y);
            // ans=0;
            if (x<y) {
                printf("%lld\n",r[y]-r[x]);
            } else {
                printf("%lld\n",l[y]-l[x]);
            }
            // if (x<y) {
            //     if (x>r_r[rpos[x]]) {
            //         ans+=a[r_l[rpos[x]+1]]-a[x];
            //         x=r_l[rpos[x]+1];
            //     }
            //     if (y>r_r[rpos[y]]) {
            //         ans+=a[y]-a[r_r[rpos[y]]];
            //         y=r_r[rpos[y]];
            //     }
            // }
        }
    }
}

/*
--- [ ---bbbb-----bbbbb-----bbbb----bbb--- ] ---
--- [ bbbb-----bbbb-----bbbb----bbbb ] ---
*/

/*
0 8 12 15 20
- - -  >
    <  -  -

1 2 4 7 11 12 14 17
- >     -  > 
< - - - <  -  -  -

1
8
1 2 4 7 11 12 14 17

bbb [ bbbb ] bbb
bbb [ bb-- ] --- bbb
bbb [ bb-----bbbbb ] bbbb
--- [ --bb ] bbb
--- [ -bb- ] ---
--- [ ---bbbb-----bbbbb-----bbbb----bbb--- ] ---
*/